#include "DSK6713_AIC23.h"
#include "dsk6713_dip.h"//codec-DSK support file
Uint32 fs = DSK6713_AIC23_FREQ_16KHZ;            //Frecuencia de muestreo

/*
#define Ne 6
#define N 3
float b[Ne][N] = { {1,-1.99914804389258,1},
                      {1,-1.99926018529716,1},
                      {1,-1.99945443478861,1},
                      {1,-1.99967875825679,1},
                      {1,-1.99987304841267,1},
                      {1,-1.99998523048168,1} };

float a[Ne][N] = { {1,-1.99353170732709,0.994782051310284},
                      {1,-1.98364523594624,0.984778043799358},
                      {1,-1.97495673078320,0.975892597769768},
                      {1,-1.96798361550478,0.968695305624949},
                      {1,-1.96311767303749,0.963636815166480},
                      {1,-1.96061976369558,0.961028242171139} };

float g[Ne] = { 0.997290851667332,0.992289347498589,0.987847065886572,0.984248775730549,0.981719779772080,0.980415621533300 };
 */

#define Ne 4
#define N 3
float b[Ne][N] = { {1,-1.969764956633425,1.000000003676001},
                   {1,-1.979764999303365,0.999999994750031},
                   {1,-1.960019792114779,0.999999998827065},
                   {1,-1.984715861685223,1.000000002746909} };

float a[Ne][N] = { {1,-1.814077964019558,0.849639518724675},
                   {1,-1.885288847122274,0.900392317840065},
                   {1,-1.862171393621124,0.923644847654413},
                   {1,-1.960252165528534,0.969624381004846} };

float g[Ne] = { 0.827727743325657,1,1,1 };

float u[N][Ne];
float temp1, temp2, y, x;
short yn, xx, ye;
/*
interrupt void c_int11()                                         //ISR
{
    short k, m, e;

    xx = input_sample();
    x = (float)xx;
    //============================================
    //Coloque la rutina de filtrado IIR en forma directa II con estructura en cascada
    for (e = 0; e < Ne; e++)
    {
        temp1 = 0;
        temp2 = 0;

        for (k = 1; k < N; k++)
        {
            temp1 = temp1 - a[e][k] * u[e][k];
            temp2 = temp2 + b[e][k] * u[e][k];
        }
        u[e][0] = g[e] * x + temp1;
        ye = u[e][0] * b[e][0] + temp2;

        for (m = 2; m > 0; m--)
        {
            u[e][m] = u[e][m - 1];
        }
        x = ye;
    }
    //============================================
    //yn = (short)x;

    if (DSK6713_DIP_get(0) == 0)
    {
        output_sample(xx);    //Envío de la muestra filtrada hacia el códec
    }
    else if (DSK6713_DIP_get(1) == 0)
    {
        output_sample(ye);  //Envío de la muestra filtrada hacia el códec
    }
    else
    {
        output_sample(0);
    }                                                         //Retorno de la ISR
}*/

void main()
{
    comm_poll();
    memset(u, 0, sizeof(u));
    DSK6713_DIP_init();
    //comm_intr();                                                  //init DSK, codec, McBSP
    while (1){
        short k, m, e;

            xx = input_sample();
            x = (float)xx;
            //============================================
            //Coloque la rutina de filtrado IIR en forma directa II con estructura en cascada
            for (e = 0; e < Ne; e++)
            {
                temp1 = 0;
                temp2 = 0;

                for (k = 1; k < N; k++)
                {
                    temp1 = temp1 - a[e][k] * u[e][k];
                    temp2 = temp2 + b[e][k] * u[e][k];
                }
                u[e][0] = g[e] * x + temp1;
                ye = u[e][0] * b[e][0] + temp2;

                for (m = 2; m > 0; m--)
                {
                    u[e][m] = u[e][m - 1];
                }
                x = ye;
            }
            //============================================
            //yn = (short)x;

            if (DSK6713_DIP_get(0) == 0)
            {
                output_sample(xx);    //Envío de la muestra filtrada hacia el códec
            }
            else if (DSK6713_DIP_get(1) == 0)
            {
                output_sample(ye);  //Envío de la muestra filtrada hacia el códec
            }
            else
            {
                output_sample(0);
            }

    };                                                          //infinite loop
}
