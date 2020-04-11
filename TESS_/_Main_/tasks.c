#include "tasks.h"


void _100US_LOOP (void)
{

#if(!FMSTR_DISABLE)
    {
      FMSTR_Poll();
      FMSTR_Recorder();
    }
#endif

}

void _2MS_LOOP (void)
{

}

void _10MS_LOOP (void)
{


}
