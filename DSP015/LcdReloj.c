#define LED GPIOA_ODR.B5

//#define DISPLAY GPIOB_ODR
sbit LCD_RS at GPIOC_ODR.B0;
sbit LCD_EN at GPIOC_ODR.B1;
sbit LCD_D4 at GPIOC_ODR.B2;
sbit LCD_D5 at GPIOC_ODR.B3;
sbit LCD_D6 at GPIOC_ODR.B4;
sbit LCD_D7 at GPIOC_ODR.B5;

unsigned int val;
unsigned int cont1;
int hora = 0, minu = 0, seg = 0, dec = 0;
char horaT[7], minT[7], segT[7], decT[7];

void Periodo() iv IVT_INT_TIM3 ics ICS_AUTO
{
    TIM3_SR.UIF = 0;
    //LED=~LED;
    dec++;
    if (dec == 10)
    {
        dec = 0;
        seg++;
        LED = ~LED;
        if (seg == 60)
        { //Cuando llegue el segundero a 60
            seg = 0;
            minu++; //se reinician los segundos y aumentan los minutos
            if (minu == 60)
            {             //Cuando los minutos llegan a 60
                minu = 0; //Se reinicia el minutero
                hora++;   //y aumenta en uno el valor de hora
                if (hora == 24)
                    hora = 0; //Si la hora llega a 24 se reinicia a 0
            }
        }
    }
    IntToStr(dec, decT); //Se hacen las conversiones a texto
    IntToStr(seg, segT); //Se hacen las conversiones a texto
    IntToStr(minu, minT);
    IntToStr(hora, horaT);
    if (hora < 10)
    {
        Lcd_Out(2, 1, "0");
        Lcd_Out(2, 2, &horaT[5]);
    }
    else
    {
        Lcd_Out(2, 1, &horaT[4]);
        Lcd_Out(2, 2, &horaT[5]);
    }
    Lcd_Out(2, 3, ":");
    if (minu < 10)
    {
        Lcd_Out(2, 4, "0");
        Lcd_Out(2, 5, &minT[5]);
    }
    else
    {
        Lcd_Out(2, 4, &minT[4]);
        Lcd_Out(2, 5, &minT[5]);
    }
    Lcd_Out(2, 6, ":");
    if (seg < 10)
    {
        Lcd_Out(2, 7, "0");
        Lcd_Out(2, 8, &segT[5]);
    }
    else
    {
        Lcd_Out(2, 7, &segT[4]);
        Lcd_Out(2, 8, &segT[5]);
    }
    Lcd_Out(2, 9, ":");
    if (dec < 10)
    {
        Lcd_Out(2, 10, "0");
        Lcd_Out(2, 11, &decT[5]);
    }
    else
    {
        Lcd_Out(2, 10, &decT[4]);
        Lcd_Out(2, 11, &decT[5]);
    }
}

void main()
{
    Lcd_Init();
    Lcd_Cmd(_LCD_CLEAR);
    Lcd_Cmd(_LCD_CURSOR_OFF);
    LED = 0;
    cont1 = 0;
    Lcd_Out(1, 4, "");
    GPIO_Digital_Output(&GPIOA_BASE, _GPIO_PINMASK_5); //Salida con push pull
    //Timer 3
    RCC_APB1ENR.TIM3EN = 1;       // Enciende el módulo del timer 3
    TIM3_CR1.CEN = 0;             // Deshabilita el contador del timer 3
    TIM3_PSC = 7999;              // Establece el prescalador APB1/(PSC+1) =2000Hz
    TIM3_ARR = 200;               // Establece valor de autorecarga    0.5 seg.
    NVIC_IntEnable(IVT_INT_TIM3); // Establece la interrupcion del timer 3
    TIM3_DIER.UIE = 1;            // Habilita la generación de interrupción
    TIM3_CR1.CEN = 1;             // Habilita el contador del timer 3

    //Control global de interrupciones
    EnableInterrupts(); // Habilita las interrupciones
}