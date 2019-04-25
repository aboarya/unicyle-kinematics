
#include <string>
#include <unordered_map>

#include "tareeq/control/interfaces/state.h"
#include "tareeq/control/unicycle_model.h"

namespace tareeq {
  namespace control {
    

    UnicycleModel::UnicycleModel(std::unordered_map<std::string, double> values)
      : values_{values}
    {}
      
    /**
     */
    void UnicycleModel::Update(const std::unordered_map<std::string, double>& values)
    {}
    
    /**
     */
    void UnicycleModel::Update(const std::unordered_map<std::string, Sensor>& sensors)
    {}
    
    /**
     */
    const std::unordered_map<std::string, double>& UnicycleModel::GetRep()
    {
      return this->values_;
    }
    
    /**
     */
    const std::unordered_map<std::string, double>& operator- (const State& state)
    {
      return state.GetRep();
    }
    
  } // end namespace control
} // end namespace tareeq
