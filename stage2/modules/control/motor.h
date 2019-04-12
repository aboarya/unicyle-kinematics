#ifndef TAREEQ_MOTOR_
#define TAREEQ_MOTOR_

#include <memory>

namespace tareeq {
  namespace control {
    
      class Motor
    {
    public:
      
      virtual ~Motor() = default;

      virtual void Run() = 0;
      virtual void Stop() = 0;
      virtual void ApplyRotationRate(double rotation_rate) = 0;
      
    };

      // simple factor method
      std::unique_ptr<Motor> MakeMotor();
    
  } // namespace control
} // namespace tareeq
#endif // TAREEQ_MOTOR_
