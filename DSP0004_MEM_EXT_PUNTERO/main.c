/*//bucle_poll.c
#include "DSK6713_AIC23.h" //(Colocar la ruta en la versión 3.1)
Uint32 fs=DSK6713_AIC23_FREQ_8KHZ; //set sampling rate
void comm_poll();
void output_sample(int out_data);
Uint32 input_sample();


void main()
{
short sample_data;
comm_poll(); //init DSK, codec, McBSP
while(1) //infinite loop
{
sample_data = input_sample(); //input sample
output_sample(sample_data); //output sample
}
}*/


// DSP004_MEM_EXT_PUNTEROS.c
#include "dsk6713_aic23.h"            //Archivo de soporte del DSK (Colocar la ruta en la versión 3.1)
#include "dsk6713_dip.h"
#include "dsk6713_led.h"

#define lbuffer 3000                                                   //Definición del tamaño del buffer para introducir retardo
#define lbuffer2 6000
#define lbuffer3 9000

short entrada, salida;
short buffer[lbuffer];                         //Creación del buffer
short buffer2[lbuffer2];
short buffer3[lbuffer3];

short e = 0, j = 0, k = 0;
float amplitud = 0.5;                          //Parámetro para variar al ampilitud del eco
float amplitud2 = 0.25;                        //Parámetro para variar al ampilitud del eco
float amplitud3 = 0.125;

short lb=lbuffer;
short lb2=lbuffer2;
short lb3=lbuffer3;

Uint32 fs=DSK6713_AIC23_FREQ_8KHZ;      //Frecuencia de muestreo
#define N    40000                                                                     //Búffer
int i; short var, salida;
short* x_ptr= (short*) 0x80000000;
short* x_ptr2= (short*) 0x80400000;

#define LEFT  1                  //data structure for union of 32-bit data
#define RIGHT 0                  //into two 16-bit data
union {
    Uint32 uint;
    short channel[2];
    } AIC_data;

extern far void vectors();         //external function

static Uint32 CODECEventId, poll;

