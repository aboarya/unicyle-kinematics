#pragma once

#include "tareeq/gpio/pwm.h"
#include "tareeq/gpio/output.h"

namespace tareeq {
  namespace control {

    using tareeq::gpio::Pwm;
    using tareeq::gpio::Output;
    
    class Motor {
      // private fields
      bool is_started_ = false;
      bool is_spin_forward_ = false;
      
      std::unique_ptr<Pwm> speed_pin_;
      std::unique_ptr<Output> control_a_;
      std::unique_ptr<Output> control_b_;
      
    public:
      //Motor() = default;
      ~Motor() = default;      
      Motor(Motor&&) = default;


     
      Motor(std::unique_ptr<Pwm>&& speed_pin, std::unique_ptr<Output>&& control_a, std::unique_ptr<Output>&& control_b);

      bool Start();
      bool Stop();
      bool SpinForward();
      bool SpinBackward();
      bool SetSpeed(const double w);

      inline const bool IsStarted(){return is_started_;};
      inline const bool IsSpinForward(){return is_spin_forward_;};
      
    };

  } // end namespace control
} // end namespace tareeq
