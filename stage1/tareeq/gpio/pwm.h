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


  double duty_cycle_;
  double frequency_;
  double basetime_;
  double slicetime_;
  struct timespec req_on_, req_off_;

  void full_sleep(struct timespec &req);
  
};

#endif // PWMPIN_
