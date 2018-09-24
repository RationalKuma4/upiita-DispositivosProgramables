#include "dsk6713_aic23.h"
#include "rbfN60FIR.cof"    // Archivo de soporte para el códec DSK (poner la ruta)
#define N 61
Uint32 fs = DSK6713_AIC23_FREQ_16KHZ;          // Frecuencia de muestreo

#define N 55 //number of coefficients
float h[N] = { 1.7619E-017, 7.0567E-003, 2.2150E-018,-1.0962E-002, 4.0310E-017,
1.3946E-002, 7.1787E-018,-1.4588E-002, 3.9928E-017, 1.1474E-002,
5.9881E-018,-3.5159E-003,-6.6174E-018,-9.7476E-003,-1.7919E-017,
2.7932E-002,-9.4329E-017,-4.9740E-002, 3.3834E-017, 7.3066E-002,
-3.6228E-017,-9.5284E-002, 3.2194E-017, 1.1365E-001,-2.2165E-017,
-1.2576E-001, 7.8980E-018, 1.3000E-001, 7.8980E-018,-1.2576E-001,
-2.2165E-017, 1.1365E-001, 3.2194E-017,-9.5284E-002,-3.6228E-017,
7.3066E-002, 3.3834E-017,-4.9740E-002,-9.4329E-017, 2.7932E-002,
-1.7919E-017,-9.7476E-003,-6.6174E-018,-3.5159E-003, 5.9881E-018,
1.1474E-002, 3.9928E-017,-1.4588E-002, 7.1787E-018, 1.3946E-002,
4.0310E-017,-1.0962E-002, 2.2150E-018, 7.0567E-003, 1.7619E-017 };

#define N2 


//Rutina del servicio de interrupción
interrupt void c_int11() 
{
	float x[N];
	float yy;
	short y, xx;
	int k, m;
	//declaración de vectores y variables locales
	xx = input_sample(); //Lectura de una muestra del códec
	x[0] = (float)xx;

	// ************** coloque aquí la rutina de filtrado de filtrado FIR **************
	yy = 0;

	for (k = 0; k <= N - 1; k++) {
		yy = yy + h[k] * x[k];
	}
	for (m = N - 1; m > 0; m--) {
		x[m] = x[m - 1];
	}
	y = (short)yy;

	if (DSK6713_DIP_get(0) == 0) {
		output_sample(x[0]);    //Envío de la muestra filtrada hacia el códec
	}
	else if (DSK6713_DIP_get(1) == 0) {
		output_sample(y);  //Envío de la muestra filtrada hacia el códec
	}
	else {
		output_sample(0);
	}
	return;
}

void main() {
	comm_intr();    // Inicializar el codec, DSK y McBSP
	DSK6713_DIP_init();
	while (1);       // Bucle infinito a la espera de una interrupción
}


