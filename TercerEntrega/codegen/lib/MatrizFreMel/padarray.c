/*
 * File: padarray.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 25-Nov-2018 12:09:16
 */

/* Include Files */
#include <string.h>
#include "rt_nonfinite.h"
#include "MatrizFreMel.h"
#include "padarray.h"

/* Function Definitions */

/*
 * Arguments    : const double varargin_1[1008]
 *                double b[1250]
 * Return Type  : void
 */
void padarray(const double varargin_1[1008], double b[1250])
{
  int j;
  int i;
  for (j = 0; j < 4; j++) {
    memset(&b[j * 50 + 1050], 0, 50U * sizeof(double));
  }

  for (j = 0; j < 21; j++) {
    for (i = 0; i < 2; i++) {
      b[(i + 50 * j) + 48] = 0.0;
    }

    memcpy(&b[j * 50], &varargin_1[j * 48], 48U * sizeof(double));
  }
}

/*
 * File trailer for padarray.c
 *
 * [EOF]
 */
