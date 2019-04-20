#pragma once


#include <string>
#include <memory>
#include <unordered_map>

#include "tareeq/control/interfaces/pid.h"
#include "tareeq/control/interfaces/state.h"
#include "tareeq/control/interfaces/sensor.h"
#include "tareeq/control/interfaces/actuator.h"

namespace tareeq {
  namespace control {

    class ControlAgent {

      // set target state
      // measure current state
      // calculate error
      // apply error

    public:
    ControlAgent(const unordered_map<std::string, Sensor>& sensors,
		 const PID& regulator,
		 const Actuator& actuator) :
      sensors_{std::move(sensors)},
	regulator_{std::move(regulator)},
	  actuator_{std::move(actuator)}
	{};
      
      void SetTargetState(const State& state);
  
      void ClosedLoop()
      {
	//State error = regulator.CalculateError(target_state_, current_state_);
    
	//while (target - error > some_threshold)
	//{
	//  actuator.Apply(error);
	//  current_state_.Update(sensor);
	//  error = regulator.CalculateError(target_state_, current_state_);	
	// }
      };
    private:
      State current_state_;
      State target_state_;

    };
    
  } // namespace control 
} // namespace tareeq
