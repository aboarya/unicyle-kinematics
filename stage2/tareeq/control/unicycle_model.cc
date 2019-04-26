
#include <string>
#include <unordered_map>

#include "tareeq/control/unicycle_model.h"
#include "tareeq/control/interfaces/state.h"
#include "tareeq/control/interfaces/sensor.h"

namespace tareeq {
  namespace control {
    

    UnicycleModel::UnicycleModel(std::unordered_map<std::string, std::unique_ptr<Sensor>&&> sensors)
    {}
      
    /**
     */
    //void UnicycleModel::Update(const std::unordered_map<std::string, double>& values)
    //{}
    
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
