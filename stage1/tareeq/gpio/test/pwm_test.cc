#include "tareeq/gpio/pwm.h"
#include <gtest/gtest.h>

namespace {

  class PwmTest: public testing::Test {
  protected:
    void SetUp() override {
      pwm_(12);
    }

    Pwm pwm_;
  }
}

TEST_F(PwmTests, SetDutyCycle) {

  pwm->SetDutyCycle(50);
  ASSERT_EXPECT_EQ(50, pwm->GetDutyCycle());


  pwm->SetDutyCycle(-10);
  ASSERT_EXPECT_EQ(0, pwm->GetDutyCycle());

  pwm->SetDutyCycle(150);
  ASSERT_EXPECT_EQ(100, pwm->GetDutyCycle());

}
