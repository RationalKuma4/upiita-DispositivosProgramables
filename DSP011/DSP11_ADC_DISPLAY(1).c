#define DISPLAY GPIOB_ODR
#define CERO     0XC0
#define UNO      0XF9
#define DOS      0XA4
#define TRES     0XB0


#define LED0   GPIOC_ODR.B0
#define LED1   GPIOC_ODR.B1
#define LED2   GPIOC_ODR.B2
#define LED3   GPIOC_ODR.B3

//#define ADC1 GPIOA_IDR.A0
//Declara variables globales
const unsigned short int segmentos[]={CERO,UNO,DOS,TRES};
unsigned adc_value;
int num, x;

float volt;
void Conf_maq();
void Procesamiento();

void main() {
     Conf_maq();
     ADC_Set_Input_Channel(_ADC_CHANNEL_0);    //establecer el canal
     ADC1_Init();        //inicia el ADC
     while(1) //Bucle principal
        Procesamiento();
}

void Conf_maq()
{
 GPIO_Config(&GPIOA_BASE,_GPIO_PINMASK_0,_GPIO_CFG_MODE_ANALOG | _GPIO_CFG_PULL_NO);     //A0 modo analogico, no es entrada pull (digital)
 //conf. salida digital del display de 7 segmentos
 GPIO_Config(&GPIOB_BASE, _GPIO_PINMASK_0 | _GPIO_PINMASK_1 | _GPIO_PINMASK_2 | _GPIO_PINMASK_3
                        | _GPIO_PINMASK_4 | _GPIO_PINMASK_5 | _GPIO_PINMASK_6 | _GPIO_PINMASK_7,
                          _GPIO_CFG_MODE_OUTPUT | _GPIO_CFG_SPEED_2MHZ |_GPIO_CFG_OTYPE_PP);
  //config. leds
  GPIO_Digital_Output(&GPIOC_BASE,_GPIO_PINMASK_0);
  GPIO_Digital_Output(&GPIOC_BASE,_GPIO_PINMASK_1);
  GPIO_Digital_Output(&GPIOC_BASE,_GPIO_PINMASK_2);
  GPIO_Digital_Output(&GPIOC_BASE,_GPIO_PINMASK_3);
}
void Procesamiento()
{
  x=4095;
  adc_value = ADC1_Get_Sample(0);
  volt=adc_value*(3.3/x); // X=2 a la 12 -1;
  num=floor(volt);  //2.4 = 2
  DISPLAY = segmentos[num];
  if(num == 0){
       LED0 =~ LED0;
       Delay_ms(200);
       LED1=0;
        LED2=0;
        LED3=0;
       }
  else if (num == 1){
       LED1 =~ LED1;
       Delay_ms(200);
       LED0=0;
       LED2=0;
       LED3=0;
        }
  else if (num == 2){
       LED2 =~ LED2;
       Delay_ms(200);
        LED0=0;
       LED1=0;
       LED3=0;
       }
  else if (num == 3){
       LED3 =~ LED3;
       Delay_ms(200);
        LED0=0;
       LED1=0;
       LED2=0;
       //LED3=0;
        }
}