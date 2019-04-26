#pragma once

#include <string>
#include <memory>
#include <unordered_map>

#include "input.h"
#include "tareeq/control/odometry_sensor.h"
#include "tareeq/control/unicycle_model.h"

namespace tareeq {
  namespace mocks {

    //struct SensorConfig
    //{};
    
    class MockSensor : public tareeq::control::OdometrySensor
    {
    public:
    MockSensor()
      : tareeq::control::OdometrySensor(std::make_unique<MockInput>(), std::make_unique<MockInput>())
	{};
      
      //MOCK_METHOD0(IsActive, bool());
      //MOCK_METHOD1(Init, void(SensorConfig config));
      MOCK_METHOD0(ReadMeasurement, std::unordered_map<std::string, double>&());

    };
  } //end namespace mocks
} // end namespace tareeq
