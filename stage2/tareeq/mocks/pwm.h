#pragma once

#include "tareeq/gpio/pwm.h"

namespace tareeq {
  namespace mocks {
    
    class MockPwm : public tareeq::gpio::Pwm
    {
    public:
      MOCK_METHOD0(Stop, void());
      MOCK_METHOD0(Pulse, void());
      MOCK_METHOD0(Start, void());
      MOCK_METHOD0(CalculateDuration, void());

      MOCK_METHOD0(GetDutyCycle, const double());
      
      MOCK_METHOD1(SetSpeed, void(double speed));
      MOCK_METHOD1(SetFrequency, void(double speed));
      


    };
  } //end namespace mocks
} // end namespace tareeq
