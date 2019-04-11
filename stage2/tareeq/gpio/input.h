#ifndef INPUTGPIO_
#define INPUTGPIO_

#include "gpio.h"

const std::string input_("input");

template <typename TChip, typename TLine, typename TLineRequest>
class Input : public Gpio<TChip,TLine,TLineRequest>
{
 public:
  Input()  = default;
  ~Input() = default;
  
 Input(const uint32_t& line_number): Gpio(line_number, input_){};

  void WaitForEdge();

  const long& GetTotalCount();
  
 private:
  long total_count_ = 0;
  gpiod::line_event event_;
};

#endif // INPUTGPIO_
