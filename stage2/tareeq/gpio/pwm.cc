#include "pwm.h"
#include <time.h>

const std::string output_("output");

Pwm::Pwm(const int& pin_number) : Gpio(pin_number, output_)
{
  // some basic default values which will be
  // overriden by the PID controller
  this->frequency_  = 100.0;
  this->duty_cycle_ = 10.;
  this->base_time_ = 1.0 / this->frequency_;
  this->slice_time_ = this->base_time_ / this->max_cycle_;
  this->CalculateDuration();
  
  // activate the robot
  this->is_running_ = true;
}

void Pwm::SetFrequency(double freq)
{
  this->base_time_ = 1.0 / freq;
  this->slice_time_ = this->base_time_ / this->max_cycle_;
  this->CalculateDuration();
}

inline void Pwm::CalculateDuration()
{
  on_duration_ = std::chrono::duration<double>(this->duty_cycle_ * this->slice_time_);
  off_duration_ = std::chrono::duration<double>((this->max_cycle_ - this->duty_cycle_) * this->slice_time_);
}

const double &Pwm::GetDutyCycle()
{
  return this->duty_cycle_;
}

void Pwm::SetDutyCycle(double duty_cycle)
{

  this->duty_cycle_ = duty_cycle;

  // ensure duty cycle is a percentage
  if (duty_cycle < 0.0)
    this->duty_cycle_ = 0.0;

  if (duty_cycle_ > 100.0)
    this->duty_cycle_ = 100.0;

  this->CalculateDuration();
}

void Pwm::Pulse()
{
  while (this->IsRunning())
    {

      if (this->duty_cycle_ >= 0.0)
	{
	  this->Output(1);
	  std::this_thread::sleep_for(on_duration_);
	}
      
      if (this->duty_cycle_ <= this->max_cycle_)
	{
	  this->Output(0);
	  std::this_thread::sleep_for(off_duration_);
	}
    }

  //end of thread
  this->Output(0); // turn off
}