// This is needed to modify the BSL's data channel McBSP configuration
// See the changes below
MCBSP_Config AIC23CfgData = {
        MCBSP_FMKS(SPCR, FREE, NO)              |
        MCBSP_FMKS(SPCR, SOFT, NO)              |
        MCBSP_FMKS(SPCR, FRST, YES)             |
        MCBSP_FMKS(SPCR, GRST, YES)             |
        MCBSP_FMKS(SPCR, XINTM, XRDY)           |
        MCBSP_FMKS(SPCR, XSYNCERR, NO)          |
        MCBSP_FMKS(SPCR, XRST, YES)             |
        MCBSP_FMKS(SPCR, DLB, OFF)              |
        MCBSP_FMKS(SPCR, RJUST, RZF)            |
        MCBSP_FMKS(SPCR, CLKSTP, DISABLE)       |
        MCBSP_FMKS(SPCR, DXENA, OFF)            |
        MCBSP_FMKS(SPCR, RINTM, RRDY)           |
        MCBSP_FMKS(SPCR, RSYNCERR, NO)          |
        MCBSP_FMKS(SPCR, RRST, YES),

        MCBSP_FMKS(RCR, RPHASE, SINGLE)         |
        MCBSP_FMKS(RCR, RFRLEN2, DEFAULT)       |
        MCBSP_FMKS(RCR, RWDLEN2, DEFAULT)       |
        MCBSP_FMKS(RCR, RCOMPAND, MSB)          |
        MCBSP_FMKS(RCR, RFIG, NO)               |
        MCBSP_FMKS(RCR, RDATDLY, 0BIT)          |
        MCBSP_FMKS(RCR, RFRLEN1, OF(0))         | // This changes to 1 FRAME
        MCBSP_FMKS(RCR, RWDLEN1, 32BIT)         | // This changes to 32 bits per frame
        MCBSP_FMKS(RCR, RWDREVRS, DISABLE),

        MCBSP_FMKS(XCR, XPHASE, SINGLE)         |
        MCBSP_FMKS(XCR, XFRLEN2, DEFAULT)       |
        MCBSP_FMKS(XCR, XWDLEN2, DEFAULT)       |
        MCBSP_FMKS(XCR, XCOMPAND, MSB)          |
        MCBSP_FMKS(XCR, XFIG, NO)               |
        MCBSP_FMKS(XCR, XDATDLY, 0BIT)          |
        MCBSP_FMKS(XCR, XFRLEN1, OF(0))         | // This changes to 1 FRAME
        MCBSP_FMKS(XCR, XWDLEN1, 32BIT)         | // This changes to 32 bits per frame
        MCBSP_FMKS(XCR, XWDREVRS, DISABLE),

        MCBSP_FMKS(SRGR, GSYNC, DEFAULT)        |
        MCBSP_FMKS(SRGR, CLKSP, DEFAULT)        |
        MCBSP_FMKS(SRGR, CLKSM, DEFAULT)        |
        MCBSP_FMKS(SRGR, FSGM, DEFAULT)         |
        MCBSP_FMKS(SRGR, FPER, DEFAULT)         |
        MCBSP_FMKS(SRGR, FWID, DEFAULT)         |
        MCBSP_FMKS(SRGR, CLKGDV, DEFAULT),

        MCBSP_MCR_DEFAULT,
        MCBSP_RCER_DEFAULT,
        MCBSP_XCER_DEFAULT,

        MCBSP_FMKS(PCR, XIOEN, SP)              |
        MCBSP_FMKS(PCR, RIOEN, SP)              |
        MCBSP_FMKS(PCR, FSXM, EXTERNAL)         |
        MCBSP_FMKS(PCR, FSRM, EXTERNAL)         |
        MCBSP_FMKS(PCR, CLKXM, INPUT)           |
        MCBSP_FMKS(PCR, CLKRM, INPUT)           |
        MCBSP_FMKS(PCR, CLKSSTAT, DEFAULT)      |
        MCBSP_FMKS(PCR, DXSTAT, DEFAULT)        |
        MCBSP_FMKS(PCR, FSXP, ACTIVEHIGH)       |
        MCBSP_FMKS(PCR, FSRP, ACTIVEHIGH)       |
        MCBSP_FMKS(PCR, CLKXP, FALLING)         |
        MCBSP_FMKS(PCR, CLKRP, RISING)
    };


