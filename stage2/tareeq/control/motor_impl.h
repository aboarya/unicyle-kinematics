#include <iostream>

#include "motor.h"

namespace tareeq {
  namespace control {
    template<class T, class T1>
      class MotorImpl : public Motor
    {
      T* speed_pin_;
      T1* control_pin_a_;
      T1* control_pin_b_;
      
    public:

      
      ~MotorImpl()
	{
	  this->Stop();
	};

      
      MotorImpl(T& speed_pin, T1& c_pin_a, T1& c_pin_b)
      {
	speed_pin_ = &speed_pin;
	control_pin_a_ = &c_pin_a;
	control_pin_b_ = &c_pin_b;
      };
      
      virtual void Run()
      {
	this->control_pin_a_->On();
	this->control_pin_b_->Off();
	this->speed_pin_->Start();
      };

      virtual void Stop()
      {
	this->speed_pin_->Stop();
	this->control_pin_a_->Off();
	this->control_pin_b_->Off();
      };

      virtual void ApplyRotationRate(double rotation_rate)
      {
	std::cout << "-- setting speed " << rotation_rate << std::endl;
	this->speed_pin_->SetSpeed(rotation_rate);
      };
      
    };
  } // namespace gpio
} // namespace tareeq
