// LCD module connections
sbit LCD_RS at GPIOC_ODR.B0;
sbit LCD_EN at GPIOC_ODR.B1;
sbit LCD_D4 at GPIOC_ODR.B2;
sbit LCD_D5 at GPIOC_ODR.B3;
sbit LCD_D6 at GPIOC_ODR.B4;
sbit LCD_D7 at GPIOC_ODR.B5;
char txt1[6];
char limpiar[] = "                 ";
float volt;
void lectura();
void Conf_maq();
void Procesamiento();
unsigned adc_value;
unsigned valor;
void main()
{
    Conf_maq();
    ADC_Set_Input_Channel(_ADC_CHANNEL_0);
    ADC1_Init();
    Lcd_Init();
    Lcd_Cmd(_LCD_CLEAR);
    Lcd_Cmd(_LCD_CURSOR_OFF);
    Lcd_Out(1, 1, "MaquinadeEstado");

    while (1) //Bucle principal
        Procesamiento();
}

void Conf_maq()
{
    GPIO_Config(&GPIOA_BASE, _GPIO_PINMASK_0, _GPIO_CFG_MODE_ANALOG | _GPIO_CFG_PULL_NO);
    GPIO_Config(&GPIOC_BASE, _GPIO_PINMASK_0 | _GPIO_PINMASK_1 | _GPIO_PINMASK_2 | _GPIO_PINMASK_3 | _GPIO_PINMASK_4 | _GPIO_PINMASK_5,
                _GPIO_CFG_MODE_OUTPUT | _GPIO_CFG_SPEED_2MHZ);
}

void Procesamiento()
{

    adc_value = ADC1_Get_Sample(0);
    volt = adc_value * (3.3 / 4095);
    FloatToStr(volt, txt1);
    Lcd_Out(2, 1, limpiar);
    Lcd_Out(2, 1, txt1);
    Delay_ms(500);
}