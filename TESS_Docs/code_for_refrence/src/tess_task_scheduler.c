/**
  ******************************************************************************
  * File Name          : tess_task_scheduler.c
  * Author			   : Axinte Andrei
  * Description        : Scheduler of tasks source file
  ******************************************************************************
**/
#ifdef __cplusplus
extern "C" {
#endif

/*INCLUDES*/
#include "tess_task_scheduler.h"

/*Task Scheduler*/

unsigned_char_t runningTasks[4] = {255}; //Track running tasks-[0] always idleTask
const unsigned_char_t idleTask = 255;    // 0 highest priority, 255 lowest
unsigned_char_t currentTask = 0;         // Index of highest priority task in runningTasks
const unsigned_char_t tasksNum =2;
unsigned_int16_t tasksPeriod = 1; 

/*The priority is given by the position in the array */
task_t tasks[2]={{1,   1, MAIN_2MS_LOOP,  0},
                 {5,   5, MAIN_10MS_LOOP,  0}};

void TESS_TASK_SCHEDULER(void) 
{
  unsigned_char_t i;
  //SaveContext(); //save temporary registers, if necessary
  for (i=0; i < tasksNum; ++i) 
  { // Heart of scheduler code
    
    if ( (tasks[i].elapsedTime >= tasks[i].period)      // Task ready
        && (runningTasks[currentTask] > i)              // Task priority > current task priority
        && (!tasks[i].running)      )                    // Task not already running (no self-preemption)
          {
              
              //SuspendTick();                        //DisableInterrupts -  Critical section void 

              tasks[i].elapsedTime = 0; // Reset time since last tick
              tasks[i].running = 1; // Mark as running
              currentTask += 1;
              runningTasks[currentTask] = i; // Add to runningTasks
              
             // ResumeTick();                         //EnableInterrupts - End critical section void 
              
              tasks[i].function(); // Execute task
              
              //SuspendTick();                        //DisableInterrupts - Critical section 
              
              tasks[i].running = 0;
              runningTasks[currentTask] = idleTask; // Remove from runningTasks
              currentTask -= 1;
              
              //ResumeTick();                         //EnableInterrupts - End critical section void 
             
            }
    tasks[i].elapsedTime += tasksPeriod;
  }
  //RestoreContext();//restore temporary registers, if necessary
}

#ifdef __cplusplus
}
#endif
