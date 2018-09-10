//signal.c
#include "dsk6713_aic23.h"               //Archivo de soporte para el códec y el DSK
#include "dsk6713_dip.h"
#include "dsk6713.h"
//#include "C6713dskinit.h"
Uint32 fs=DSK6713_AIC23_FREQ_96KHZ;       //Tasa de muestreo
int loop = 0;
short gain = 10;

short diente[8]={0,143,286,429,572,715,858,1001};// Valores de un periodo del diente de sierra
short pulso[8]={0,1000,1000,1000,1000,1000,1000,0};
short signal1[8]={0,707,1000,707,0,-707,-1000,-707};   // Valores de un periodo de una sinusoidal
short signal2[4]={0,1000,0,-1000};
short signal3[2]={707,-707};

//Arreglo de puntos para las señales
int loopSin=0;
short signaSin[24]={0,2588,5000,7071,8660,9659,1000,9659,8660,7071,5000,2588,0,-2588,-5000,-7071,-8660,-9659,-1000,-9659,-8660,-7071,-5000,-2588};
short signalSum1[96];
short signalSum2[48];
short signalSum3[12];

short buffer[256];                                           //Buffer de salida
const short Lbuffer= 256;                                            //Tamaño del buffer de salida
int i = 0;

#define using_bios                  //if BIOS don't use top of vector table
extern Uint32 fs;                       //for sampling frequency

interrupt void c_int11();
void c6713_dsk_init();
void comm_poll();
void comm_intr();
void output_sample(int out_data);

interrupt void c_int11()                        //Rutina del servicio de interrupción
{
    if(DSK6713_DIP_get(0)==0)
    {
        output_sample(gain*signaSin[loop]);                            //Valores de salida de la señal diente de sierra
        buffer[i] = signaSin[loop];                            //Salida al buffer
        i++;

    //incremento de la cuenta en el buffer
        if(i==Lbuffer) i=0;
        if (loop < 25) ++loop;
        else loop = 0;                                   //Reinicio de la tabla que contiene un periodo de la señal
        return;                                                 //Retorno de la interrupción
    }
    else if(DSK6713_DIP_get(1)==0)
    {
        output_sample(gain*signal1[loop]);                            //Valores de salida de la señal diente de sierra
        buffer[i] = signal1[loop];                            //Salida al buffer
        i++;

        //incremento de la cuenta en el buffer
        if(i==Lbuffer) i=0;
        if (loop < 3) ++loop;
        else loop = 0;                                   //Reinicio de la tabla que contiene un periodo de la señal
        return;                                                 //Retorno de la interrupción
    }
    else if(DSK6713_DIP_get(2)==0)
    {
        output_sample(gain*signal2[loop]);                            //Valores de salida de la señal diente de sierra
        buffer[i] = signal2[loop];                            //Salida al buffer
        i++;

        //incremento de la cuenta en el buffer
        if(i==Lbuffer) i=0;
        if (loop < 1) ++loop;
        else loop = 0;                                   //Reinicio de la tabla que contiene un periodo de la señal
        return;                                                 //Retorno de la interrupción
    }
    else if(DSK6713_DIP_get(3)==0)
    {
        output_sample(gain*signal3[loop]);                            //Valores de salida de la señal diente de sierra
        buffer[i] = signal3[loop];                            //Salida al buffer
        i++;

        //incremento de la cuenta en el buffer
        if(i==Lbuffer) i=0;
        if (loop < 1) ++loop;
        else loop = 0;                                   //Reinicio de la tabla que contiene un periodo de la señal
        return;                                                 //Retorno de la interrupción
    }
    else output_sample(0);
}

void main()
{
  DSK6713_init();
  DSK6713_DIP_init();
  comm_intr();                               //Inicialización del DSK, codec y McBSP
  while(1);                                  //Bucle infinito
}
