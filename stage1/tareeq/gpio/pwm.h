#ifndef PWMPIN_
#define PWMPIN_

#include <iostream>

#include "gpio.h"

class Pwm : public Gpio
{
  
 public:
  Pwm() = default;
  ~Pwm() = default;
  
  Pwm(const int& line_number);

  void SetFrequency(double freq);

  void Pulse();

  void SetDutyCycle(double duty_cycle);
  const double &GetDutyCycle();

  inline void CalculateDuration();
 private:

  const double max_cycle_ = 100.;
  double frequency_;
  double base_time_;
  double slice_time_;
  double duty_cycle_;

  std::chrono::duration<double> on_duration_;
  std::chrono::duration<double> off_duration_;
  
};

#endif // PWMPIN_
