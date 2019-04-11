#ifndef GPIO_INTERFACE
#define GPIO_INTERFACE

template <typename TChip, typename TLine, typename TLineRequest>
  class Gpio
{
 private:
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
  
  /* 
     boolean used to activate
     and deactivate the robot
  */
  inline const bool &IsRunning()
  {
    return is_running_;
  };
  
  TChip chip_;
  TLine line_;
  TLineRequest request_;
  
  /** gpio pin number, not board pin number */
  uint32_t line_number_;
  
  /* set by child classes */
  bool is_running_;
  
  int  request_type_;
  std::string direction_;
  std::string consumer_;
};

class Pwm : private Gpio
{
 public:
  virtual Pwm() = default;
  virtual ~Pwm() = default;

  //
  virtual Pwm(const int& line_number) = 0;
  virtual void SetFrequency(double freq) = 0;
  virtual void Pulse() = 0;
  virtual void SetDutyCycle(double duty_cycle) = 0;
  virtual const double &GetDutyCycle() = 0;
  virtual inline void CalculateDuration() = 0;

};


class Input : private Gpio
{
 public:
  virtual Input()  = default;
  virtual ~Input() = default;

  // 
  virtual Input(const int& line_number) = 0;
  virtual void WaitForEdge() = 0;
  virtual const long& GetTotalCount() = 0;
  
};

class Output: private Gpio
{
 public:
  virtual Output() = default;
  virtual ~Output() = default;

  //
  virtual Output(const int& line_number) = 0;
  virtual void OutputValue() = 0;

};

#endif // GPIO_INTERFACE
