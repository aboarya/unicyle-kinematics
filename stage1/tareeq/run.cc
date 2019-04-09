#include <iostream>
#include <chrono>
#include <thread>
#include <string>

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "modules/control/main.h"

ControlAgent agent;

void my_handler(int s){
  printf("Caught signal %d\n",s);
  
  // simple attempt at a clean shutdown
  agent.~ControlAgent();
  exit(1); 
  
}

int main(int argc, char **argv)
{
  struct sigaction sigIntHandler;

  sigIntHandler.sa_handler = my_handler;
  sigemptyset(&sigIntHandler.sa_mask);
  sigIntHandler.sa_flags = 0;
  
  sigaction(SIGINT, &sigIntHandler, NULL);

  // start system
  agent.run();

  // wait for ctrl-c
  //pause();

  std::chrono::milliseconds s(100);
  while (true)
    {
      agent.log();
      std::this_thread::sleep_for(s); 
    }
  return 0;    
 
}
