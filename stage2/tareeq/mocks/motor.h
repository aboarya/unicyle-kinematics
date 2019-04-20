#pragma once

#include "tareeq/control/motor.h"

namespace tareeq {
  namespace mocks {
    
    class MockMotor : public tareeq::control::Motor
    {
    public:
      MOCK_METHOD0(Start, bool());
      MOCK_METHOD0(Stop, bool());
      MOCK_METHOD0(SpinForward, bool());
      MOCK_METHOD0(SpinBackward, bool());

    };
  } //end namespace mocks
} // end namespace tareeq
