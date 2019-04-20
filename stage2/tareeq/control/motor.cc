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
      control_b_(std::move(control_b)) {};

    /**
     */
    bool Motor::SpinForward()
    {
      this->control_a_->On();
      this->control_b_->Off();
      
      this->speed_pin_->Start();
      
      return true; // TO-DO : actual success validation
    }

    /**
     */
    bool Motor::SpinBackward()
    {
      this->control_a_->Off();
      this->control_b_->On();
      
      this->speed_pin_->Start();
      
      return true; // TO-DO : actual success validation
    }
    
    /**
     */
    bool Motor::Stop()
    {
      this->speed_pin_->Stop();
      this->control_a_->Off();
      this->control_b_->Off();

      return true; // TO-DO : actual success validation
    };

    
    
  } // end namespace control  
} // end namespace tareeq
