#pragma once

#include <string>
#include <unordered_map>

#include "sensor.h"
#include "tareeq/control/unicycle_model.h"

namespace tareeq {
  namespace mocks {
    
    class MockState : public tareeq::control::State
    {
      
    public:
      MOCK_METHOD0(Update, void());
      MOCK_CONST_METHOD0(GetRep, std::unordered_map<std::string, double>&());
      virtual const std::unordered_map<std::string, double>& operator- (const tareeq::control::State& state) override { return state.GetRep();}

    };
  } //end namespace mocks
} // end namespace tareeq
