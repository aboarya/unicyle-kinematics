#ifndef GPIO_OUTPUT_INTERFACE_
#define GPIO_OUTPUT_INTERFACE_

namespace tareeq {
  namespace gpio {
    class Output
    {
    public:
      virtual ~Output() = default;
      
      //
      virtual void OutputValue(int value) = 0;
    };
  } // namespace gpio  
} // namespace tareeq

#endif // GPIO_OUTPUT_INTERFACE_
