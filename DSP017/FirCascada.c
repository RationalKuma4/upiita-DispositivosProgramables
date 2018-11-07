#define Ne 5
#define N 3

float b[Ne][N] = {{1, 0, -1}, {1, 0, -1}, {1, 0, -1}};
float a[Ne][N] = {{1, -1.80698640507082, 0.953361813177329}, {1, -1.91550999268786, 0.970847556557155}, {1, -1.83656685674047, 0.925127794903965}};
float G[Ne] = {0.0767632705882416,
               0.0767632705882416,
               0.0374361025480173,
               1};
float u1[Ne][N];

float temp1, temp2, ye, x, volt_adc_in, volt_dac_out;
unsigned int adc_value, y;

void Proc() iv IVT_INT_TIM2 ics ICS_AUTO
{
    float yn, u[N];
    int e, i, k, m;
    unsigned int y;
    //////////////////////////////////////////
    TIM2_SR.UIF = 0;
    adc_value = ADC1_Get_Sample(0); //PA0 es la entrada al canal 0 del ADC1
    volt_adc_in = adc_value * 3.3 / 4095;
    x = adc_value;
    //Rutina de filtrado FIR por muestra

    adc_value = ADC1_Get_Sample(0); //PA0 es la entrada al canal 0 del ADC1
    x = (float)adc_value;
    for (e = 0; e < Ne; e++)
    {
        temp1 = 0;
        temp2 = 0;
        for (k = 1; k < N; k++)
        {
            temp1 = temp1 - a[e][k] * u1[e][k];
            temp2 = temp2 + b[e][k] * u1[e][k];
        }
        u1[e][0] = G[e] * x + temp1;
        yn = u1[e][0] * b[e][0] + temp2;
        //Corrimiento
        for (i = N - 1; i > 0; i--)
        {
            u1[e][i] = u1[e][i - 1];
        }
        x = yn;
    }
    y = (unsigned int)yn;
    ///////////////////////////////////////////

    volt_dac_out = 3.3 * y / 4095;
    DAC_DHR12R1 = y;
    DAC_SWTRIGRbits.SWTRIG1 = 1; //INICIA LA CONVERSIÓN ES BORRADA
                                 // POR SW EN CUANTO TERMINA
}

void main()
{
    //ADC_Set_Input_Channel(_ADC_CHANNEL_0);                // Set ADC channel 0 as an analog input
    GPIO_Config(&GPIOA_BASE,
                _GPIO_PINMASK_0,
                _GPIO_CFG_MODE_ANALOG | _GPIO_CFG_PULL_NO);
    ADC1_Init();

    //Configuración del adc1
    ADC1_CR2 = 0x00000001;      //Habilita ADC
    RCC_APB2ENR |= 1 << ADC1EN; //HABILITA EL RELOJ DEL ADC1
    //ADC1_SMPR2=0x00000007;   //Tiempo de conversión de 480+12 ciclos= 492/42E6 = 1.171428571E-5
    ADC_CCR = 0x00030000;  //ADC prescaler PCLK2 dividido por 8        = 2MHz
    ADC1_CR2 = 0x56000001; //Iniciar la conversión de canales regulares.
                           //Habilitar trigger externo para canales regulares
                           //Timer 2 TRGO event
    //Configuración del dac1
    GPIO_Analog_Input(&GPIOA_BASE, _GPIO_PINMASK_4); //HABILITA EL PUERTO 4
                                                     //EN MODO ANALÓGICO
    RCC_APB1ENR.B29 = 1;                             //HABILITA EL RELOJ DEL BUS APB1 AL MODULO DAC
    //DAC_CRbits.TSEL1=4;          //SELECCIONA DISPARO POR HARDWARE TIMER 2
    //DAC_CR+=0X38;                //SELECCIÓN DE DISPARO POR SOFTWARE Y ENABLE
    DAC_CRbits.TSEL1 = 7; //SELECCIÓN DE DISPARO POR SOFTWARE
    DAC_CRbits.TEN1 = 1;  //Habilita conversión por disparo
    DAC_CRbits.BOFF1 = 1; //ENCIENDE EL BUFFER DE SALIDA DEL DAC1
    DAC_CRbits.EN1 = 1;   //ENCIENDE EL MODULO DAC1
    DAC_DHR12R1 = 2048;
    //DAC_SWTRIGRbits.SWTRIG1=1;   //INICIA LA CONVERSIÓN ES BORRADA
    //POR SW EN CUANTO TERMINA

    //Timer 2
    RCC_APB1ENR.TIM2EN = 1;
    TIM2_CR2bits.MMS = 1;         // Master Mode selected enabled
    TIM2_CR1.CEN = 0;             // Deshabilita el contador del timer 2
    TIM2_PSC = 99;                // Establece el prescalador APB1/(PSC+1)=0.16 MHz
    TIM2_ARR = 1;                 // Establece valor de autorecarga
    NVIC_IntEnable(IVT_INT_TIM2); // Establece la interrupcion del timer 3
    TIM2_DIER.UIE = 1;            // Habilita la generación de interrupción
    TIM2_CR1.CEN = 1;             // Habilita el contador del timer 3

    //Control global de interrupciones
    EnableInterrupts(); // Habilita las interrupciones
}
//total_datos=sizeof(vec)/sizeof(unsigned int);