#pragma once

#include <string>
#include <unordered_map>
#include "tareeq/control/interfaces/sensor.h"

namespace tareeq {
  namespace control {

    class State {

    public:

      virtual ~State() = default;

      virtual void Update(const std::unordered_map<std::string, double> values) = 0;
      virtual void Update(const std::unordered_map<std::string, Sensor>& sensors) = 0;

      virtual std::unordered_map<std::string, double> const operator- (const State& state) = 0;

    };

  } // end namespace control
} // end namespace tareeq
