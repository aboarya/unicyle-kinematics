#pragma once

#include "motor.h"
#include "interfaces/actuator.h"

namespace tareeq {
  namespace control {

class UniCycleDriver : public Actuator {

 public:
  UniCycleDriver(Motor& right_motor, Motor& left_motor);
  
  virtual bool Apply(const State& error) {
    
  };

  inline bool Start();
  inline bool Stop();
  inline bool DriveForward();
  inline bool DriveBackward();

  inline const bool IsDrivnigForward();

 private:
  bool is_driving_forward_;
  Motor right_motor_;
  Motor left_motor_;
  
};

  } // end namespace control
} // end namespace tareeq
