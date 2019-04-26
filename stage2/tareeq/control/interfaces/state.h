#pragma once

#include <string>
#include <unordered_map>

namespace tareeq {
  namespace control {

    class State {

    public:

      virtual ~State() = default;

      virtual void Update(const std::unordered_map<std::string, double> values) = 0;
      //virtual void Update(const std::unordered_map<std::string, Sensor>& sensors) = 0;
      virtual void Update() = 0;
      virtual const std::unordered_map<std::string, double>& GetRep() const = 0;
      virtual const std::unordered_map<std::string, double>& operator- (const State& state) = 0;

    };

  } // end namespace control
} // end namespace tareeq
