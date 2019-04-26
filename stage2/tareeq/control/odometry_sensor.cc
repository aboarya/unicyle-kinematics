#include "tareeq/control/odometry_sensor.h"

namespace tareeq {
  namespace control {

    OdometrySensor::IsActive()
    {
      // STUB : TO-DO add code
      return true;
    }

    OdometrySensor::Init(const SensorConfig& config)
    {
      // STUB : TO-DO add code
    }

    const std::unordered_map<std::string, double>& OdometrySensor::ReadMeasurement()
    {
      map_["encoder_r_"] = static_cast<double>(encoder_r_.GetTotalCount());
      map_["encoder_l_"] = static_cast<double>(encoder_l_.GetTotalCount());
      return map_;
    }
    
  } // end namespace control
} // end namespace tareeq
