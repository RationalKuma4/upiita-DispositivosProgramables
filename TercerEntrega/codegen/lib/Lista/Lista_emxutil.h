/*
 * File: Lista_emxutil.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-Nov-2018 17:00:33
 */

#ifndef LISTA_EMXUTIL_H
#define LISTA_EMXUTIL_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Lista_types.h"

/* Function Declarations */
extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#endif

/*
 * File trailer for Lista_emxutil.h
 *
 * [EOF]
 */
