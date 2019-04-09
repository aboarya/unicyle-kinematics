#define _USE_MATH_DEFINES
 
#include <cmath>

#include <iostream>
#include <chrono>
#include <thread>
#include <string>

#include "encoder.h"

Encoder::Encoder(const uint32_t line_number): line_number_(line_number)
{
  input_pin_ = Input(line_number);
  is_running_ = true;
}

void Encoder::Run()
{
  std::thread interrupt_routine(&Input::wait_for_edge, std::ref(this->input_pin_));
  interrupt_routine.detach();
  
  std::thread rps_routine(&Encoder::CalculateDistanceTraveled, this);
  rps_routine.detach();
  

}

void Encoder::Stop()
{
  is_running_ = false;
}

Encoder::~Encoder()
{
  Stop();
}

void Encoder::CalculateDistanceTraveled()
{
  while (this->is_running_)
    {

      //std::cout << "   total count " << input_pin_.get_total_count() << std::endl;
      distance_traveled_ = (2.0 * M_PI *
			    static_cast<double>(input_pin_.get_total_count() / num_slots_)
			    * wheel_radius_m_); // in meters
      
      current_distance_ = distance_traveled_;
      
      // rotate rate = distance / 1 ms * (1000 ms / 1 second) 
      if (current_distance_ != prev_distance_)
	{
	  //std::cout << this->line_number_ << "-- current distance " << current_distance_ << " and previous distance = " << prev_distance_  << "and rotation rate " << rotation_rate_ << std::endl;
	  rotation_rate_ = (current_distance_ - prev_distance_) * 1000; // in seconds
	  prev_distance_ = current_distance_;
	   
	}

      std::this_thread::sleep_for( time_window_); // 1 millisecond

    }
}

const double Encoder::GetDistanceTraveled()
{
  return distance_traveled_ ;
}

const double Encoder::GetRotationRate()
{
  return rotation_rate_ ;
}

void Encoder::CalculateRotationRate()
{
  // while (this->is_running_)
  //{
  //std::this_thread::sleep_for( time_window_ ); // 100 milliseconds
      
      current_distance_ = distance_traveled_;

      // rotate rate = distance / 100 ms * (1000 ms / 1 second) 
      rotation_rate_ = (current_distance_ - prev_distance_) * 10.; // in seconds
      prev_distance_ = current_distance_;

      std::cout << " >>>>>>> distance_traveled " << distance_traveled_ << " and current distance " << current_distance_ << " and rotation rate " << rotation_rate_ << std::endl;
      //}
}
