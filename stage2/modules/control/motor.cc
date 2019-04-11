#include <iostream>
#include <chrono>
#include <thread>

#include "motor.h"

const std::string output_("output");

Motor::Motor(uint8_t speed_pin, uint8_t control_pin_a, uint8_t control_pin_b) :
  speed_pin_(speed_pin),
  control_pin_a_(control_pin_a, output_),
  control_pin_b_(control_pin_b, output_)
{}

void Motor::Run(void)
{
  this->control_pin_a_.Output(1);
  this->control_pin_b_.Output(0);
  std::thread t(&Pwm::Pulse, std::ref(this->speed_pin_));
  t.detach();
}

void Motor::Stop(void)
{
  this->speed_pin_.Stop();
}

Motor::~Motor()
{
  this->speed_pin_.Stop();
  this->speed_pin_.Output(0);
  this->control_pin_a_.Output(0);
  this->control_pin_b_.Output(0);
}

void Motor::SetSpeed(double duty_cycle)
{
  std::cout << "-- setting speed " << duty_cycle << std::endl;
  this->speed_pin_.SetDutyCycle(duty_cycle);
}
