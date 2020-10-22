#ifdef CS333_P2
#include "types.h"
#include "uproc.h"
#include "user.h"
#include "stat.h"



int main()
{
  struct uproc * table; 
  uint max = 64;
  table = malloc(max * sizeof(struct uproc));
  int Num = getprocs(max, table);
 
  printf(1, "PID\tName    \tUID\tGID\tPPID\tElapsed\tCPU\tState\tSize\t");
  for(int i = 0 ; i < Num; i++) {
    //Decimal conversion for elapsed time 
    int seconds = table[i].elapsed_ticks/1000; 
    int milli = (table[i].elapsed_ticks)%1000; 

    int hund = milli/100; 
    int ten = (milli%100)/10;
    int one = milli%10; 


  //Decimal conversion for CPU time 
    int cpu_sec = table[i].CPU_total_ticks/1000;
    int cpu_milli = table[i].CPU_total_ticks%1000; 

    int cpu_hun = cpu_milli/100;
    int cpu_ten = (cpu_milli%100)/10;
    int cpu_one = cpu_milli%10; 


    printf(1,"\n%d\t%s\t        %d\t%d\t%d\t%d.%d%d%d\t%d.%d%d%d\t%s\t%d\n", table[i].pid, table[i].name, table[i].uid, table[i].gid, table[i].ppid, seconds, hund, ten ,one , cpu_sec, cpu_hun, cpu_ten, cpu_one, table[i].state, table[i].size);     
  }
/*
process id (as decimal integer)
name (as string)
process uid (as decimal integer)
process gid (as decimal integer)
parent process id (as decimal integer)
process elapsed time (as a floating point number)
process total CPU time (as a floating point number)
state (as string)
size (as decimal integer)

  */
  free(table);
  exit();
}
#endif //CS333_P2
