#pragma once

#include <string>
#include <unordered_map>

#include "sensor.h"
#include "tareeq/control/unicycle_model.h"

namespace tareeq {
  namespace mocks {
    
    class MockState : public tareeq::control::State
    {
      //std::unordered_map<std::string, std::unique_ptr<MockSensor>> sensors_;
      
    public:
    /* MockState(std::unordered_map<std::string, std::unique_ptr<MockSensor>> sensors) */
    /*   : tareeq::control::UnicycleModel(sensors) */
    /* 	{}; */

      /* MockState() */
      /* 	{ */
      /* 	  std::unique_ptr<MockSensor> sensor = std::make_unique<MockSensor>(); */
      /* 	  sensors_["odometry"] = std::move(sensor); */
      /* 	  tareeq::control::UnicycleModel(sensors_); */
      /* 	}; */
      
      //MOCK_METHOD1(Update, void(std::unordered_map<std::string, tareeq::control::Sensor> values));
      //MOCK_METHOD1(Update, void(std::unordered_map<std::string, double> values));
      MOCK_METHOD0(Update, void());
      MOCK_METHOD0(GetRep, std::unordered_map<std::string, double>());

    };
  } //end namespace mocks
} // end namespace tareeq
