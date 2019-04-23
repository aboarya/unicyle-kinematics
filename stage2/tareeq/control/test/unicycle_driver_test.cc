#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "tareeq/mocks/motor.h"
#include "../unicycle_driver.h"

namespace tareeq {
  namespace control {

    using namespace tareeq::mocks;
    
    class UniCDriverTest : public testing::Test
    {
    public:
      // Motor r{
      // 	std::make_unique<MockPwm>(),
      // 	  std::make_unique<MockOutput>(),
      // 	  std::make_unique<MockOutput>()
      // 	  };

      // Motor l{
      // 	std::make_unique<MockPwm>(),
      // 	  std::make_unique<MockOutput>(),
      // 	  std::make_unique<MockOutput>()
      // 	  };

      MockMotor r;
      MockMotor l;
      UniCycleDriver driver{r, l};
    };

    TEST_F(UniCDriverTest, CheckValidConstruction) {

      EXPECT_EQ(true, driver.Start()); // TO-DO: make Run() return boolean
      
    }

  } // end namespace control
} // end namespace tareeq
