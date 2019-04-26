#pragma once

#include <unordered_map>

#include "tareeq/gpio/input.h"
#include "tareeq/control/interfaces/sensor.h"

namespace tareeq {
  namespace control {

    using tareeq::gpio::Input;
    
    class OdometrySensor : public Sensor {

      // private fields
      std::unique_ptr<Input>&& encoder_r_;
      std::unique_ptr<Input>&& encoder_l_;
      
      std::unordered_map<std::string, double> map_;
      
    public:

      OdometrySensor(std::unique_ptr<Input>&& encoder_r, std::unique_ptr<Input>&& encoder_l);
      
      virtual bool IsActive();
      
      virtual void Init(const SensorConfig& config);
      
      virtual const std::unordered_map<std::string, double>& ReadMeasurement();
      
    };
    
  } // end namespace control
} // end namespace tareeq
