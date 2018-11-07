unsigned DACoutput;
unsigned adc_value;
float volt;
int x;
void Conf_maq();
void Ini_var();
void Procesamiento();

void main()
{
    Conf_maq();
    Ini_var();
    //ADC_Set_Input_Channel(_ADC_CHANNEL_0);    //establecer el canal
    ADC1_Init(); //inicia el ADC
    DAC1_Init(_DAC_CH1_ENABLE);
    while (1) //Bucle principal
        Procesamiento();
}

void Conf_maq()
{
    GPIO_Config(&GPIOA_BASE, _GPIO_PINMASK_0, _GPIO_CFG_MODE_ANALOG | _GPIO_CFG_PULL_NO);
}
void Ini_var()
{
}
void Procesamiento()
{
    /*ADC_Set_Input_Channel(_ADC_CHANNEL_0);
        salidaADC=ADC1_Get_Sample(0);
        DAC1_CH2_Output(salidaADC);      */

    // x=4096;
    ADC_Set_Input_Channel(_ADC_CHANNEL_0);
    adc_value = ADC1_Get_Sample(0);
    //volt=adc_value*(3.3/x);

    DAC1_Ch1_Output(adc_value); //Por default el DAC es de 12 bits
                                //DACoutput = 3.3 * adc_value/x;
}