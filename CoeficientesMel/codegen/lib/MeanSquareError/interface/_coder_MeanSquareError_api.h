/*
 * File: _coder_MeanSquareError_api.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 25-Nov-2018 13:22:46
 */

#ifndef _CODER_MEANSQUAREERROR_API_H
#define _CODER_MEANSQUAREERROR_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_MeanSquareError_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern real_T MeanSquareError(real_T referencia[1250], real_T aproximacion[1250]);
extern void MeanSquareError_api(const mxArray * const prhs[2], int32_T nlhs,
  const mxArray *plhs[1]);
extern void MeanSquareError_atexit(void);
extern void MeanSquareError_initialize(void);
extern void MeanSquareError_terminate(void);
extern void MeanSquareError_xil_terminate(void);

#endif

/*
 * File trailer for _coder_MeanSquareError_api.h
 *
 * [EOF]
 */
