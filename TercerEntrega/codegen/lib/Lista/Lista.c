/*
 * File: Lista.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-Nov-2018 17:00:33
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "Lista.h"
#include "Lista_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : double a
 *                double b
 *                double d
 *                emxArray_real_T *vector
 * Return Type  : void
 */
void Lista(double a, double b, double d, emxArray_real_T *vector)
{
  int k;
  double ndbl;
  double apnd;
  double cdiff;
  int nm1d2;
  double absa;
  double absb;
  int n;
  if (rtIsNaN(a) || rtIsNaN(d) || rtIsNaN(b)) {
    k = vector->size[0] * vector->size[1];
    vector->size[0] = 1;
    vector->size[1] = 1;
    emxEnsureCapacity_real_T(vector, k);
    vector->data[0] = rtNaN;
  } else if ((d == 0.0) || ((a < b) && (d < 0.0)) || ((b < a) && (d > 0.0))) {
    k = vector->size[0] * vector->size[1];
    vector->size[0] = 1;
    vector->size[1] = 0;
    emxEnsureCapacity_real_T(vector, k);
  } else if ((rtIsInf(a) || rtIsInf(b)) && (rtIsInf(d) || (a == b))) {
    k = vector->size[0] * vector->size[1];
    vector->size[0] = 1;
    vector->size[1] = 1;
    emxEnsureCapacity_real_T(vector, k);
    vector->data[0] = rtNaN;
  } else if (rtIsInf(d)) {
    k = vector->size[0] * vector->size[1];
    vector->size[0] = 1;
    vector->size[1] = 1;
    emxEnsureCapacity_real_T(vector, k);
    vector->data[0] = a;
  } else if ((floor(a) == a) && (floor(d) == d)) {
    k = vector->size[0] * vector->size[1];
    vector->size[0] = 1;
    vector->size[1] = (int)floor((b - a) / d) + 1;
    emxEnsureCapacity_real_T(vector, k);
    nm1d2 = (int)floor((b - a) / d);
    for (k = 0; k <= nm1d2; k++) {
      vector->data[vector->size[0] * k] = a + d * (double)k;
    }
  } else {
    ndbl = floor((b - a) / d + 0.5);
    apnd = a + ndbl * d;
    if (d > 0.0) {
      cdiff = apnd - b;
    } else {
      cdiff = b - apnd;
    }

    absa = fabs(a);
    absb = fabs(b);
    if ((absa > absb) || rtIsNaN(absb)) {
      absb = absa;
    }

    if (fabs(cdiff) < 4.4408920985006262E-16 * absb) {
      ndbl++;
      apnd = b;
    } else if (cdiff > 0.0) {
      apnd = a + (ndbl - 1.0) * d;
    } else {
      ndbl++;
    }

    if (ndbl >= 0.0) {
      n = (int)ndbl;
    } else {
      n = 0;
    }

    k = vector->size[0] * vector->size[1];
    vector->size[0] = 1;
    vector->size[1] = n;
    emxEnsureCapacity_real_T(vector, k);
    if (n > 0) {
      vector->data[0] = a;
      if (n > 1) {
        vector->data[n - 1] = apnd;
        nm1d2 = (n - 1) / 2;
        for (k = 1; k < nm1d2; k++) {
          ndbl = (double)k * d;
          vector->data[k] = a + ndbl;
          vector->data[(n - k) - 1] = apnd - ndbl;
        }

        if (nm1d2 << 1 == n - 1) {
          vector->data[nm1d2] = (a + apnd) / 2.0;
        } else {
          ndbl = (double)nm1d2 * d;
          vector->data[nm1d2] = a + ndbl;
          vector->data[nm1d2 + 1] = apnd - ndbl;
        }
      }
    }
  }
}

/*
 * File trailer for Lista.c
 *
 * [EOF]
 */
