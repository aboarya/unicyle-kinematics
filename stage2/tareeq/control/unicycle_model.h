#pragma once

#include "modules/control/interfaces/state.h"

namespace tareeq {
  namespace control {
    
    class UnicycleModel : public State {

    public:
      UnicyleModel(unordered_map<string, double> values) { values_{values} };

      virtual void Update(const unordered_map<string, double>& values);
      virtual void Update(const unordered_map<string, Sensor>& sensors);
  
    private:
      unordered_map<string, double> values_;

    };

  } // end namespace control
} // end namespace tareeq
