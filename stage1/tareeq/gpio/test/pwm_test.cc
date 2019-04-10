#include "tareeq/gpio/pwm.h"
#include <gtest/gtest.h>

namespace {

  class PwmTest: public testing::Test {
  protected:
    void SetUp() override {
      
    }

    Pwm pwm_{12};
  };


  TEST_F(PwmTest, SetDutyCycle) {

    pwm_.SetDutyCycle(50);
    EXPECT_EQ(50, pwm_.GetDutyCycle());
  

    pwm_.SetDutyCycle(-10);
    EXPECT_EQ(0, pwm_.GetDutyCycle());

    pwm_.SetDutyCycle(150);
    EXPECT_EQ(100, pwm_.GetDutyCycle());
    
  }

} // namespace
