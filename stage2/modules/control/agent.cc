#include <iostream>

#include "agent.h"

int main(int argc, char** argv)
{
  std::cout << ">>>>>>>>>>>>>> building actuators" << std::endl;
  
  tareeq::control::ControlAgent agent(tareeq::control::MakeAcutator());
    
    std::cout << ">>>>>>>>>>>>>> good so far" << std::endl;
  

  return 0;
}
