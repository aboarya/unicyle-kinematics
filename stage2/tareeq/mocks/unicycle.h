#pragma once

#include <string>
#include <unordered_map>

#include "tareeq/control/unicycle_model.h"

namespace tareeq {
  namespace mocks {
    
    class MockState : public tareeq::control::UnicycleModel
    {
    public:
    MockState(std::unordered_map<std::string, double> values)
      : tareeq::control::UnicycleModel(values)
	{};
      
      MOCK_METHOD1(Update, void(std::unordered_map<std::string, tareeq::control::Sensor> values));
      MOCK_METHOD1(Update, void(std::unordered_map<std::string, double> values));
      MOCK_METHOD0(GetRep, std::unordered_map<std::string, double>());

    };
  } //end namespace mocks
} // end namespace tareeq
