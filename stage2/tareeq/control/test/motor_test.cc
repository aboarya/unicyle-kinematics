#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <memory>

#include "../motor.h"

#include "tareeq/mocks/pwm.h"
#include "tareeq/mocks/output.h"


namespace tareeq {
  namespace control {

    using namespace tareeq::mocks;
    
    class MotorTest : public testing::Test {

    public:
      
      Motor r_motor{
	std::make_unique<MockPwm>(),
	  std::make_unique<MockOutput>(),
	  std::make_unique<MockOutput>()
	  };
      
    };
    TEST_F(MotorTest, CheckConstructor) {
      
      EXPECT_EQ(true, r_motor.SpinForward());
      EXPECT_EQ(true, r_motor.SpinBackward());
      EXPECT_EQ(true, r_motor.Stop());
      
    }

  } // namespace control
} // namespace tareeq
