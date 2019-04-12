#include "pwm_impl.h"

namespace tareeq {
  namespace gpio {
    
    std::unique_ptr<Pwm> MakePwmPin()
    {
      const int line_number = 12;
      return std::make_unique<PwmImpl<gpiod::chip, gpiod::line, gpiod::line_request>>(line_number);
    }
  } // namespace gpio  
} // namespace tareeq
