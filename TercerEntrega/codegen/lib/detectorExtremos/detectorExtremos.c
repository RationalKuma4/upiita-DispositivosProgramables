/*
 * File: detectorExtremos.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 25-Nov-2018 00:34:53
 */

/* Include Files */
#include <math.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "detectorExtremos.h"

/* Function Definitions */

/*
 * Arguments    : const double Y[8000]
 *                double palabradelimitada[4000]
 * Return Type  : void
 */
void detectorExtremos(const double Y[8000], double palabradelimitada[4000])
{
  double m;
  double n;
  double longPal;
  int t;
  int j;
  double umbral;
  int i0;
  int k;
  double b_k;
  int loop_ub;
  double Y_data[8000];

  /* numero de veces que calculara el umbral(nºtramas) */
  m = 2.0;

  /* factor de índice de inicio, empieza por 2 porque necesitaremos dato(x-1) */
  n = 1026.0;

  /*  factor de índice final */
  /* esto contara las ventanas consecutivas sin info. para detectar final pronunciación. */
  longPal = 1.0;
  t = 0;
  memset(&palabradelimitada[0], 0, 4000U * sizeof(double));
  for (j = 0; j < 7; j++) {
    /* esto segmentara la señal en tramas */
    umbral = 0.0;
    i0 = (int)(n + (1.0 - m));
    for (k = 0; k < i0; k++) {
      b_k = m + (double)k;

      /* bucle recorre muestras de n a m y calcula el umbral de la trama */
      umbral += fabs(Y[(int)b_k - 1] * fabs(Y[(int)b_k - 1]) - Y[(int)b_k - 2] *
                     fabs(Y[(int)b_k - 2]));
    }

    /* evolucionUmbral(n)=umbral; %se almacena el valor cada 1024 posiciones */
    /* =DETECTOR INICIO=> si supera umbral se empieza a almacenar tramas */
    if (umbral > 0.75) {
      /* comprobamos si se detecta inicio, si supera Umbral Inicio=1.25 */
      t = 0;
      longPal += 1024.0;
      if (m > n) {
        i0 = 0;
        k = 0;
      } else {
        i0 = (int)m - 1;
        k = (int)n;
      }

      loop_ub = k - i0;
      for (k = 0; k < loop_ub; k++) {
        Y_data[k] = Y[i0 + k];
      }

      for (i0 = 0; i0 < 1025; i0++) {
        palabradelimitada[(int)(longPal + (-1024.0 + (double)i0)) - 1] =
          Y_data[i0];
      }

      /* almacenamos tramas si t<15 */
    }

    /* =DETECTOR FIN=> se detecta final si transcurren 15 tramas sin info (t=15) */
    if ((umbral < 0.3) && (t < 0.1) && (longPal != 1.0)) {
      /* comprobamos si incrementamos t, */
      t++;
      longPal += 1024.0;
      if (m > n) {
        i0 = 0;
        k = 0;
      } else {
        i0 = (int)m - 1;
        k = (int)n;
      }

      loop_ub = k - i0;
      for (k = 0; k < loop_ub; k++) {
        Y_data[k] = Y[i0 + k];
      }

      for (i0 = 0; i0 < 1025; i0++) {
        palabradelimitada[(int)(longPal + (-1024.0 + (double)i0)) - 1] =
          Y_data[i0];
      }

      /* almacenamos tramas si t<15 */
    }

    m += 1024.0;
    n += 1024.0;
  }
}

/*
 * File trailer for detectorExtremos.c
 *
 * [EOF]
 */
