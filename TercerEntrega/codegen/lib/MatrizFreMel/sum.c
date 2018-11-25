/*
 * File: sum.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 25-Nov-2018 12:09:16
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "MatrizFreMel.h"
#include "sum.h"

/* Function Definitions */

/*
 * Arguments    : const double x[128]
 * Return Type  : double
 */
double sum(const double x[128])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 127; k++) {
    y += x[k + 1];
  }

  return y;
}

/*
 * File trailer for sum.c
 *
 * [EOF]
 */
