/*
 * File: _coder_detectorExtremos_api.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 25-Nov-2018 00:34:53
 */

#ifndef _CODER_DETECTOREXTREMOS_API_H
#define _CODER_DETECTOREXTREMOS_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_detectorExtremos_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void detectorExtremos(real_T Y[8000], real_T palabradelimitada[4000]);
extern void detectorExtremos_api(const mxArray * const prhs[1], int32_T nlhs,
  const mxArray *plhs[1]);
extern void detectorExtremos_atexit(void);
extern void detectorExtremos_initialize(void);
extern void detectorExtremos_terminate(void);
extern void detectorExtremos_xil_terminate(void);

#endif

/*
 * File trailer for _coder_detectorExtremos_api.h
 *
 * [EOF]
 */
