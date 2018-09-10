//DSP04_codec_melod.c
#include "dsk6713.h"
#include "dsk6713_aic23.h"
Uint32 fs=DSK6713_AIC23_FREQ_16KHZ;
#include "math.h"
#include "dsk6713_dip.h"

/*Frecuencias de Notas*/
#define fdo 523
#define fre 587
#define fmi 659
#define ffa 698
#define fsol 783
#define fla 880
#define fsi 987
#define fdo6 1046
#define fre6 1174

/* Cadencia */
#define c 0.5 //corchea
#define n 1.0 //negra
#define b 2.0 //blanca
#define r 4.0 //redonda

//Define la frecuencia de muestreo con la cual fue creada la partitura
#define Fmuestreo 16000
#define Fmuestreo2 16000


//Define el tama�o del vector con la partitura y cadencia
#define N 110
#define N2 160

// Define partitura, los elementos del arreglo son frecuencia y cadencia
float partitura[N]={fsi,n,fdo6,n,fre6,n,fre6,n,fdo6,n,fsi,n,fla,n,fsol,n,
fsol,n,fla,n,fsi,n,fsi,b,fla,b,fsi,b,fdo6,n,fre6,n,fre6,n,fdo6,n,
fsi,n,fla,n,fsol,n,fsol,n,fla,n,fsi,n,fla,b,fsol,b,fla,b,fsi,n,fsol,n,
fla,n,fsi,c,fdo6,c,fsi,n,fsol,n,fla,n,fsi,c,fdo6,c,fsi,n,fla,n,fsol,n,
fla,n,fre,b,fsi,b,fdo6,n,fre6,n,fre6,n,fdo6,n,fsi,n,fla,n,fsol,n,fsol,n,
fla,n,fsi,n,fla,b,fsol,b};
float partitura2[N2] = {fsol,n,fmi,n,fmi,n,fmi,n,fsol,n,fmi,n,fmi,n,fmi,n,fre6,c,
        fdo6,c,fsi,c,fla,c,fsol,c,ffa,n,fmi,n,ffa,n,fsol,b,fsol,n,fmi,n,fmi,n,
        fmi,n,fsol,n,fmi,n,fmi,n,fmi,n,fre6,c,fdo6,c,fsi,c,fla,c,fsol,n,fsol,
        n,fla,r,fdo6,n,fla,n,fla,n,fla,n,fre6,n,fsi,n,fsi,n,fsi,n,fre6,n,fsi,n,
        fre6,n,fsi,n,fmi,n,fdo6,n,fmi,n,fdo6,n,fsol,n,fmi,n,fmi,n,fmi,n,fsol,n,
        fmi,n,fmi,n,fmi,n,fre6,c,fdo6,c,fsi,c,fla,c,fsol,n,ffa,n,fmi,n,ffa,n,fsol,
        b,fsol,n,fmi,n,fmi,n,fmi,n,fsol,n,fmi,n,fmi,n,fmi,n,fre6,c,fdo6,c,fsi,c,fla,
        c,fsol,n,fsi,n,fdo6,n};

/* Configuraci�n del Codec */
DSK6713_AIC23_Config config1 = {
0x0017, /* 0 DSK6713_AIC23_LEFTINVOL   Volumen del canal izquierdo entrada*/
0x0017, /* 1 DSK6713_AIC23_RIGHTINVOL  Volumen del canal derecho entrada */
0x00d8, /* 2 DSK6713_AIC23_LEFTHPVOL   Volumen del canal izquierdo headphone */
0x00d8, /* 3 DSK6713_AIC23_RIGHTHPVOL  Volumen del canal derecho headphone */
0x0015, /* 4 DSK6713_AIC23_ANAPATH     Control de audio analogico */
0x0000, /* 5 DSK6713_AIC23_DIGPATH     Control de audio digital */
0x0000, /* 6 DSK6713_AIC23_POWERDOWN   Control power down */
0x0043, /* 7 DSK6713_AIC23_DIGIF       Formato de audio digital */
0x0081, /* 8 DSK6713_AIC23_SAMPLERATE  Tasa de muestreo 48K[Hz] */
0x0001  /* 9 DSK6713_AIC23_DIGACT      Activaci�n de la interface digital */
};

void main()  /* main() Rutina principal, Inicializa BSL y sintetiza la melod�a */
{
    //DSK6713_AIC23_Config config1 = DSK6713_AIC23_DEFAULTCONFIG;
    DSK6713_AIC23_CodecHandle hCodec;
    Int16 fseno,buffindex;
    float nota,duracion,sample;
    float pi=3.141592;
    DSK6713_DIP_init();
    DSK6713_init(); //Inicializaci�n de la tarjeta
    hCodec = DSK6713_AIC23_openCodec(0, &config1); //Apertura del c�dec
    DSK6713_AIC23_setFreq(hCodec, fs); //Ajuste de la frecuencia de muestreo del c�dec


    while(1)
    {
        if(DSK6713_DIP_get(0)==0)
        {
            for (buffindex=0;buffindex<N;buffindex=buffindex+2)
            {
                nota=partitura[buffindex];
                duracion=partitura[buffindex+1];
                for (sample = 0.0; sample <(duracion/2.0); sample=(Fmuestreo*sample+1)/Fmuestreo)
                {
                    fseno=(Int16)(32000*sin(2*pi*nota*sample));
                    while (!DSK6713_AIC23_write(hCodec, fseno));
                    //while(DSK6713_DIP_get(0) != 0);
                    if(DSK6713_DIP_get(0)!=0) break;
                }
            }
        }

        if(DSK6713_DIP_get(2)==0)
        {
            for (buffindex=0;buffindex<N2;buffindex=buffindex+2)
            {
                nota=partitura2[buffindex];
                duracion=partitura2[buffindex+1];
                for (sample = 0.0; sample <(duracion/2.0); sample=(Fmuestreo2*sample+1)/Fmuestreo2)
                {
                    fseno=(Int16)(32000*sin(2*pi*nota*sample));
                    while (!DSK6713_AIC23_write(hCodec, fseno));
                    //while(DSK6713_DIP_get(3) != 0);
                    if(DSK6713_DIP_get(2)!=0) break;
                }
            }
        }
    }


    /*for (buffindex=0;buffindex<N;buffindex=buffindex+2)
    {
        nota=partitura[buffindex];
        duracion=partitura[buffindex+1];
        for (sample = 0.0; sample <(duracion/2.0); sample=(Fmuestreo*sample+1)/Fmuestreo)
        {
            fseno=(Int16)(32000*sin(2*pi*nota*sample));
            while (!DSK6713_AIC23_write(hCodec, fseno));
            while(DSK6713_DIP_get(0) != 0);
        }

    }*/
    /* Cierra el codec*/
    DSK6713_AIC23_closeCodec(hCodec);
}
