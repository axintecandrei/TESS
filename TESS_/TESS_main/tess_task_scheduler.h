/**
  ******************************************************************************
  * File Name          : tess_task_scheduler.h
  * Author			   : Axinte Andrei
  * Description        : Scheduler of tasks header file
  ******************************************************************************
**/
#ifndef __tess_task_scheduler_h__
#define __tess_task_scheduler_h__

#include "tess_tasks.h" 

/*Tasks Structure */
typedef struct task_t
{
  
  unsigned_int16_t period;                   /*The interval that the task should be executed*/
  unsigned_int16_t elapsedTime;              /*the amount of time that has passed since the previous execution of the task*/
  void(*function) (void);                    /* pointer to the task�s function.*/
  unsigned_char_t running;                   /*Flag that is checked to see if the task is ready to run*/

}task_t;



extern void TESS_TASK_SCHEDULER (void);

#endif /*__tess_task_scheduler_h__*/
