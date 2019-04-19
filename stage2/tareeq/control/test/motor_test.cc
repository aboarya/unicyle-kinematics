#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "modules/control/motor_impl.h"


namespace tareeq {
  namespace control {

    class MockSpeedPin {
    public:
      MOCK_METHOD0(Start, void());
      MOCK_METHOD0(Stop, void());      
      MOCK_METHOD1(SetSpeed, void(double duty_cycle));
      
      ~MockSpeedPin() = default;
    };

    class MockControlPin {
    public:
      MOCK_METHOD0(On, void());
      MOCK_METHOD0(Off, void());

      ~MockControlPin() = default;
    };

    class MotorTest: public testing::Test {
    protected:
      void SetUp() override {
	
      }

      MockSpeedPin a;
      MockControlPin b;
      MotorImpl<MockSpeedPin, MockControlPin> motor{a, b, b};
    };

    TEST_F(MotorTest, CheckValidDecoupling) {
      motor.Run();
      EXPECT_EQ(true, true); // TO-DO: make Run() return boolean

      motor.ApplyRotationRate(50.0);
      EXPECT_EQ(true, true); // TO-DO: make ApplyRotationRate() return boolean

      motor.Stop();
      EXPECT_EQ(true, true); // TO-DO: make Stop() return boolean
    }

  } // namespace control
} // namespace tareeq
