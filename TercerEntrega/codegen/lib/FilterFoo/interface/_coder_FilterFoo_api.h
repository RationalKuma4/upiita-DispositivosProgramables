/*
 * File: _coder_FilterFoo_api.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 25-Nov-2018 00:03:20
 */

#ifndef _CODER_FILTERFOO_API_H
#define _CODER_FILTERFOO_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_FilterFoo_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void FilterFoo(real_T b_y1[8000], real_T y[8000]);
extern void FilterFoo_api(const mxArray * const prhs[1], int32_T nlhs, const
  mxArray *plhs[1]);
extern void FilterFoo_atexit(void);
extern void FilterFoo_initialize(void);
extern void FilterFoo_terminate(void);
extern void FilterFoo_xil_terminate(void);

#endif

/*
 * File trailer for _coder_FilterFoo_api.h
 *
 * [EOF]
 */
