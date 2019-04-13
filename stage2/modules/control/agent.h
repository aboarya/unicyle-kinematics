#pragma once

#include <memory>

#include "actuators.h"

namespace tareeq {
  namespace control {

    class ControlAgent {
      
    public:
      ControlAgent(std::unique_ptr<Actuators>&& actuators)
	: actuators_(std::move(actuators))
      {
      }

      ControlAgent() = default;
      ~ControlAgent() = default;

    private:
      std::unique_ptr<Actuators> actuators_;
    };
    
    
  } // namespace control 
} // namespace tareeq
