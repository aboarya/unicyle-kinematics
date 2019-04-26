
#include <string>
#include <unordered_map>

#include "tareeq/control/unicycle_model.h"
#include "tareeq/control/interfaces/sensor.h"
#include "tareeq/control/interfaces/state.h"

namespace tareeq {
  namespace control {
    

    UnicycleModel::UnicycleModel(const std::unordered_map<std::string, Sensor>& sensors)
      : sensors_{sensors}
    {}
      
    /**
     */
    void UnicycleModel::Update(const std::unordered_map<std::string, double>& values)
    {}
    
    /**
     */
    void UnicycleModel::Update()
    {}
    
    /**
     */
    const std::unordered_map<std::string, double>& UnicycleModel::GetRep() const
    {
      return this->values_;
    }
    
    /**
     */
    const std::unordered_map<std::string, double>& UnicycleModel::operator- (const State& state)
    {
      return state.GetRep();
    }
    
  } // end namespace control
} // end namespace tareeq
