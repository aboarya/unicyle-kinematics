#include "pwm.h"
#include <time.h>

const std::string output_("output");

Pwm::Pwm(const uint32_t& pin_number) : Gpio(pin_number, output_)
{
  this->configure();
  this->calculate_times();
  this->is_running_ = true;
}

void Pwm::configure(void)
{
  this->frequency_  = 100.0;
  this->duty_cycle_ = 25.;
  this->base_time_ = 1.0 / this->frequency_;
  this->slice_time_ = this->base_time_ / this->max_cycle_;
  
}

void Pwm::calculate_times(void)
{
  //  long long usec;
    
  // usec = (long long) (this->duty_cycle_ * this->slicetime_ * (double) 1000.0);
  // this->req_on_.tv_sec = (int) (usec / 1000000LL);
  // usec -= (long long) this->req_on_.tv_sec * 1000000LL;
  // this->req_on_.tv_sec = (long) usec * 1000L;
  
  // usec = (long long) ((100.0 - this->duty_cycle_) * this->slicetime_ * 1000.0);
  // this->req_off_.tv_sec = (int) (usec / 1000000LL);
  // usec -= (long long) this->req_off_.tv_sec * 1000000LL;
  // this->req_off_.tv_sec = (long) usec * 1000L;
    
}

void Pwm::set_frequency(double freq)
{
  this->base_time_ = 1.0 / freq;
  this->slice_time_ = this->base_time_ / this->max_cycle_;

}

void Pwm::set_duty_cycle(double duty_cycle)
{

  this->duty_cycle_ = duty_cycle;
  if (duty_cycle < 0.0)
    this->duty_cycle_ = 0.0;

  if (duty_cycle_ > 100.0)
    this->duty_cycle_ = 100.0;

  
}

void Pwm::pulse()
{
  while (this->is_running_)
    {
      //std::cout << " frequency is " << this->frequency_;
 
      if (this->duty_cycle_ >= 0.0)
	{
	  this->output(1);
	  std::this_thread::sleep_for(std::chrono::duration<double>(this->duty_cycle_ * this->slice_time_));
	}
      
      if (this->duty_cycle_ <= this->max_cycle_)
	{
	  this->output(0);
	  std::this_thread::sleep_for(std::chrono::duration<double>((this->max_cycle_ - this->duty_cycle_) * this->slice_time_));
	}
    }

  //end of thread
  this->output(0); // turn off
}


Pwm::~Pwm()
{
  this->is_running_ = false;
  
};
