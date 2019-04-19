#pragma once

#include <unordered_map>
#include "tareeq/control/interfaces/state.h"

namespace tareeq {
  namespace control {
    
    class Actuator {

    public:
      virtual ~Actuator() = default;

      virtual bool Apply(const State& error) = 0;
    };

  } // end namespace control
} // end namespace tareeq
