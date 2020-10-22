#ifdef CS333_P2
#include "types.h"
#include "user.h"
#include "stat.h"



int 
main(int argc, char* argv[])
{
  int ticks_in = uptime(); 
  int pid = fork(); 


  if(pid < 0)
  {
    printf(2, "Error!\n"); 
    exit(); 
  }
  if(pid > 0)
    wait(); 
  if(pid == 0)
  {
    if(exec(argv[1], argv +1) < 0)
    {
      printf(2, "Error!!\n");
      exit();
    }
  } 
    int ticks_out = uptime(); 
    int total_time = ticks_out - ticks_in;

    int seconds = total_time/1000;
    int milli = total_time %1000; 

    int hun = milli/100; 
    int ten = (milli%100)/10; 
    int ones = (milli%10); 

    printf(1, "%s ran in %d.%d%d%d seconds\n", argv[1], seconds, hun, ten, ones);
  exit();
}
#endif 
