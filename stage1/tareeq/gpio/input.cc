#include <iostream>
#include <chrono>
#include <thread>
#include <string>

#include "input.h"

const std::string input_("input");

Input::Input(const uint32_t& line_number): Gpio(line_number, input_)
{
  
}

void Input::wait_for_edge() 
{
  //line_ = chip_.get_line(line_number_);
  //line_.request(request_);
  while (line_.event_wait(std::chrono::seconds(1)))
    {
      event_ = line_.event_read();
      if (event_.event_type == gpiod::line_event::FALLING_EDGE)
	{
	  //std::cout << "OK " << std::endl;
	  total_count_++;
	}
    }
}

const long long Input::get_total_count()
{
  return total_count_;
}
