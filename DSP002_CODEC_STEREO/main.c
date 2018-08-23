//#include "dsk6713_aic23.h"
#include "dsk6713_dip.h"
#include "dsk6713.h"//códec del DSK

/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk6713_aic23.h ========
 *
 *  Codec interface for AIC23 on the DSK6713 board
 */
#ifndef DSK6713_AIC23_
#define DSK6713_AIC23_

#ifdef __cplusplus
extern "C" {
#endif

#include <csl.h>
#include <csl_mcbsp.h>

/* AIC23 McBSP defines */
#define DSK6713_AIC23_CONTROLHANDLE  DSK6713_AIC23_codeccontrolhandle
#define DSK6713_AIC23_DATAHANDLE     DSK6713_AIC23_codecdatahandle

/* McBSP handles */
extern MCBSP_Handle DSK6713_AIC23_DATAHANDLE;
extern MCBSP_Handle DSK6713_AIC23_CONTROLHANDLE;

/* Codec module definitions */
#define DSK6713_AIC23_NUMREGS         10
#define DSK6713_AIC23_LEFTINVOL       0
#define DSK6713_AIC23_RIGHTINVOL      1
#define DSK6713_AIC23_LEFTHPVOL       2
#define DSK6713_AIC23_RIGHTHPVOL      3
#define DSK6713_AIC23_ANAPATH         4
#define DSK6713_AIC23_DIGPATH         5
#define DSK6713_AIC23_POWERDOWN       6
#define DSK6713_AIC23_DIGIF           7
#define DSK6713_AIC23_SAMPLERATE      8
#define DSK6713_AIC23_DIGACT          9
#define DSK6713_AIC23_RESET           15

/* Frequency Definitions */
#define DSK6713_AIC23_FREQ_8KHZ       1
#define DSK6713_AIC23_FREQ_16KHZ      2
#define DSK6713_AIC23_FREQ_24KHZ      3
#define DSK6713_AIC23_FREQ_32KHZ      4
#define DSK6713_AIC23_FREQ_44KHZ      5
#define DSK6713_AIC23_FREQ_48KHZ      6
#define DSK6713_AIC23_FREQ_96KHZ      7

/* Codec Handle */
typedef int DSK6713_AIC23_CodecHandle;

/* Parameter Structure for the DSK6713 AIC23 Codec */
typedef struct DSK6713_AIC23_Config {
    int regs[DSK6713_AIC23_NUMREGS];
} DSK6713_AIC23_Config;

#define DSK6713_AIC23_DEFAULTCONFIG { \
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
    0x0011, /* Set-Up Reg 4       Analog audio path control */               \
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
}

/* Set codec register regnum to value regval */
void DSK6713_AIC23_rset(DSK6713_AIC23_CodecHandle hCodec, Uint16 regnum, Uint16 regval);

/* Return value of codec register regnum */
Uint16 DSK6713_AIC23_rget(DSK6713_AIC23_CodecHandle hCodec, Uint16 regnum);

/* Open the codec with id and return handle */
DSK6713_AIC23_CodecHandle DSK6713_AIC23_openCodec(int id, DSK6713_AIC23_Config *Config);

/* Close the codec */
void DSK6713_AIC23_closeCodec(DSK6713_AIC23_CodecHandle hCodec);

/* Configure the codec register values */
void DSK6713_AIC23_config(DSK6713_AIC23_CodecHandle hCodec, DSK6713_AIC23_Config *Config);

/* Write a 32-bit value to the codec */
Int16 DSK6713_AIC23_write(DSK6713_AIC23_CodecHandle hCodec, Uint32 val);

/* Read a 32-bit value from the codec */
Int16 DSK6713_AIC23_read(DSK6713_AIC23_CodecHandle hCodec, Uint32 *val);

/* Set the codec output gain */
void DSK6713_AIC23_outGain(DSK6713_AIC23_CodecHandle hCodec, Uint16 outGain);

/* Set the codec loopback mode */
void DSK6713_AIC23_loopback(DSK6713_AIC23_CodecHandle hCodec, Int16 mode);

/* Enable/disable codec mute mode */
void DSK6713_AIC23_mute(DSK6713_AIC23_CodecHandle hCodec, Int16 mode);

/* Enable/disable codec powerdown modes for DAC, ADC */
void DSK6713_AIC23_powerDown(DSK6713_AIC23_CodecHandle hCodec, Uint16 sect);

/* Set the codec sample rate frequency */
void DSK6713_AIC23_setFreq(DSK6713_AIC23_CodecHandle hCodec, Uint32 freq);

#ifdef __cplusplus
}
#endif

#endif


Uint32 fs=DSK6713_AIC23_FREQ_8KHZ;
union {Uint32 combo; short channel[2];} AIC23_data;
short entrada;