DSK6713_AIC23_Config config = { \
    0x0017, /* Set-Up Reg 0       Left line input channel volume control */  \
            /* LRS     0          simultaneous left/right volume: disabled */\
            /* LIM     0          left line input mute: disabled */          \
            /* XX      00         reserved */                                \
            /* LIV     10111      left line input volume: 0 dB */            \
                                                                             \
    0x0017, /* Set-Up Reg 1       Right line input channel volume control */ \
            /* RLS     0          simultaneous right/left volume: disabled */\
            /* RIM     0          right line input mute: disabled */         \
            /* XX      00         reserved */                                \
            /* RIV     10111      right line input volume: 0 dB */           \
                                                                             \
    0x01f9, /* Set-Up Reg 2       Left channel headphone volume control */   \
            /* LRS     1          simultaneous left/right volume: enabled */ \
            /* LZC     1          left channel zero-cross detect: enabled */ \
            /* LHV     1111001    left headphone volume: 0 dB */             \
                                                                             \
    0x01f9, /* Set-Up Reg 3       Right channel headphone volume control */  \
            /* RLS     1          simultaneous right/left volume: enabled */ \
            /* RZC     1          right channel zero-cross detect: enabled */\
            /* RHV     1111001    right headphone volume: 0 dB */            \
                                                                             \
    0x0015, /* Set-Up Reg 4       Analog audio path control */               \
            /* X       0          reserved */                                \
            /* STA     00         sidetone attenuation: -6 dB */             \
            /* STE     0          sidetone: disabled */                      \
            /* DAC     1          DAC: selected */                           \
            /* BYP     0          bypass: off */                             \
            /* INSEL   0          input select for ADC: line */              \
            /* MICM    0          microphone mute: disabled */               \
            /* MICB    1          microphone boost: enabled */               \
                                                                             \
    0x0000, /* Set-Up Reg 5       Digital audio path control */              \
            /* XXXXX   00000      reserved */                                \
            /* DACM    0          DAC soft mute: disabled */                 \
            /* DEEMP   00         deemphasis control: disabled */            \
            /* ADCHP   0          ADC high-pass filter: disabled */          \
                                                                             \
    0x0000, /* Set-Up Reg 6       Power down control */                      \
            /* X       0          reserved */                                \
            /* OFF     0          device power: on (i.e. not off) */         \
            /* CLK     0          clock: on */                               \
            /* OSC     0          oscillator: on */                          \
            /* OUT     0          outputs: on */                             \
            /* DAC     0          DAC: on */                                 \
            /* ADC     0          ADC: on */                                 \
            /* MIC     0          microphone: on */                          \
            /* LINE    0          line input: on */                          \
                                                                             \
    0x0043, /* Set-Up Reg 7       Digital audio interface format */          \
            /* XX      00         reserved */                                \
            /* MS      1          master/slave mode: master */               \
            /* LRSWAP  0          DAC left/right swap: disabled */           \
            /* LRP     0          DAC lrp: MSB on 1st BCLK */                \
            /* IWL     00         input bit length: 16 bit */                \
            /* FOR     11         data format: DSP format */                 \
                                                                             \
    0x0081, /* Set-Up Reg 8       Sample rate control */                     \
            /* X       0          reserved */                                \
            /* CLKOUT  1          clock output divider: 2 (MCLK/2) */        \
            /* CLKIN   0          clock input divider: 2 (MCLK/2) */         \
            /* SR,BOSR 00000      sampling rate: ADC  48 kHz DAC  48 kHz */  \
            /* USB/N   1          clock mode select (USB/normal): USB */     \
                                                                             \
    0x0001  /* Set-Up Reg 9       Digital interface activation */            \
            /* XX..X   00000000   reserved */                                \
            /* ACT     1          active */                                  \
};

DSK6713_AIC23_CodecHandle hAIC23_handle;

void c6713_dsk_init();
void output_sample(int);
Uint32 input_sample();

Uint32 DSK6713_DIP_get(Uint32 dipNum);
void DSK6713_LED_init();
void DSK6713_LED_off(Uint32 ledNum);
void DSK6713_LED_on(Uint32 ledNum);
void DSK6713_LED_toggle(Uint32 ledNum);

