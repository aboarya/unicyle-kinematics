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
      MockMotor m;
      //UniCycleDriver driver{m, m};
    };

    TEST_F(UniCDriverTest, CheckValidConstruction) {

      EXPECT_EQ(true, true); // TO-DO: make Run() return boolean

    }

  } // end namespace control
} // end namespace tareeq
