/*
 * -------------------------------------------------------------------
 * MPLAB 16-Bit Device Blocks for Simulink v3.38.
 *
 *   Product Page:  http://www.microchip.com/SimulinkBlocks
 *           Forum: http://www.microchip.com/forums/f192.aspx
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: MPLAB_device_block_main.c
 *
 * Code generated for Simulink model 'MPLAB_device_block'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * C/C++ source code generated on : Wed Apr 04 18:44:17 2018
 */

#define MCHP_isMainFile
#include "MPLAB_device_block.h"

/* Microchip Global Variables */
/* Set Fuses Options */

#pragma config FNOSC = FRC, PWMLOCK = OFF
#pragma config FWDTEN = OFF
#pragma config JTAGEN = OFF

/* Scheduler */
void __attribute__((__interrupt__,__auto_psv__)) _T1Interrupt(void)
{
  {
    struct {
      unsigned int Flags0 : 1;
      unsigned int Flags1 : 1;
    } static volatile Overrun;

    struct {
      unsigned int Flags0 : 1;
      unsigned int Flags1 : 1;
    } static volatile event;

    static int_T taskCounter[2] = { 0, 0 };

    _T1IF = 0;                         /* Re-enable interrupt */

    /* Check subrate overrun, set rates that need to run this time step*/
    if (taskCounter[1] == 0) {         /* task dropped on overload */
      event.Flags1 = 1U;
    }

    /* Update task internal counters */
    taskCounter[1]++;
    if (taskCounter[1] == 500) {
      taskCounter[1]= 0;
    }

    /* Step the model for base rate */
    /* Start profiling task 0 */
    MPLAB_device_block_step0();

    /* Get model outputs here */

    /* Stop profiling task 0 */
    if (_T1IF ) {
      return;                          /* Will re-enter into the interrupt */
    }

    /* Re-Enable Interrupt. IPL value is 2 at this point */
    _IPL0 = 1;                         /* Switch IPL from 2 to 1 to enable re-entrant scheduler interrupt */
    _IPL1 = 0;

    /* Step the model for any subrate */
    /* Handle Task 1 */
    if (Overrun.Flags1) {
      return;                          /* Priority to higher rate steps interrupted */
    }

    if (event.Flags1) {
      Overrun.Flags1 = 1;
      do {
        /* Start profiling task 1 */
        event.Flags1 = 0U;
        MPLAB_device_block_step1();

        /* Get model outputs here */
        ;                              /* Execute task tid 1 */

        /* Stop profiling task 1 */
      } while (event.Flags1);

      Overrun.Flags1 = 0U;
    }

    /* Disable Interrupt. IPL value is 1 at this point */
    _IPL1 = 1;                         /* Switch back IPL from 1 to 2 to disable re-entrant scheduler interrupt avoiding problem with interrupt epilog */
    _IPL0 = 0;
  }
}

int main()
{
  /* Initialize model */
  /* Configure Pins as Analog or Digital */
  /* Configure Remappables Pins */

  /* Configure Digitals I/O directions */
  TRISA = 0xFFF3;

  /* Initialize model */
  MPLAB_device_block_initialize();

  /* Configure Timers */
  /* --- TIMER 1 --- This timer is enabled at end of configuration functions. */
  T1CON = 0;                           /* Stop Timer 1 and resets control register */
  _T1IP = 2;                           /* Set timer Interrupt Priority */
  _T1IF = 0;                           /* Reset pending Interrupt */
  _T1IE = 1;                           /* Enable Timer Interrupt. */
  PR1 = 0x0E64;                        /* Period */

  /* Enable Time-step */
  TMR1 = 0x0E63;
  T1CONbits.TON = 1;                   /* Start timer 1. Timer 1 is the source trigger for the model Time-step */

  /* Main Loop */
  for (;;) ;
}                                      /* end of main() */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
