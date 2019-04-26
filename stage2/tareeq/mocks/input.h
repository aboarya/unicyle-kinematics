#pragma once

#include "tareeq/gpio/input.h"

namespace tareeq {
  namespace mocks {
    
    class MockInput : public tareeq::gpio::Input
    {
    public:
      
      MOCK_METHOD0(WaitForEdge, void());
      MOCK_METHOD0(GetTotalCount, const long&());

    };
  } //end namespace mocks
} // end namespace tareeq
