#pragma once

#include <string>
#include <memory>
#include <unordered_map>

#include "input.h"
#include "tareeq/control/interfaces/sensor.h"

namespace tareeq {
  namespace mocks {

    class MockSensor : public tareeq::control::Sensor
    {
    public:
      MOCK_METHOD0(ReadMeasurement, std::unordered_map<std::string, double>&());

    };
  } //end namespace mocks
} // end namespace tareeq
