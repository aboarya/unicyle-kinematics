#include <iostream>
#include <chrono>
#include <thread>

#include "motor.h"

const std::string output_("output");

Motor::Motor(uint8_t speed_pin, uint8_t control_pin_a, uint8_t control_pin_b) :
  speed_pin_(speed_pin),
  control_pin_a_(control_pin_a, output_),
  control_pin_b_(control_pin_b, output_)
{
  this->speed_ = 50.;  // in Khz
  this->duty_cycle = 5.; // in percent
}

void Motor::Run(void)
{
  this->control_pin_a_.output(1);
  this->control_pin_b_.output(0);
  std::thread t(&Pwm::pulse, this->speed_pin_);
  t.detach();
}

void Motor::sleep(int millis)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(millis));
};

void Motor::stop(void)
{
  this->speed_pin_.is_running_ = false;
}

Motor::~Motor()
{
  this->speed_pin_.is_running_  = false;
  this->speed_pin_.output(0);
  this->control_pin_a_.output(0);
  this->control_pin_b_.output(0);
}

void Motor::SetSpeed(double duty_cyle)
{
  this->speed_pin_.set_duty_cycle(duty_cycle);
}
