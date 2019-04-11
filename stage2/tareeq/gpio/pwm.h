#ifndef PWM_INTERFACE_
#define PWM_INTERFACE_

namespace tareeq {
  namespace gpio {
    class Pwm
    {
    public:
      virtual ~Pwm() = default;
  
      //
      virtual void SetFrequency(double freq) = 0;
      virtual void Pulse() = 0;
      virtual void SetDutyCycle(double duty_cycle) = 0;
      virtual const double &GetDutyCycle() = 0;
      virtual inline void CalculateDuration() = 0;
      
    };
  } // namespace gpio
} // namespace tareeq

#endif // PWM_INTERFACE_
