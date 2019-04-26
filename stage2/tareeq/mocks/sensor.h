#pragma once

#include <string>
#include <unordered_map>

#include "tareeq/control/unicycle_model.h"

namespace tareeq {
  namespace mocks {

    struct SensorConfig
    {};
    
    class MockSensor : public tareeq::control::OdometrySensor
    {
    public:
    MockSensor(std::unique_ptr<Input>&& encoder_r, std::unique_ptr<Input>&& encoder_l)
      : tareeq::control::OdometrySensor(encoder_r, encoder_l)
	{};
      
      MOCK_METHOD0(IsActive, bool());
      MOCK_METHOD1(Init, void(SensorConfig config));
      MOCK_METHOD0(ReadMeasurement, std::unordered_map<std::string, double>());

    };
  } //end namespace mocks
} // end namespace tareeq
