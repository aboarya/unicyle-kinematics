#ifndef CONTROL_ENCODER_
#define CONTROL_ENCODER_

#include "tareeq/gpio/input.h"

class Encoder
{
 public:

  Encoder(const uint32_t line_number);
  ~Encoder();

  void Stop();
  void Run();

  void CalculateRotationRate();
  void CalculateDistanceTraveled();
  
  const double &GetDistanceTraveled();
  const double &GetRotationRate();
  const double &GetWheelRadius();  
  
 private:
  bool is_running_;
  Input input_pin_;

  const double   circumference_m_ = 6.0 / 100; // in meters
  const double  wheel_radius_m_ = circumference_m_ / 2.; // in meters
  
  const uint32_t line_number_;
  const uint32_t num_slots_ = 20;

  double   rotation_rate_ = 0.; // in radians / second
  
  double   distance_traveled_   = 0.;
  double   current_distance_    = 0.;
  double   prev_distance_       = 0.;

  std::chrono::milliseconds time_window_ = std::chrono::milliseconds(1); // 1 milliseconds
};

#endif // CONTROL_ENCODER
