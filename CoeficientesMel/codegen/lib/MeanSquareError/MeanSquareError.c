/*
 * File: MeanSquareError.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 25-Nov-2018 13:22:46
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "MeanSquareError.h"
#include "power.h"
#include "abs.h"

/* Function Definitions */

/*
 * Arguments    : const double referencia[1250]
 *                const double aproximacion[1250]
 * Return Type  : double
 */
double MeanSquareError(const double referencia[1250], const double aproximacion
  [1250])
{
  int k;
  double b_referencia[1250];
  double dv0[1250];
  double D[1250];
  double y;
  for (k = 0; k < 1250; k++) {
    b_referencia[k] = referencia[k] - aproximacion[k];
  }

  b_abs(b_referencia, dv0);
  power(dv0, D);
  y = D[0];
  for (k = 0; k < 1249; k++) {
    y += D[k + 1];
  }

  return y / 1250.0;
}

/*
 * File trailer for MeanSquareError.c
 *
 * [EOF]
 */
