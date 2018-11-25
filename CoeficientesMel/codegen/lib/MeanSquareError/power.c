/*
 * File: power.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 25-Nov-2018 13:22:46
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "MeanSquareError.h"
#include "power.h"

/* Function Definitions */

/*
 * Arguments    : const double a[1250]
 *                double y[1250]
 * Return Type  : void
 */
void power(const double a[1250], double y[1250])
{
  int k;
  for (k = 0; k < 1250; k++) {
    y[k] = a[k] * a[k];
  }
}

/*
 * File trailer for power.c
 *
 * [EOF]
 */
