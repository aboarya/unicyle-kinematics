#pragma once

#include "motor.h"
#include "interfaces/actuator.h"
#include "interfaces/state.h"

namespace tareeq {
  namespace control {

    class UniCycleDriver : public Actuator {

      Motor right_motor_;
      Motor left_motor_;

      bool is_driving_forward_ = false;
      
    public:
      UniCycleDriver(Motor& right_motor, Motor& left_motor);
  
      virtual bool Apply(const State& error);

      bool Start();
      bool Stop();
      bool DriveForward();
      bool DriveBackward();
      
      const bool IsDrivnigForward();
    };

  } // end namespace control
} // end namespace tareeq
