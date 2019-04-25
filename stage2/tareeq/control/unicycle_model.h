#pragma once

#include <string>
#include <unordered_map>

#include "tareeq/control/interfaces/state.h"

namespace tareeq {
  namespace control {
    
    class UnicycleModel : public State {

    public:
      UnicycleModel(std::unordered_map<std::string, double> values);

      virtual void Update(const std::unordered_map<std::string, double>& values);
      virtual void Update(const std::unordered_map<std::string, Sensor>& sensors);
      virtual const std::unordered_map<std::string, double>& GetRep();
      virtual const std::unordered_map<std::string, double> operator- (const State& state);
  
    private:
      std::unordered_map<std::string, double> values_;

    };

  } // end namespace control
} // end namespace tareeq
