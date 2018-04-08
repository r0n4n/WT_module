/*
 * -------------------------------------------------------------------
 * MPLAB 16-Bit Device Blocks for Simulink v3.38.
 *
 *   Product Page:  http://www.microchip.com/SimulinkBlocks
 *           Forum: http://www.microchip.com/forums/f192.aspx
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: MPLAB_device_block.h
 *
 * Code generated for Simulink model 'MPLAB_device_block'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * C/C++ source code generated on : Wed Apr 04 18:44:17 2018
 */

#ifndef RTW_HEADER_MPLAB_device_block_h_
#define RTW_HEADER_MPLAB_device_block_h_
#include <string.h>
#include <stddef.h>
#ifndef MPLAB_device_block_COMMON_INCLUDES_
# define MPLAB_device_block_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* MPLAB_device_block_COMMON_INCLUDES_ */

#include "MPLAB_device_block_types.h"
#define FCY                            (3685000U)                /* Instruction Frequency FCY set at  3.685 MHz */

/* Include for pic 33E */
#include <p33Exxxx.h>
#include <libpic30.h>                  /* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include <libq.h>                      /* For possible use with C function Call block */

/* Macros for accessing real-time model data structure */
#ifndef rtmCounterLimit
# define rtmCounterLimit(rtm, idx)     ((rtm)->Timing.TaskCounters.cLimit[(idx)])
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  uint8_T Output_DSTATE;               /* '<S1>/Output' */
} DW_MPLAB_device_block_T;

/* Real-time Model Data Structure */
struct tag_RTM_MPLAB_device_block_T {
  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[2];
      uint16_T cLimit[2];
    } TaskCounters;
  } Timing;
};

/* Block signals and states (auto storage) */
extern DW_MPLAB_device_block_T MPLAB_device_block_DW;

/* Model entry point functions */
extern void MPLAB_device_block_initialize(void);
extern void MPLAB_device_block_step0(void);
extern void MPLAB_device_block_step1(void);

/* Real-time Model object */
extern RT_MODEL_MPLAB_device_block_T *const MPLAB_device_block_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'MPLAB_device_block'
 * '<S1>'   : 'MPLAB_device_block/Counter Limited'
 * '<S2>'   : 'MPLAB_device_block/Digital Output'
 * '<S3>'   : 'MPLAB_device_block/Counter Limited/Increment Real World'
 * '<S4>'   : 'MPLAB_device_block/Counter Limited/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_MPLAB_device_block_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
