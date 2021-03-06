#ifndef GPIO_
#define GPIO_

#include <iostream>
#include <string>
#include <cstdint>
#include <chrono>
#include <thread>

#include <gpiod.hpp>

static gpiod::chip chip_;

static void __attribute__((constructor)) setup() ;

static void setup()
{
  const std::string chip_number_ = std::string("0");
  chip_ = gpiod::chip(chip_number_, gpiod::chip::OPEN_BY_NUMBER); 
  
}


/*
Abstract Class for all GPIO Pins
*/

class Gpio
{
 public:
  Gpio() = default;
  ~Gpio() {this->Stop();};
  
 Gpio(const uint32_t &line_number,
      const std::string &direction):
  line_number_(line_number),
    direction_(direction)
    {
      
      if (direction == "output")
	{
	  request_type_ = gpiod::line_request::DIRECTION_OUTPUT;
	}
      else
	{
	  request_type_ = gpiod::line_request::EVENT_BOTH_EDGES;
	}
      
      consumer_ = std::string("pin_number_") + std::to_string(line_number);
      
      request_ = {
      consumer: consumer_,
      request_type: request_type_ 
      };

      line_ = chip_.get_line(line_number_);
      line_.request(request_);
      
    };
  
  
  void Stop()
  {
    this->is_running_ = false;
  };

  /* sets the dervied pin as a GPIO Output pin */
  inline void Output(int value)
  {
    this->line_.set_value(value);
  };

  /* 
     boolean used to activate
     and deactivate the robot
  */
  inline const bool &IsRunning()
    {
      return is_running_;
    };

 protected:
  gpiod::line line_;
  gpiod::line_request request_;
  
  /** gpio pin number, not board pin number */
  uint32_t line_number_;

  /* set by child classes */
  bool is_running_;
  
 private:
  int  request_type_;
  std::string direction_;
  std::string consumer_;
  
  
};

#endif // GPIO_
