#ifndef INPUTGPIO_
#define INPUTGPIO_

#include "gpio.h"

const std::string direction("input");

class Input : public Gpio
{
 public:
  Input(){};
 Input(const uint32_t &line_number);
  ~Input(){};

  void wait_for_edge();
  const long long get_total_count();
  
 private:
  long long total_count_ = 0;
  gpiod::line_event event_;
};

#endif // INPUTGPIO_
