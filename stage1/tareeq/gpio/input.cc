#include <iostream>
#include <chrono>
#include <thread>
#include <string>

#include "input.h"

void Input::WaitForEdge() 
{

  while(this->IsRunning())
    {
      while (line_.event_wait(std::chrono::milliseconds(1)))
	{
	  event_ = line_.event_read();
	  if (event_.event_type == gpiod::line_event::FALLING_EDGE)
	    {
	      total_count_++;
	    }
	}
    }
}

const long& Input::GetTotalCount()
{
  return total_count_;
}
