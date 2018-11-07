//#include "rbf_FIR_fs8000.cof"
#define N 46
double h[N]={0.0185528759683730,0.0242109476032831,0.0277829208244479,0.0287157605048040,0.0267160957801307,0.0218010004123622,0.0143147815659519,0.00490800537748229,-0.00552053823532904,-0.0159136630462449,-0.0251680526378794,-0.0322565367332875,-0.0363463016475719,-0.0368989858399227,-0.0337403559822885,-0.0270905482727715,-0.0175503237081195,-0.00604389990240904,0.00627592988236340,0.0181501278001484,0.0283495394936514,0.0358093662588136,0.0397465559917278,0.0397465559917278,0.0358093662588136,0.0283495394936514,0.0181501278001484,0.00627592988236340,-0.00604389990240904,-0.0175503237081195,-0.0270905482727715,-0.0337403559822885,-0.0368989858399227,-0.0363463016475719,-0.0322565367332875,-0.0251680526378794,-0.0159136630462449,-0.00552053823532904,0.00490800537748229,0.0143147815659519,0.0218010004123622,0.0267160957801307,0.0287157605048040,0.0277829208244479,0.0242109476032831,0.0185528759683730};



float temp1, temp2, yn, x, volt_adc_in, volt_dac_out;
unsigned int adc_value, y;

void Proc() iv IVT_INT_TIM2 ics ICS_AUTO {
   float u[N];
   int y;
   short i, k, m;

   TIM2_SR.UIF = 0;
   adc_value = ADC1_Get_Sample(0);         //PA0 es la entrada al canal 0 del ADC1
   volt_adc_in=adc_value*3.3/4095;
   x= (double) adc_value;
   //Rutina de filtrado FIR por muestra
   u[0]=x;
   yn = 0;
   for (i = 0; i< N; i++)
       yn += (h[i] * u[i]);
   for (i = N-1; i > 0; i--)
       u[i] = u[i-1];
   y= (int) yn;

   //volt_dac_out = 3.3 * y/4095;
   //DAC_DHR12R1=y;
   //DAC_SWTRIGRbits.SWTRIG1=1;  //INICIA LA CONVERSIÓN ES BORRADA POR SW EN 
                                                             //CUANTO TERMINA
   DAC1_Ch1_Output(y);  // get output from the channel 1 of DAC1 module
}

void main() {
   /*GPIO_Config(&GPIOA_BASE,
            _GPIO_PINMASK_0,
            _GPIO_CFG_MODE_ANALOG | _GPIO_CFG_PULL_NO);*/
   ADC_Set_Input_Channel(_ADC_CHANNEL_0);                // Set ADC channel 0 as an analog
                                                                                                // input
   ADC1_Init();
   DAC1_Init(_DAC_CH1_ENABLE);  // Initialize DAC1 module for STM32 device, channel 1



   //Configuración del adc1

   ADC1_CR2=0x00000001;             //Habilita ADC
   RCC_APB2ENR|=1<<ADC1EN;  //HABILITA EL RELOJ DEL ADC1
   ADC1_SMPR2=0x00000000;       //Tiempo de conversión de 480+12 ciclos= 492/42E6 = 
                                                         //1.171428571E-5
   ADC_CCR=0x00030000;      //ADC prescaler PCLK2 dividido por 8        = 2MHz
   ADC1_CR2=0x56000001;     //Iniciar la conversión de canales regulares.
                                                 //Habilitar trigger externo para canales regulares
                                                  //Timer 2 TRGO event

   //Configuración del dac1
   GPIO_Analog_Input(&GPIOA_BASE,_GPIO_PINMASK_4);//HABILITA EL PUERTO 4 EN
                                                                                                  // MODO ANALÓGICO
   RCC_APB1ENR.B29=1;             //HABILITA EL RELOJ DEL BUS APB1 AL MODULO DAC
   //DAC_CRbits.TSEL1=4;            //SELECCIONA DISPARO POR HARDWARE TIMER 2
   //DAC_CR+=0X38;                //SELECCIÓN DE DISPARO POR SOFTWARE Y ENABLE
   DAC_CRbits.TSEL1=7;          //SELECCIÓN DE DISPARO POR SOFTWARE
   DAC_CRbits.TEN1=1;             //Habilita conversión por disparo
   DAC_CRbits.BOFF1=1;            //ENCIENDE EL BUFFER DE SALIDA DEL DAC1
   DAC_CRbits.EN1=1;              //ENCIENDE EL MODULO DAC1
   DAC_DHR12R1=2048;
   //DAC_SWTRIGRbits.SWTRIG1=1;     //INICIA LA CONVERSIÓN ES BORRADA POR HW EN
                                                                 // CUANTO TERMINA

   //Timer 2
   RCC_APB1ENR.TIM2EN = 1;
   TIM2_CR2bits.MMS=1;           // Master Mode selected enabled
   TIM2_CR1.CEN = 0;             // Deshabilita el contador del timer 2
   TIM2_PSC = 999;              // Establece el prescalador APB1/(PSC+1)
   TIM2_ARR = 1;              // Establece valor de autorecarga
   NVIC_IntEnable(IVT_INT_TIM2); // Establece la interrupcion del timer 2
   TIM2_DIER.UIE = 1;            // Habilita la generación de interrupción
   TIM2_CR1.CEN = 1;             // Habilita el contador del timer 2

   //Control global de interrupciones
   EnableInterrupts();             // Habilita las interrupciones
}





