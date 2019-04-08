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
  this->frequency_  = 50.0;
  this->duty_cycle_ = 5.0;
  this->basetime_   = 1.0;
  this->slicetime_  = 0.01;
  
}

void Pwm::calculate_times(void)
{
  long long usec;
    
  usec = (long long) (this->duty_cycle_ * this->slicetime_ * (double) 1000.0);
  this->req_on_.tv_sec = (int) (usec / 1000000LL);
  usec -= (long long) this->req_on_.tv_sec * 1000000LL;
  this->req_on_.tv_sec = (long) usec * 1000L;
  
  usec = (long long) ((100.0 - this->duty_cycle_) * this->slicetime_ * 1000.0);
  this->req_off_.tv_sec = (int) (usec / 1000000LL);
  usec -= (long long) this->req_off_.tv_sec * 1000000LL;
  this->req_off_.tv_sec = (long) usec * 1000L;
    
}

void Pwm::set_frequency(double freq)
{
  this->basetime_ = 1000.0 / freq;
  this->slicetime_ = this->basetime_ / 100.0;
  this->calculate_times();
}

void Pwm::set_duty_cycle(double duty_cycle)
{
  this->duty_cycle_ = duty_cycle;
  if (duty_cycle < 0.0)
    this->duty_cycle_ = 0.0;

  if (duty_cycle_ > 100.0)
    this->duty_cycle_ = 100.0;

  this->calculate_times();
  
}

void Pwm::pulse()
{
  while (this->is_running_)
    {
      //std::cout << " frequency is " << this->frequency_;
 
      if (this->duty_cycle_ > 0.0)
	{
	  this->output(1);
	  this->full_sleep(this->req_on_);
	}
      
      if (this->duty_cycle_ < 100.0)
	{
	  this->output(0);
	  this->full_sleep(this->req_off_);
	}
    }

  //end of thread
  this->output(0); // turn off
}

void Pwm::full_sleep(struct timespec &req)
{
  struct timespec rem = {0};

  if (nanosleep(&req, &rem) == -1)
    this->full_sleep(rem);
}

Pwm::~Pwm()
{
  this->is_running_ = false;
  
};