void main()
{
    poll=1;                             //1 if using polling
       c6713_dsk_init();

       //DSK, CODEC y McBSP
 DSK6713_DIP_init();
 DSK6713_LED_init();
 short lb3=lbuffer3;
 while(1)                                                                            //Bucle infinito
 {
     if(DSK6713_DIP_get(0) == 0)                                     //Verificar si el switch No. 0 está presionado
     {
         DSK6713_LED_on(0);                              //Encender LED No. 0
         for (i = 0; i<N; i++)
         {
             //*(x_ptr+i) = input_sample();
             short CHANNEL_data;

                 if (poll) while(!MCBSP_rrdy(DSK6713_AIC23_DATAHANDLE));//if ready to receive
                      AIC_data.uint=MCBSP_read(DSK6713_AIC23_DATAHANDLE);//read data

             //Swapping left and right channels (see comments in output_sample())
                 CHANNEL_data=AIC_data.channel[RIGHT];           //swap left and right channel
                 AIC_data.channel[RIGHT]=AIC_data.channel[LEFT];
                 AIC_data.channel[LEFT]=CHANNEL_data;
                 AIC_data.uint=*(x_ptr+i);

         }                  //Lectura de una muestra de entrada
         DSK6713_LED_off(0);
         var=0;
     }
     else if(DSK6713_DIP_get(1) == 0)                                     //Verificar si el switch No. 0 está presionado
     {
         DSK6713_LED_on(1);                                            //encender el  LED No. 1
          for (i = 0; i<N; i++)
          {
              salida=*(x_ptr+i);
          //output_sample(salida);
          short CHANNEL_data;

              AIC_data.uint=0;                 //clear data structure
              AIC_data.uint=salida;          //32-bit data -->data structure

          //The existing interface defaults to right channel. To default instead to the
          //left channel and use output_sample(short), left and right channels are swapped
          //In main source program use LEFT 0 and RIGHT 1 (opposite of what is used here)
              CHANNEL_data=AIC_data.channel[RIGHT];           //swap left and right channels
              AIC_data.channel[RIGHT]=AIC_data.channel[LEFT];
              AIC_data.channel[LEFT]=CHANNEL_data;
             if (poll) while(!MCBSP_xrdy(DSK6713_AIC23_DATAHANDLE));//if ready to transmit
                  MCBSP_write(DSK6713_AIC23_DATAHANDLE,AIC_data.uint);//write/output data
          }                              //Reproducción
          var=1;
          DSK6713_LED_off(1);
     }
     else if(DSK6713_DIP_get(2) == 0)                                     //Verificar si el switch No. 0 está presionado
     {
         DSK6713_LED_on(2);                              //Encender LED No. 0
      for (i = 0; i<N; i++)
      {
          short CHANNEL_data;

                           if (poll) while(!MCBSP_rrdy(DSK6713_AIC23_DATAHANDLE));//if ready to receive
                                AIC_data.uint=MCBSP_read(DSK6713_AIC23_DATAHANDLE);//read data

                       //Swapping left and right channels (see comments in output_sample())
                           CHANNEL_data=AIC_data.channel[RIGHT];           //swap left and right channel
                           AIC_data.channel[RIGHT]=AIC_data.channel[LEFT];
                           AIC_data.channel[LEFT]=CHANNEL_data;
                           AIC_data.uint=*(x_ptr2+i);

      }                  //Lectura de una muestra de entrada
      DSK6713_LED_off(2);
      var=0;
     }
     else if(DSK6713_DIP_get(3) == 0)
     {
         DSK6713_LED_on(3);                                            //encender el  LED No. 1
       for (i = 0; i<N; i++)
       {
           salida=*(x_ptr2+i)+buffer3[e]*amplitud3+buffer2[j]*amplitud2+buffer[k]*amplitud;
           buffer3[e] =*(x_ptr2+i);
           buffer2[j] =*(x_ptr2+i);
           buffer[j] =*(x_ptr2+i);
           //output_sample(salida);
           short CHANNEL_data;

            AIC_data.uint=0;                 //clear data structure
            AIC_data.uint=salida;          //32-bit data -->data structure

        //The existing interface defaults to right channel. To default instead to the
        //left channel and use output_sample(short), left and right channels are swapped
        //In main source program use LEFT 0 and RIGHT 1 (opposite of what is used here)
            CHANNEL_data=AIC_data.channel[RIGHT];           //swap left and right channels
            AIC_data.channel[RIGHT]=AIC_data.channel[LEFT];
            AIC_data.channel[LEFT]=CHANNEL_data;
           if (poll) while(!MCBSP_xrdy(DSK6713_AIC23_DATAHANDLE));//if ready to transmit
                MCBSP_write(DSK6713_AIC23_DATAHANDLE,AIC_data.uint);//write/output data
            k++;e++;j++;
            if (e >= lb) e = 0;
            if (j >= lb2) j = 0;
            if (k >= lb3) k = 0;
            //Reproducción
             //var=1;
             //DSK6713_LED_off(3);
       }                              //Reproducción
           var=1;
           DSK6713_LED_off(3);
     }
 }
}
