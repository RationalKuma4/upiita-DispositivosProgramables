/*
 * File: main.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 25-Nov-2018 12:09:16
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include Files */
#include "rt_nonfinite.h"
#include "MatrizFreMel.h"
#include "main.h"
#include "MatrizFreMel_terminate.h"
#include "MatrizFreMel_initialize.h"

/* Function Declarations */
static void argInit_1x400_real_T(double result[400]);
static void argInit_1x8000_real_T(double result[8000]);
static void argInit_21x128_real_T(double result[2688]);
static double argInit_real_T(void);
static void main_MatrizFreMel(void);

/* Function Definitions */

/*
 * Arguments    : double result[400]
 * Return Type  : void
 */
static void argInit_1x400_real_T(double result[400])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 400; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

/*
 * Arguments    : double result[8000]
 * Return Type  : void
 */
static void argInit_1x8000_real_T(double result[8000])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 8000; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

/*
 * Arguments    : double result[2688]
 * Return Type  : void
 */
static void argInit_21x128_real_T(double result[2688])
{
  int idx0;
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 21; idx0++) {
    for (idx1 = 0; idx1 < 128; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[idx0 + 21 * idx1] = argInit_real_T();
    }
  }
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_MatrizFreMel(void)
{
  double dv2[8000];
  double dv3[2688];
  double dv4[400];
  double mfcc[1250];

  /* Initialize function 'MatrizFreMel' input arguments. */
  /* Initialize function input argument 'y'. */
  /* Initialize function input argument 'Hm'. */
  /* Initialize function input argument 'W'. */
  /* Call the entry-point 'MatrizFreMel'. */
  argInit_1x8000_real_T(dv2);
  argInit_21x128_real_T(dv3);
  argInit_1x400_real_T(dv4);
  MatrizFreMel(dv2, dv3, dv4, mfcc);
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  MatrizFreMel_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_MatrizFreMel();

  /* Terminate the application.
     You do not need to do this more than one time. */
  MatrizFreMel_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
