/*
 * File: MatrizFreMel.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 25-Nov-2018 12:09:16
 */

/* Include Files */
#include <math.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "MatrizFreMel.h"
#include "log.h"
#include "sum.h"
#include "fft.h"
#include "padarray.h"

/* Function Definitions */

/*
 * Arguments    : const double y[8000]
 *                const double Hm[2688]
 *                const double W[400]
 *                double mfcc[1250]
 * Return Type  : void
 */
void MatrizFreMel(const double y[8000], const double Hm[2688], const double W
                  [400], double mfcc[1250])
{
  double n;
  double ntrama;
  double energia[1008];
  double tramaEspecFil[2688];
  double MFCC[1008];
  int l;
  double tramaVoz[400];
  creal_T tramaEspectral[256];
  int k;
  double b_tramaEspecFil[128];
  double temp;
  double d0;

  /* Tamaño de ventana */
  /* Número de puntos de la FFTNFFT=256; %Número de puntos de la FFT */
  /* Traslape */
  /* Rutina para entramado, FFT, energía, MFCC */
  n = 0.0;
  ntrama = 0.0;
  memset(&energia[0], 0, 1008U * sizeof(double));
  memset(&tramaEspecFil[0], 0, 2688U * sizeof(double));
  memset(&MFCC[0], 0, 1008U * sizeof(double));
  while (n + 400.0 < 8000.0) {
    /* Entramado */
    /* Ventaneo */
    for (l = 0; l < 400; l++) {
      tramaVoz[l] = y[(int)(n + (1.0 + (double)l)) - 1] * W[l];
    }

    fft(tramaVoz, tramaEspectral);

    /* T. de Fourier de la trama */
    /* Solo consideramos la mitad de puntos del espectro ya que es simétrico */
    for (k = 0; k < 20; k++) {
      for (l = 0; l < 128; l++) {
        tramaEspecFil[(k + 21 * l) + 1] = tramaEspectral[l].re * Hm[(k + 21 * l)
          + 1];
      }

      /* Filtrado en frecuencia */
      for (l = 0; l < 128; l++) {
        b_tramaEspecFil[l] = tramaEspecFil[(k + 21 * l) + 1] * tramaEspecFil[(k
          + 21 * l) + 1];
      }

      energia[((int)(ntrama + 1.0) + 48 * (k + 1)) - 1] = sum(b_tramaEspecFil);

      /* Obtención de la energía en cada banda */
      temp = 0.0;
      for (l = 0; l < 20; l++) {
        d0 = energia[((int)(ntrama + 1.0) + 48 * (k + 1)) - 1];
        b_log(&d0);
        temp += d0 * cos((1.0 + (double)l) * ((2.0 + (double)k) - 0.5) *
                         3.1415926535897931 / 20.0);

        /* Obtención de los coeficientes cepstrales */
      }

      /* usando la DCT */
      MFCC[((int)(ntrama + 1.0) + 48 * (k + 1)) - 1] = temp;
    }

    n += 160.0;
    ntrama++;
  }

  padarray(MFCC, mfcc);
}

/*
 * File trailer for MatrizFreMel.c
 *
 * [EOF]
 */