//// hhhhhhh
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

#define using_bios                  //if BIOS don't use top of vector table
extern Uint32 fs;                       //for sampling frequency



interrupt void c_int11()
{
    if (DSK6713_DIP_get(0) == 0)
    {
        //1. Bucle transparente en monostereo
        short CHANNEL_data;
        if (poll) while(!MCBSP_rrdy(DSK6713_AIC23_DATAHANDLE));//if ready to receive
             AIC_data.uint=MCBSP_read(DSK6713_AIC23_DATAHANDLE);//read data
        //Swapping left and right channels (see comments in output_sample())
        CHANNEL_data=AIC_data.channel[RIGHT];           //swap left and right channel
        AIC_data.channel[RIGHT]=AIC_data.channel[LEFT];
        AIC_data.channel[LEFT]=CHANNEL_data;
        entrada=AIC_data.uint;

       //entrada=input_sample();
        //short CHANNEL_data;

        AIC_data.uint=0;                 //clear data structure
        AIC_data.uint=entrada;          //32-bit data -->data structure

        //The existing interface defaults to right channel. To default instead to the
        //left channel and use output_sample(short), left and right channels are swapped
        //In main source program use LEFT 0 and RIGHT 1 (opposite of what is used here)
        CHANNEL_data=AIC_data.channel[RIGHT];           //swap left and right channels
        AIC_data.channel[RIGHT]=AIC_data.channel[LEFT];
        AIC_data.channel[LEFT]=CHANNEL_data;
       if (poll) while(!MCBSP_xrdy(DSK6713_AIC23_DATAHANDLE));//if ready to transmit
            MCBSP_write(DSK6713_AIC23_DATAHANDLE,AIC_data.uint);//write/output data

       //output_sample(entrada);

    }
    else if (DSK6713_DIP_get(1) == 0)
    {
        //2. Canal izquierdo
        short CHANNEL_data;
        if (poll) while(!MCBSP_rrdy(DSK6713_AIC23_DATAHANDLE));//if ready to receive
             AIC_data.uint=MCBSP_read(DSK6713_AIC23_DATAHANDLE);//read data
        //Swapping left and right channels (see comments in output_sample())
        CHANNEL_data=AIC_data.channel[RIGHT];           //swap left and right channel
        AIC_data.channel[RIGHT]=AIC_data.channel[LEFT];
        AIC_data.channel[LEFT]=CHANNEL_data;
        AIC23_data.combo=AIC_data.uint;
       //AIC23_data.combo = input_sample(); //Muestra de entrada de 32 bits



        AIC_data.uint=0;                              //clear data structure
        AIC_data.channel[LEFT]=AIC23_data.channel[LEFT];   //data from Left channel -->data structure

        if (poll) while(!MCBSP_xrdy(DSK6713_AIC23_DATAHANDLE));//if ready to transmit
            MCBSP_write(DSK6713_AIC23_DATAHANDLE,AIC_data.uint);//output left channel

       //output_left_sample(AIC23_data.channel[LEFT]);
    }

    else if (DSK6713_DIP_get(2) == 0)
    {
        //3. Canal derecho
        short CHANNEL_data;
        if (poll) while(!MCBSP_rrdy(DSK6713_AIC23_DATAHANDLE));//if ready to receive
             AIC_data.uint=MCBSP_read(DSK6713_AIC23_DATAHANDLE);//read data
        //Swapping left and right channels (see comments in output_sample())
        CHANNEL_data=AIC_data.channel[RIGHT];           //swap left and right channel
        AIC_data.channel[RIGHT]=AIC_data.channel[LEFT];
        AIC_data.channel[LEFT]=CHANNEL_data;
        AIC23_data.combo=AIC_data.uint;
       //AIC23_data.combo = input_sample();//Muestra de entrada de 32 bits

        AIC_data.uint=0;                              //clear data structure
        AIC_data.channel[RIGHT]=AIC23_data.channel[RIGHT];   //data from Left channel -->data structure

        if (poll) while(!MCBSP_xrdy(DSK6713_AIC23_DATAHANDLE));//if ready to transmit
            MCBSP_write(DSK6713_AIC23_DATAHANDLE,AIC_data.uint);//output left channel

       //output_left_sample(AIC23_data.channel[LEFT]);
        //output_right_sample(AIC23_data.channel[RIGHT]);
    }
    else if (DSK6713_DIP_get(3) == 0)
    {
        //4. Salida en stereo
        short CHANNEL_data;
        if (poll) while(!MCBSP_rrdy(DSK6713_AIC23_DATAHANDLE));//if ready to receive
             AIC_data.uint=MCBSP_read(DSK6713_AIC23_DATAHANDLE);//read data
        //Swapping left and right channels (see comments in output_sample())
        CHANNEL_data=AIC_data.channel[RIGHT];           //swap left and right channel
        AIC_data.channel[RIGHT]=AIC_data.channel[LEFT];
        AIC_data.channel[LEFT]=CHANNEL_data;
        AIC23_data.combo=AIC_data.uint;
       //AIC23_data.combo = input_sample();//Muestra de entrada de 32 bits

        AIC_data.uint=0;                 //clear data structure
                AIC_data.uint=AIC23_data.combo;          //32-bit data -->data structure

                //The existing interface defaults to right channel. To default instead to the
                //left channel and use output_sample(short), left and right channels are swapped
                //In main source program use LEFT 0 and RIGHT 1 (opposite of what is used here)
                CHANNEL_data=AIC_data.channel[RIGHT];           //swap left and right channels
                AIC_data.channel[RIGHT]=AIC_data.channel[LEFT];
                AIC_data.channel[LEFT]=CHANNEL_data;
               if (poll) while(!MCBSP_xrdy(DSK6713_AIC23_DATAHANDLE));//if ready to transmit
                    MCBSP_write(DSK6713_AIC23_DATAHANDLE,AIC_data.uint);//write/output data
       // output_sample(AIC23_data.combo);
    }
    else
    {
        short CHANNEL_data;

            AIC_data.uint=0;                 //clear data structure
            AIC_data.uint=0;          //32-bit data -->data structure

        //The existing interface defaults to right channel. To default instead to the
        //left channel and use output_sample(short), left and right channels are swapped
        //In main source program use LEFT 0 and RIGHT 1 (opposite of what is used here)
            CHANNEL_data=AIC_data.channel[RIGHT];           //swap left and right channels
            AIC_data.channel[RIGHT]=AIC_data.channel[LEFT];
            AIC_data.channel[LEFT]=CHANNEL_data;
           if (poll) while(!MCBSP_xrdy(DSK6713_AIC23_DATAHANDLE));//if ready to transmit
                MCBSP_write(DSK6713_AIC23_DATAHANDLE,AIC_data.uint);//write/output data
    }
    return;
}

