#define DIPSW GPIOC_IDR

unsigned value;
int num, x;
unsigned DACoutput;

void Conf_maq();
void Ini_var();
void Procesamiento();

void main() {
        Conf_maq();
        Ini_var();
        DAC1_Init(_DAC_CH1_ENABLE);  // Initialize DAC1 module for STM32 device, channel 1

        while(1) //Bucle principal
          Procesamiento();
        }

void Conf_maq()
     {
      GPIO_Digital_Input(&GPIOC_BASE, _GPIO_PINMASK_0 | _GPIO_PINMASK_1 | _GPIO_PINMASK_2 | _GPIO_PINMASK_3
                        | _GPIO_PINMASK_4 | _GPIO_PINMASK_5 | _GPIO_PINMASK_6 | _GPIO_PINMASK_7);

      GPIO_Config(&GPIOC_BASE, _GPIO_PINMASK_0 | _GPIO_PINMASK_1 | _GPIO_PINMASK_2 | _GPIO_PINMASK_3
                 | _GPIO_PINMASK_4 | _GPIO_PINMASK_5 | _GPIO_PINMASK_6 | _GPIO_PINMASK_7,
                 _GPIO_CFG_MODE_INPUT | _GPIO_CFG_SPEED_2MHZ | _GPIO_CFG_PULL_DOWN);

     }
 void Ini_var()
 {
   value=0;
}
void Procesamiento()
     {
     x=255; //para 8 bits
     //x=4096 //para 12 bits
     value=DIPSW&0xff;
     //DAC1_Ch1_Output(value); //Por default el DAC es de 12 bits
     DAC1_Advanced_Ch1_Output(value, _DAC_8_BIT | _DAC_WAVE_DISABLED | _DAC_TRIGGER_SW); //para 8 bits
     DACoutput = 3.3 * value/x;
     }