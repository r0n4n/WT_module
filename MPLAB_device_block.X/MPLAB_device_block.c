/*
 * -------------------------------------------------------------------
 * MPLAB 16-Bit Device Blocks for Simulink v3.38.
 *
 *   Product Page:  http://www.microchip.com/SimulinkBlocks
 *           Forum: http://www.microchip.com/forums/f192.aspx
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: MPLAB_device_block.c
 *
 * Code generated for Simulink model 'MPLAB_device_block'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * C/C++ source code generated on : Wed Apr 04 18:44:17 2018
 */

#include "MPLAB_device_block.h"
#include "MPLAB_device_block_private.h"

/* Block signals and states (auto storage) */
DW_MPLAB_device_block_T MPLAB_device_block_DW;

/* Real-time model */
RT_MODEL_MPLAB_device_block_T MPLAB_device_block_M_;
RT_MODEL_MPLAB_device_block_T *const MPLAB_device_block_M =
  &MPLAB_device_block_M_;

/* Model step function for TID0 */
void MPLAB_device_block_step0(void)    /* Sample time: [0.001s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID1 */
void MPLAB_device_block_step1(void)    /* Sample time: [0.5s, 0.0s] */
{
  /* local block i/o variables */
  boolean_T rtb_DataTypeConversion;
  uint8_T rtb_FixPtSum1;

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  UnitDelay: '<S1>/Output'
   */
  rtb_DataTypeConversion = (MPLAB_device_block_DW.Output_DSTATE != 0);

  /* S-Function (MCHP_Digital_Output_Write): '<S2>/Digital Output Write' */
  LATAbits.LATA2 = rtb_DataTypeConversion;
  LATAbits.LATA3 = rtb_DataTypeConversion;

  /* Sum: '<S3>/FixPt Sum1' incorporates:
   *  Constant: '<S3>/FixPt Constant'
   *  UnitDelay: '<S1>/Output'
   */
  rtb_FixPtSum1 = (uint8_T)(MPLAB_device_block_DW.Output_DSTATE + 1U);

  /* Switch: '<S4>/FixPt Switch' */
  if (rtb_FixPtSum1 > 1) {
    /* Update for UnitDelay: '<S1>/Output' incorporates:
     *  Constant: '<S4>/Constant'
     */
    MPLAB_device_block_DW.Output_DSTATE = 0U;
  } else {
    /* Update for UnitDelay: '<S1>/Output' */
    MPLAB_device_block_DW.Output_DSTATE = rtb_FixPtSum1;
  }

  /* End of Switch: '<S4>/FixPt Switch' */
}

/* Model initialize function */
void MPLAB_device_block_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)&MPLAB_device_block_DW, 0,
                sizeof(DW_MPLAB_device_block_T));

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
