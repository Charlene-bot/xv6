/*
 * This file contains types and definitions for Portland State University.
 * The contents are intended to be visible in both user and kernel space.
 */

#ifndef PDX_INCLUDE
#define PDX_INCLUDE

#define TRUE 1
#define FALSE 0
#define RETURN_SUCCESS 0
#define RETURN_FAILURE -1

#define NUL 0
#ifndef NULL
#define NULL NUL
#endif  // NULL

#define TPS 1000   // ticks-per-second
#define SCHED_INTERVAL (TPS/100)  // see trap.c

#define NPROC  64  // maximum number of processes -- normally in param.h

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

#ifdef CS333_P2
#define _setgid  100
#define _setuid  100
#endif //CS333_P2 sets the init process uid and gid to 100

#ifdef CS333_P4
#define DEFAULT_BUDGET (1*TPS)
#define DEFAULT_PRIORITY MAXPRIO 
#define TICKS_TO_PROMOTE (3*TPS) 
#define MAXPRIO 6  //Max priority 0<= prio <= MAXPRIO (Number of priority queues)
#define BUDGET 300
#define PER_LINE 15
#endif //CS333_P4


#endif  // PDX_INCLUDE
