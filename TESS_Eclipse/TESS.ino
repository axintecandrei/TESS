#ifdef __cplusplus
extern "C" {
#endif
  #include "TESS_main/tess_main.h"
#ifdef __cplusplus
}
#endif

volatile unsigned_char_t byte_r;
unsigned_char_t pin_State;
void setup()
{
  TESS_BFU_ADC_INIT();
  TESS_BFU_UART_INIT();
  TESS_BFU_IO_INIT();
  TESS_BFU_PWM_INIT();
  TESS_MOC_SPEEDCURRCTRL_INIT();
  TESS_MIP_BEMFEST_INIT();
  TESS_MIP_MOTOR_TORQUE_CALC_INIT();

  pinMode(7, OUTPUT);
  digitalWrite(7,0);
  byte_r = 0;
  pin_State = 0;

}

void loop()
{
   ;   /*The magic is happening in the timer ISR...*/
}

ISR(TIMER1_OVF_vect)
{

  Set_TessStateMachReqSpeed(TESS_MAP(byte_r,0,127,0,32000));
  if((Get_TessStateMachReqSpeed() > 0) && (Get_TessStateMachReqSpeed()  <= 16000))
     Set_TessStateMachReqSpeed(Get_TessStateMachReqSpeed()-16000);
  else if ((Get_TessStateMachReqSpeed()  > 16000) && (Get_TessStateMachReqSpeed() <= 32000))
     Set_TessStateMachReqSpeed((-1)*(16000-Get_TessStateMachReqSpeed()));
  pin_State ^= 1;
  digitalWrite(7,pin_State);
  TESS_TASK_SCHEDULER();
  //digitalWrite(7,0);
}

ISR(USART_RX_vect)
{

#if ( CFG_ACQ_ON == 1)
  byte_r = UDR0;
  if(byte_r > 0)
  {
	  TESS_START_ACQ = 1;
  }
  else
  {
	  TESS_START_ACQ = 0;
  }
#else
   TESS_BFU_UART_RX_HANDLER();
#endif
}

ISR(USART_TX_vect)
{
#if (CFG_ACQ_ON == 1)
   if(!TESS_RINGBUFF_IS_EMPTY(&TESS_RING_BUFFER))
   {
      UDR0 = TESS_RING_BUFFER_GET(&TESS_RING_BUFFER);
   }
   else
   {
	   /*do nothing*/
   }
#endif
}


