#pragma once

#include <string>
#include <unordered_map>

namespace tareeq {
  namespace control {
    
    struct SensorConfig {
      // required config values
    };

    class Sensor {
      
      virtual ~Sensor() = default;

      virtual bool IsActive() = 0;

      virtual void Init(const SensorConfig& config) = 0;
      virtual std::unordered_map<std::string, double> const ReadMeasurement() = 0;
  
    };
    
  } // end namespace control
} // end namespace tareeq

