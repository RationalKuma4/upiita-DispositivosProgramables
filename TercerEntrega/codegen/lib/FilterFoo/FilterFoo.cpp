//
// File: FilterFoo.cpp
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 25-Nov-2018 00:03:20
//

// Include Files
#include <string.h>
#include "rt_nonfinite.h"
#include "FilterFoo.h"

// Function Definitions

//
// Arguments    : const double b_y1[8000]
//                double y[8000]
// Return Type  : void
//
void FilterFoo(const double b_y1[8000], double y[8000])
{
  int k;
  int j;
  memset(&y[0], 0, 8000U * sizeof(double));
  for (k = 0; k < 2; k++) {
    for (j = k; j + 1 < 8001; j++) {
      y[j] += (1.0 + -1.95 * (double)k) * b_y1[j - k];
    }
  }
}

//
// File trailer for FilterFoo.cpp
//
// [EOF]
//
