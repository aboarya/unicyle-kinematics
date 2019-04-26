#pragma once

#include <string>
#include <unordered_map>

#include "tareeq/control/interfaces/state.h"
#include "tareeq/control/interfaces/sensor.h"

namespace tareeq {
  namespace control {
    
    class UnicycleModel : public State {

      // private fields;
      const std::unordered_map<std::string, Sensor>& sensors_;
      
    public:
      UnicycleModel(const std::unordered_map<std::string, Sensor>& sensors);

      virtual void Update(const std::unordered_map<std::string, double>& values);
      //virtual void Update(const std::unordered_map<std::string, Sensor>& sensors);
      virtual void Update();
      virtual const std::unordered_map<std::string, double>& GetRep() const;
      virtual const std::unordered_map<std::string, double>& operator- (const State& state);
  
    private:
      std::unordered_map<std::string, double> values_;

    };

  } // end namespace control
} // end namespace tareeq
