/*
 * File: abs.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 25-Nov-2018 13:22:46
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "MeanSquareError.h"
#include "abs.h"

/* Function Definitions */

/*
 * Arguments    : const double x[1250]
 *                double y[1250]
 * Return Type  : void
 */
void b_abs(const double x[1250], double y[1250])
{
  int k;
  for (k = 0; k < 1250; k++) {
    y[k] = fabs(x[k]);
  }
}

/*
 * File trailer for abs.c
 *
 * [EOF]
 */
