#pragma once

#include <string>
#include <memory>
#include <unordered_map>

#include "tareeq/control/interfaces/state.h"
#include "tareeq/control/interfaces/sensor.h"

namespace tareeq {
  namespace control {
    
    class UnicycleModel : public State {

      // private fields;
      std::unordered_map<std::string, std::unique_ptr<Sensor>> sensors_;
      
    public:
      
      //UnicycleModel() = default;
      
      UnicycleModel(std::unordered_map<std::string, std::unique_ptr<Sensor>&&> sensors);

      //virtual void Update(const std::unordered_map<std::string, double>& values);
      //virtual void Update(const std::unordered_map<std::string, Sensor>& sensors);
      virtual void Update();
      virtual const std::unordered_map<std::string, double>& GetRep() const;
      virtual const std::unordered_map<std::string, double>& operator- (const State& state);
  
    private:
      std::unordered_map<std::string, double> values_;

    };

  } // end namespace control
} // end namespace tareeq
