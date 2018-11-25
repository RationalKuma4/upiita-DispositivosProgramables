/*
 * File: _coder_MatrizFreMel_api.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 25-Nov-2018 12:09:16
 */

#ifndef _CODER_MATRIZFREMEL_API_H
#define _CODER_MATRIZFREMEL_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_MatrizFreMel_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void MatrizFreMel(real_T y[8000], real_T Hm[2688], real_T W[400], real_T
  mfcc[1250]);
extern void MatrizFreMel_api(const mxArray * const prhs[3], int32_T nlhs, const
  mxArray *plhs[1]);
extern void MatrizFreMel_atexit(void);
extern void MatrizFreMel_initialize(void);
extern void MatrizFreMel_terminate(void);
extern void MatrizFreMel_xil_terminate(void);

#endif

/*
 * File trailer for _coder_MatrizFreMel_api.h
 *
 * [EOF]
 */
