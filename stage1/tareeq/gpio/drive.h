#ifndef RPI3B_DRIVE_
#define RPI3B_DRIVE_

#include "pwm.h"

class Driver {
 public:
  Driver();

  void drive_forward();
  void drive_backward();

 private:
  Pwm wheel_r(12, 6, 13);
  //Pwm wheel_l();
};

#endif // RPI3B_DRIVE_
