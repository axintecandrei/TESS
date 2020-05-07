#include "tasks.h"


void _100US_LOOP (void)
{
	TESS_LOOP_CNT++;
	LLD_ADC_GET_RAW_VAL();

#if CFG_ACQ_ON
	TESS_DAS_MAIN();
#endif

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
