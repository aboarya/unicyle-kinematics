#ifndef PWMPIN_
#define PWMPIN_

#include <iostream>

#include "gpio.h"

class Pwm : public Gpio
{
  
 public:
  Pwm(){};
  Pwm(const uint32_t &line_number);
  ~Pwm();
  
  void configure(void);
  
  void calculate_times(void);

  void set_frequency(double freq);

  void pulse();

  void set_duty_cycle(double duty_cycle);

  bool   is_running_;
 private:


  const double max_cycle_ = 100.;
  double frequency_;
  double base_time_;
  double slice_time_;
  double duty_cycle_;

  void sleep();
  
};

#endif // PWMPIN_
