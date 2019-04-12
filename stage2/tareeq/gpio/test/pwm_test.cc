#include "tareeq/gpio/pwm_impl.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace tareeq {
  namespace gpio {

  struct MockLineRequest {
  public:
    enum { 
      DIRECTION_AS_IS = 1, DIRECTION_INPUT, DIRECTION_OUTPUT, EVENT_FALLING_EDGE, 
      EVENT_RISING_EDGE, EVENT_BOTH_EDGES 
    };

    std::string consumer;
    int request_type;
    
  };
    
  class MockLine {
  public:
    
    enum { DIRECTION_INPUT = 1, DIRECTION_OUTPUT };
    enum { ACTIVE_LOW = 1, ACTIVE_HIGH };

    MockLine()  = default;
    ~MockLine() = default;
    
    void request(MockLineRequest request)
    {
      // do nothing for now
    }

    void set_value(int value)
    {
      // do nothing for now
    }

    MockLineRequest request_;
  };
    
  class MockChip {

  public:
    enum  { 
	OPEN_LOOKUP = 1, OPEN_BY_PATH, OPEN_BY_NAME, OPEN_BY_LABEL, 
	OPEN_BY_NUMBER 
    };

    MockChip() = default;
    ~MockChip() = default;
    
    MockChip(std::string chipnumber, int openby){};

    MockLine get_line(int linenumber)
    {
      return line_;
    }
    
    MockLine line_;
    
  };
  
  class PwmTest: public testing::Test {
  protected:
    void SetUp() override {
      
    }

    PwmImpl<MockChip,MockLine,MockLineRequest> pwm_{12};
  };


  TEST_F(PwmTest, SetDutyCycle) {

    pwm_.SetSpeed(50);
    EXPECT_EQ(50, pwm_.GetDutyCycle());
  

    pwm_.SetSpeed(-10);
    EXPECT_EQ(0, pwm_.GetDutyCycle());

    pwm_.SetSpeed(150);
    EXPECT_EQ(100, pwm_.GetDutyCycle());
    
  }

 } // namespace gpio
} // namespace tareeq

