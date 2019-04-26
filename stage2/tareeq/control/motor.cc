#include <memory>

#include "motor.h"

#include "tareeq/gpio/pwm.h"
#include "tareeq/gpio/output.h"


namespace tareeq {
  namespace control {

    using tareeq::gpio::Pwm;
    using tareeq::gpio::Output;

    /**
     */
    Motor::Motor(std::unique_ptr<Pwm>&& speed_pin, std::unique_ptr<Output>&& control_a, std::unique_ptr<Output>&& control_b) :
      speed_pin_(std::move(speed_pin)),
      control_a_(std::move(control_a)),
      control_b_(std::move(control_b)){};
    
    /**
    */
    bool Motor::Start()
    {
      this->control_a_->On();
      this->control_b_->Off();
      is_started_ = true; // TO-DO : set this from gpio success
      return is_started_;
    }

    /**
    */
    bool Motor::Stop()
    {
      this->speed_pin_->Stop();
      this->control_a_->Off();
      this->control_b_->On();

      is_started_ = false;
      return !is_started_; // TO-DO : actual success validation
    };

    
    /**
     */
    bool Motor::SpinForward()
    {
      if (!is_started_)
	{
	  // TO-DO: log error or alert
	  return false;
	}
      if (!is_spin_forward_)
	{
	  this->control_a_->Off();
	  this->control_b_->On();
	  
	  is_spin_forward_ = true;
	}
      this->speed_pin_->Start();

      return is_spin_forward_;
    }


    /**
     */
    bool Motor::SetSpeed(const double w)
    {
      if (!is_started_)
	{
	  // TO-DO: log error or alert
	  return false;
	}
      this->speed_pin_->SetSpeed(w);

      return is_started_;
    }

    /**
    */
    bool Motor::SpinBackward()
    {
      if (!is_started_)
	{
	  // TO-DO: log error or alert
	  return false;
	}
      if (is_spin_forward_)
	{
	  this->control_a_->Off();
	  this->control_b_->On();
	  
	  is_spin_forward_ = false;
	}
      
      this->speed_pin_->Start();

      return !is_spin_forward_; 
    }
    
    
    
    
  } // end namespace control  
} // end namespace tareeq
