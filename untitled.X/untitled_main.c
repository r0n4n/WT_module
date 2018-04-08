/*
 * -------------------------------------------------------------------
 * MPLAB 16-Bit Device Blocks for Simulink v3.38.
 *
 *   Product Page:  http://www.microchip.com/SimulinkBlocks
 *           Forum: http://www.microchip.com/forums/f192.aspx
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: untitled_main.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * C/C++ source code generated on : Wed Apr 04 14:41:17 2018
 */

#define MCHP_isMainFile
#include "untitled.h"

/* Microchip Global Variables */
volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;

/* Microchip Global Variables */
/* Set Fuses Options */
#pragma config FNOSC = FRC, PWMLOCK = OFF
#pragma config FWDTEN = OFF
#pragma config JTAGEN = OFF

/* Scheduler */
void __attribute__((__interrupt__,__auto_psv__)) _T1Interrupt(void)
{
  {
    extern volatile uint_T ContinueTimeStep __attribute__ ((near)) ;
    __asm__ volatile ( "BSET.b %[MyVar], #0" : [MyVar] "+m" (ContinueTimeStep) )
      ;                                /* Atomic bit-set: ContinueTimeStep |= 1 */
    _T1IF = 0;                         /* Re-enable interrupt */
  }
}

/* Solver mode : SingleTasking */
int main()
{
  /* Initialize model */
  /* Configure Pins as Analog or Digital */
  /* Configure Remappables Pins */

  /* Configure Digitals I/O directions */

  /* Initialize model */
  untitled_initialize();

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
  for (;;) {
    while (!ContinueTimeStep) ;

    /* Disable Interrupt below 2. IPL value is 0 at this point */
    _IPL0 = 1;                         /* Switch IPL from 0 to 1 */
    __asm__ volatile ("BCLR.b %[MyVar], #0" : [MyVar] "+m" (ContinueTimeStep) );/* Atomic bit-clear of ContinueTimeStep bit 1 */

    /* Call model Scheduler */
    /* Step the model for base rate */
    /* Start profiling task 0 */
    untitled_step();

    /* Get model outputs here */

    /* Stop profiling task 0 */

    /* Re-Enable all Interrupt. IPL value is 2 at this point */
    _IPL0 = 0;                         /* Switch back IPL from 1 to 0  */
  }                                    /* End for(;;) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
