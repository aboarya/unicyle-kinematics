#pragma once

#include "tareeq/gpio/pwm.h"
#include "tareeq/gpio/output.h"

namespace tareeq {
  namespace control {

    using tareeq::gpio::Pwm;
    using tareeq::gpio::Output;
    
    class Motor {
      // private fields
      std::unique_ptr<Pwm> speed_pin_;
      std::unique_ptr<Output> control_a_;
      std::unique_ptr<Output> control_b_;
      
    public:
      Motor() = default;
      ~Motor() = default;
      
      Motor(std::unique_ptr<Pwm>&& speed_pin, std::unique_ptr<Output>&& control_a, std::unique_ptr<Output>&& control_b);
      
      bool Stop();
      bool SpinForward();
      bool SpinBackward();
    };

  } // end namespace control
} // end namespace tareeq
