#pragma once

#include <string>
#include <unordered_map>

namespace tareeq {
  namespace control {
    
    //struct SensorConfig {
      // required config values
    //};

    class Sensor {
    public:
      virtual ~Sensor() = default;

      //virtual bool IsActive() = 0;

      //virtual void Init(const SensorConfig& config) = 0;
      virtual const std::unordered_map<std::string, double>& ReadMeasurement() = 0;
  
    };
    
  } // end namespace control
} // end namespace tareeq

