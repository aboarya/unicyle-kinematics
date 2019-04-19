// #include "motor.h"
// #include "motor_impl.h"

// #include "tareeq/gpio/pwm.h"
// #include "tareeq/gpio/output.h"

// namespace tareeq {
//   namespace control {
    
//     std::unique_ptr<Motor> MakeMotor()
//     {      
//       auto speed_pin = tareeq::gpio::MakePwmPin();
//       auto c_pin_a   = tareeq::gpio::MakeOutputPin();
//       auto c_pin_b   = tareeq::gpio::MakeOutputPin();
      
//       return std::make_unique<MotorImpl<tareeq::gpio::Pwm, tareeq::gpio::Output>>(*speed_pin, *c_pin_a, *c_pin_b);
//     }
    
//   } // namespace control  
// } // namespace tareeq
