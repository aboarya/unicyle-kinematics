#pragma once

#include "tareeq/control/interfaces/state.h"

namespace tareeq {
  namespace control {
    class PID {

    public:
      virtual ~PID() = default;

      virtual State const CalculateError(const State& target_state, const State& current_state) = 0;

      virtual void SetProportionalGain(const double& kp) = 0;
      virtual void SetIntegralGain(const double& ki) = 0;
      virtual void SetDifferentialGain(const double& kd) = 0;

    };

  } // end namespace control
} // end namespace tareeq
