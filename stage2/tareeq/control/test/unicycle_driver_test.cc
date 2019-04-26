#include <string>
#include <unordered_map>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "tareeq/mocks/motor.h"
#include "../unicycle_driver.h"
#include "tareeq/mocks/unicycle.h"

namespace tareeq {
  namespace control {

    using namespace tareeq::mocks;
    
    class UniCDriverTest : public testing::Test
    {
    public:

      void SetUp() override {
	m["w_r"] = 1.5;
	m["w_l"] = 1.5;
	s{MockState(m)};
      }


      MockSensor s
      MockState st;
      MockMotor r;
      MockMotor l;
      UniCycleDriver driver{r, l};
      std::unordred_map<std::string, double> m;
    };

    TEST_F(UniCDriverTest, CheckValidConstruction) {

      EXPECT_EQ(true, driver.Start());
      EXPECT_EQ(true, driver.Apply(st));
      EXPECT_EQ(true, driver.Stop());
    }

  } // end namespace control
} // end namespace tareeq
