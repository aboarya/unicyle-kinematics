#ifndef RPI3_MOTOR_
#define RPI3_MOTOR_

#include "tareeq/gpio/gpio.h"
#include "tareeq/gpio/pwm.h"

class Motor
{
 public:
  Motor(uint8_t speed_pin, uint8_t control_pin_a, uint8_t control_pin_b);
  ~Motor();
  void Run();
  void stop();
  void SetSpeed(double duty_cycle);
  void sleep(int millis);
  void IncreaseSpeed();
  void DecreaseSpeed();
  
 private:
  double speed_;
  double duty_cycle;
  Pwm speed_pin_;
  Gpio control_pin_a_;
  Gpio control_pin_b_;
  
};


#endif // RPI3_MOTOR_