void main() //main function
{
    DSK6713_init();
    DSK6713_DIP_init();

    ///comm
    poll=0;                         //0 since not polling

       IRQ_globalDisable();             //disable interrupts
        //c6713_dsk_init();                   //init DSP and codec
       DSK6713_init();                     //call BSL to init DSK-EMIF,PLL)

       hAIC23_handle=DSK6713_AIC23_openCodec(0, &config);//handle(pointer) to codec
       DSK6713_AIC23_setFreq(hAIC23_handle, fs);  //set sample rate
       MCBSP_config(DSK6713_AIC23_DATAHANDLE,&AIC23CfgData);//interface 32 bits toAIC23

       MCBSP_start(DSK6713_AIC23_DATAHANDLE, MCBSP_XMIT_START | MCBSP_RCV_START |
           MCBSP_SRGR_START | MCBSP_SRGR_FRAMESYNC, 220);//start data channel again



        CODECEventId=MCBSP_getXmtEventId(DSK6713_AIC23_codecdatahandle);//McBSP1 Xmit

    #ifndef using_bios                      //do not need to point to vector table
        IRQ_setVecs(vectors);               //point to the IRQ vector table
    #endif                                      //since interrupt vector handles this

        IRQ_map(CODECEventId, 11);          //map McBSP1 Xmit to INT11
        IRQ_reset(CODECEventId);            //reset codec INT 11
       IRQ_globalEnable();                  //globally enable interrupts
        IRQ_nmiEnable();                    //enable NMI interrupt
       IRQ_enable(CODECEventId);            //enable CODEC eventXmit INT11

       short CHANNEL_data;

           AIC_data.uint=0;                 //clear data structure
           AIC_data.uint=0;          //32-bit data -->data structure

       //The existing interface defaults to right channel. To default instead to the
       //left channel and use output_sample(short), left and right channels are swapped
       //In main source program use LEFT 0 and RIGHT 1 (opposite of what is used here)
           CHANNEL_data=AIC_data.channel[RIGHT];           //swap left and right channels
           AIC_data.channel[RIGHT]=AIC_data.channel[LEFT];
           AIC_data.channel[LEFT]=CHANNEL_data;
          if (poll) while(!MCBSP_xrdy(DSK6713_AIC23_DATAHANDLE));//if ready to transmit
               MCBSP_write(DSK6713_AIC23_DATAHANDLE,AIC_data.uint);//write/output data

        //output_sample(0);                   //start McBSP interrupt outputting a sample

    //comm_intr(); //Inicialización del DSK, códec y el McBSP
    while(1);        //bucle infinito
}
