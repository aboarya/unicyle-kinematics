#include <iostream>
#include <cstdint>
#include <thread>
#include <cmath>

#include "modules/control/motor.h"
#include "modules/control/encoder.h"


int main(int argc, char** argv)
{
  Encoder encoder_r(18);
  encoder_r.run();

  Encoder encoder_l(23);
  encoder_l.run();

  
  uint8_t speed = 26;
  uint8_t a = 20;
  uint8_t b = 21;

  uint8_t speed1 = 12;
  uint8_t c = 6;
  uint8_t d = 13;

  Motor m(speed, a, b);
  Motor m1(speed1, c, d);

  std::cout << "starting motor ... " << std::endl;

  m.run();
  m1.run();
  
  int i = 0;
 
  double d_baseline = 12 / 100.;
  double d_right;
  double d_left;

  double d_center;
  double phi;
  
  double x = 0.;
  double y = 0.;
  double theta = 90. * 3.14159/180; ;
  

  double theta_new;
  double x_new;
  double y_new;
  
  while ( i < 10)
    {
      // m.speed_up();
      // m1.speed_up();

      std::this_thread::sleep_for(std::chrono::milliseconds(1000));

      d_right = encoder_r.calculate_distance_traveled();
      d_left = encoder_l.calculate_distance_traveled();

      d_center = (d_left + d_right) / 2.0;

      phi = (d_right - d_left) / d_baseline;

      theta_new = theta + phi;
      x_new = x + (d_center * cos(theta));
      y_new = y + (d_center * sin(theta));

      std::cout << "distance right = " << d_right << " and d_left = " << d_left << " and theta_new = " << theta_new << " x_new = " << x_new << " y_new = " << y_new << " phi = " << phi << std::endl;

      x = x_new;
      y = x_new;
      theta = theta_new;
      
      
      i++;
      
    }
  
  std::cout << "stopping motor " << std::endl;

  m.stop();
  m1.stop();
  
  encoder_r.stop();
  //encoder_l.stop();
  
  std::cout << "motor stopped " << std::endl;
  return 0;
}
