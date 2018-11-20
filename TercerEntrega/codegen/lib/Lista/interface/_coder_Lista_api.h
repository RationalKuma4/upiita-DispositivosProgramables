/*
 * File: _coder_Lista_api.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-Nov-2018 17:00:33
 */

#ifndef _CODER_LISTA_API_H
#define _CODER_LISTA_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_Lista_api.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void Lista(real_T a, real_T b, real_T d, emxArray_real_T *vector);
extern void Lista_api(const mxArray * const prhs[3], int32_T nlhs, const mxArray
                      *plhs[1]);
extern void Lista_atexit(void);
extern void Lista_initialize(void);
extern void Lista_terminate(void);
extern void Lista_xil_terminate(void);

#endif

/*
 * File trailer for _coder_Lista_api.h
 *
 * [EOF]
 */
