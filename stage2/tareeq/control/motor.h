#pragma once

namespace tareeq {
  namespace control {
    
    class Motor {
    pubic:
      Motor(Pwm speed_pin, Ouput control_a, Output control_b);

      inline bool Start();
      inline bool Stop();
      inline bool SpinForward();
      inline bool SpinBackward();
    };

  } // end namespace control
} // end namespace tareeq