//#include "pbf_FIR_fs8000.cof"
#define N 46
double h[N]={0.0185528759683730,0.0242109476032831,0.0277829208244479,0.0287157605048040,0.0267160957801307,0.0218010004123622,0.0143147815659519,0.00490800537748229,-0.00552053823532904,-0.0159136630462449,-0.0251680526378794,-0.0322565367332875,-0.0363463016475719,-0.0368989858399227,-0.0337403559822885,-0.0270905482727715,-0.0175503237081195,-0.00604389990240904,0.00627592988236340,0.0181501278001484,0.0283495394936514,0.0358093662588136,0.0397465559917278,0.0397465559917278,0.0358093662588136,0.0283495394936514,0.0181501278001484,0.00627592988236340,-0.00604389990240904,-0.0175503237081195,-0.0270905482727715,-0.0337403559822885,-0.0368989858399227,-0.0363463016475719,-0.0322565367332875,-0.0251680526378794,-0.0159136630462449,-0.00552053823532904,0.00490800537748229,0.0143147815659519,0.0218010004123622,0.0267160957801307,0.0287157605048040,0.0277829208244479,0.0242109476032831,0.0185528759683730};
//double h[N]={0.00856962253365129,0.0158386383599205,0.0221007884130015,0.0265830119613712,0.0286540120178311,0.0279078917695331,0.0242261810710935,0.0178095101924505,0.00917349564520648,-0.000892465121029603,-0.0114003269247699,-0.0212650432822991,-0.0294218150118682,-0.0349457498165438,-0.0371599987499043,-0.0357193661713704,-0.0306589240099041,-0.0224010266100509,-0.0117188749586484,0.000340144609584725,0.0125633356096479,0.0237018596789182,0.0326057326914000,0.0383493291396931,0.0403330316563511,0.0383493291396931,0.0326057326914000,0.0237018596789182,0.0125633356096479,0.000340144609584725,-0.0117188749586484,-0.0224010266100509,-0.0306589240099041,-0.0357193661713704,-0.0371599987499043,-0.0349457498165438,-0.0294218150118682,-0.0212650432822991,-0.0114003269247699,-0.000892465121029603,0.00917349564520648,0.0178095101924505,0.0242261810710935,0.0279078917695331,0.0286540120178311,0.0265830119613712,0.0221007884130015,0.0158386383599205,0.00856962253365129};
float yn, x, volt_adc_in, volt_dac_out;
unsigned int adc_value, y;
void Proceso();


void main() {
   /*GPIO_Config(&GPIOA_BASE,
            _GPIO_PINMASK_0,
            _GPIO_CFG_MODE_ANALOG | _GPIO_CFG_PULL_NO);*/
   ADC_Set_Input_Channel(_ADC_CHANNEL_0);                // Set ADC channel 0 as an analog input
   ADC1_Init();
   DAC1_Init(_DAC_CH1_ENABLE);  // Initialize DAC1 module for STM32 device, channel 1



   //Configuración del adc1
   ADC1_CR2=0x00000001;     //Habilita ADC
   RCC_APB2ENR|=1<<ADC1EN;  //HABILITA EL RELOJ DEL ADC1
   ADC1_SMPR2=0x00000000;   //Tiempo de conversión de 480+12 ciclos= 492/42E6 = 1.171428571E-5
   ADC_CCR=0x00030000;      //ADC prescaler PCLK2 dividido por 8        = 2MHz
   ADC1_CR2=0x56000001;     //Iniciar la conversión de canales regulares.
                           //Habilitar trigger externo para canales regulares
                           //Timer 2 TRGO event

   //Configuración del dac1
   //(&GPIOA_BASE,_GPIO_PINMASK_4);//HABILITA EL PUERTO 4 EN MODO

   //Configuración de entrada analogica
GPIO_Config(&GPIOA_BASE,
            _GPIO_PINMASK_0,
            _GPIO_CFG_MODE_ANALOG | _GPIO_CFG_PULL_NO);

// Configuracion del puerto DAC Canal 1
GPIO_Config(&GPIOA_BASE,
            _GPIO_PINMASK_4,
            _GPIO_CFG_MODE_ANALOG | _GPIO_CFG_PULL_NO);


                                                                                                        // ANALÓGICO
   RCC_APB1ENR.B29=1;             //HABILITA EL RELOJ DEL BUS APB1 AL MODULO DAC
   //DAC_CRbits.TSEL1=4;            //SELECCIONA DISPARO POR HARDWARE TIMER 2
   //DAC_CR+=0X38;                //SELECCIÓN DE DISPARO POR SOFTWARE Y ENABLE
   DAC_CRbits.TSEL1=7;          //SELECCIÓN DE DISPARO POR SOFTWARE
   DAC_CRbits.TEN1=1;             //Habilita conversión por disparo
   DAC_CRbits.BOFF1=1;            //ENCIENDE EL BUFFER DE SALIDA DEL DAC1
   DAC_CRbits.EN1=1;              //ENCIENDE EL MODULO DAC1
   DAC_DHR12R1=2048;
   //DAC_SWTRIGRbits.SWTRIG1=1;     //INICIA LA CONVERSIÓN ES BORRADA POR HW EN
                                                                    // CUANTO TERMINA
   while(1) //Bucle principal
        Proceso();
}

void Proceso()
{
       short i, k, m;
       float u[N];

       adc_value = ADC1_Get_Sample(0);         //PA0 es la entrada al canal 0 del ADC1
       volt_adc_in=adc_value*3.3/4095;
       x= (double) adc_value;
       //Rutina de filtrado FIR por muestra
       u[0]=x;
       yn = 0;
       for (i = 0; i< N; i++)
          yn += (h[i] * u[i]);
       for (i = N-1; i > 0; i--)
          u[i] = u[i-1];
       y= (int) yn;
       //y= (unsigned int) yn;
       //volt_dac_out = 3.3 * y/4095;
       DAC1_Ch1_Output(y);
      // Delay_us(250); // Solo para obtener FS=8000
}