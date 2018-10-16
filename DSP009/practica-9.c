para el 5
//#define BOTON GPIOB_IDR.B5 //Entrada flotante PB5
#define BOTON GPIOC_IDR.B13 //Botón de usuario (PC13 pin 23 del CN7)
#define LED   GPIOA_ODR.B5   //Led de usuario (PA5 pin 11 del CN10)

//PROTOTIPOS  DE LAS FUNCIONES
void Conf_maq();
void Ini_var();
void Proceso();

void main() {
     Conf_maq();
     Ini_var();
     while(1) //Bucle principal
     Proceso();
}

void Conf_maq()
{
   GPIO_Digital_Input(&GPIOC_BASE,_GPIO_PINMASK_13);    //Entrada con Pullup usando el botón de usuario (PC13)
                                                      //(Entrada normalmente en alto y el botón se activa en bajo)

   //GPIO_Digital_Input(&GPIOB_BASE,_GPIO_PINMASK_5);   //Entrada flotante usando el pin PB5 como botón
                                                      //(Entrada normalmente en bajo y el botón se desactiva en 3.3V)
   //GPIO_Config(&GPIOB_BASE,
   //           _GPIO_PINMASK_5,
   //           _GPIO_CFG_MODE_INPUT | _GPIO_CFG_PULL_UP);  //Entrada con Pullup usando el pin PB5 como botón
                                                        //(Entrada normalmente en alto y el botón se activa en bajo)
//GPIO_Config(&GPIOB_BASE,
   //           _GPIO_PINMASK_5,
   //           _GPIO_CFG_MODE_INPUT | _GPIO_CFG_PULL_DOWN);  //Entrada con Pulldown usando el pin PB5
                                                                                                                     //como botón
                                                                                       //(Entrada normalmente en bajo y el botón se desactiva en 3.3V)

    GPIO_Digital_Output(&GPIOA_BASE,_GPIO_PINMASK_5);    //Salida con push pull
}

void Ini_var()
{
     LED=0;
}

void Proceso()
{
      if(BOTON==0)
     {
           LED=~LED;
           Delay_ms(100);
      }
}

para el 6

void Proceso()
{
      if(BOTON==1)
     {
           LED=~LED;
           Delay_ms(200);
      }
}


para el 7
#define BOTON GPIOB_IDR.B5 //Entrada flotante PB5
//#define BOTON GPIOC_IDR.B13 //Botón de usuario (PC13 pin 23 del CN7)
#define LED   GPIOA_ODR.B5   //Led de usuario (PA5 pin 11 del CN10)

//PROTOTIPOS  DE LAS FUNCIONES
void Conf_maq();
void Ini_var();
void Proceso();

void main() {
     Conf_maq();
     Ini_var();
     while(1) //Bucle principal
     Proceso();
}

void Conf_maq()
{
  // GPIO_Digital_Input(&GPIOC_BASE,_GPIO_PINMASK_13);    //Entrada con Pullup usando el botón de usuario (PC13)
                                                      //(Entrada normalmente en alto y el botón se activa en bajo)

   //GPIO_Digital_Input(&GPIOB_BASE,_GPIO_PINMASK_5);   //Entrada flotante usando el pin PB5 como botón
                                                      //(Entrada normalmente en bajo y el botón se desactiva en 3.3V)
   GPIO_Config(&GPIOB_BASE,
              _GPIO_PINMASK_5,
              _GPIO_CFG_MODE_INPUT | _GPIO_CFG_PULL_UP);  //Entrada con Pullup usando el pin PB5 como botón
                                                        //(Entrada normalmente en alto y el botón se activa en bajo)
//GPIO_Config(&GPIOB_BASE,
   //           _GPIO_PINMASK_5,
   //           _GPIO_CFG_MODE_INPUT | _GPIO_CFG_PULL_DOWN);  //Entrada con Pulldown usando el pin PB5
                                                                                                                     //como botón
                                                                                       //(Entrada normalmente en bajo y el botón se desactiva en 3.3V)

    GPIO_Digital_Output(&GPIOA_BASE,_GPIO_PINMASK_5);    //Salida con push pull
}

void Ini_var()
{
     LED=0;
}

void Proceso()
{
      if(BOTON==1)
     {
           LED=~LED;
           Delay_ms(200);
      }
}

para el 8

#define BOTON GPIOB_IDR.B5 //Entrada flotante PB5
//#define BOTON GPIOC_IDR.B13 //Botón de usuario (PC13 pin 23 del CN7)
#define LED   GPIOA_ODR.B5   //Led de usuario (PA5 pin 11 del CN10)

//PROTOTIPOS  DE LAS FUNCIONES
void Conf_maq();
void Ini_var();
void Proceso();

void main() {
     Conf_maq();
     Ini_var();
     while(1) //Bucle principal
     Proceso();
}

void Conf_maq()
{
  // GPIO_Digital_Input(&GPIOC_BASE,_GPIO_PINMASK_13);    //Entrada con Pullup usando el botón de usuario (PC13)
                                                      //(Entrada normalmente en alto y el botón se activa en bajo)

   //GPIO_Digital_Input(&GPIOB_BASE,_GPIO_PINMASK_5);   //Entrada flotante usando el pin PB5 como botón
                                                      //(Entrada normalmente en bajo y el botón se desactiva en 3.3V)
  // GPIO_Config(&GPIOB_BASE,
            //  _GPIO_PINMASK_5,
            //  _GPIO_CFG_MODE_INPUT | _GPIO_CFG_PULL_UP);  //Entrada con Pullup usando el pin PB5 como botón
                                                        //(Entrada normalmente en alto y el botón se activa en bajo)
GPIO_Config(&GPIOB_BASE,
              _GPIO_PINMASK_5,
            _GPIO_CFG_MODE_INPUT | _GPIO_CFG_PULL_DOWN);  //Entrada con Pulldown usando el pin PB5
                                                                                                                     //como botón
                                                                                       //(Entrada normalmente en bajo y el botón se desactiva en 3.3V)

    GPIO_Digital_Output(&GPIOA_BASE,_GPIO_PINMASK_5);    //Salida con push pull
}

void Ini_var()
{
     LED=0;
}

void Proceso()
{
      if(BOTON==1)
     {
           LED=~LED;
           Delay_ms(200);
      }
}


para el 10

#define BOTONV GPIOB_IDR.B5 //Entrada flotante PB5
#define BOTONA GPIOB_IDR.B6//Entrada flotante PB5
//#define BOTON GPIOC_IDR.B13 //Botón de usuario (PC13 pin 23 del CN7)
//#define LED   GPIOA_ODR.B5   //Led de usuario (PA5 pin 11 del CN10)
#define LED1   GPIOC_ODR.B0
#define LED2  GPIOC_ODR.B1
#define LED3   GPIOC_ODR.B2
#define LED4   GPIOC_ODR.B3

#define LED5   GPIOC_ODR.B4
#define LED6  GPIOC_ODR.B5
#define LED7   GPIOC_ODR.B6
#define LED8   GPIOC_ODR.B7
//PROTOTIPOS  DE LAS FUNCIONES
void Conf_maq();
void Ini_var();
void Proceso();

void main() {
     Conf_maq();
     Ini_var();
     while(1) //Bucle principal
     Proceso();
}

void Conf_maq()
{
  // GPIO_Digital_Input(&GPIOC_BASE,_GPIO_PINMASK_13);    //Entrada con Pullup usando el botón de usuario (PC13)
                                                      //(Entrada normalmente en alto y el botón se activa en bajo)

   //GPIO_Digital_Input(&GPIOB_BASE,_GPIO_PINMASK_5);   //Entrada flotante usando el pin PB5 como botón
                                                      //(Entrada normalmente en bajo y el botón se desactiva en 3.3V)
  // GPIO_Config(&GPIOB_BASE,
            //  _GPIO_PINMASK_5,
            //  _GPIO_CFG_MODE_INPUT | _GPIO_CFG_PULL_UP);  //Entrada con Pullup usando el pin PB5 como botón
                                                        //(Entrada normalmente en alto y el botón se activa en bajo)
GPIO_Config(&GPIOB_BASE,
              _GPIO_PINMASK_5,
            _GPIO_CFG_MODE_INPUT | _GPIO_CFG_PULL_DOWN);  //Entrada con Pulldown usando el pin PB5
                                                                                                                     //como botón
      GPIO_Config(&GPIOB_BASE,
              _GPIO_PINMASK_6,
              _GPIO_CFG_MODE_INPUT | _GPIO_CFG_PULL_DOWN);                                                                               //(Entrada normalmente en bajo y el botón se desactiva en 3.3V)

    GPIO_Digital_Output(&GPIOC_BASE,_GPIO_PINMASK_0);
    GPIO_Digital_Output(&GPIOC_BASE,_GPIO_PINMASK_1);
    GPIO_Digital_Output(&GPIOC_BASE,_GPIO_PINMASK_2);
    GPIO_Digital_Output(&GPIOC_BASE,_GPIO_PINMASK_3);    //Salida con push pull

    GPIO_Digital_Output(&GPIOC_BASE,_GPIO_PINMASK_4);
    GPIO_Digital_Output(&GPIOC_BASE,_GPIO_PINMASK_5);
    GPIO_Digital_Output(&GPIOC_BASE,_GPIO_PINMASK_6);
    GPIO_Digital_Output(&GPIOC_BASE,_GPIO_PINMASK_7);
}

void Ini_var()
{
     LED1=0;
}

void Proceso()
{          int pin ;
      if(BOTONV==1)
     {     for (pin=0; pin<4;pin++)    {
           if (pin==0) {
              LED1=~LED1;
              Delay_ms(200);
              LED1=0;
           }
           else if (pin==1) {
                LED2=~LED2;
                Delay_ms(200);
                LED2=0;
           }
           else if (pin==2) {
                LED3=~LED3;
                Delay_ms(200);
                LED3=0;
           }
           else if (pin==3) {
                LED4=~LED4;
                Delay_ms(200);
                LED4=0;
           }
           }
      }


      else if(BOTONA==1)
     {     for (pin=3; pin>=0;pin--)    {
           if (pin==0) {
              LED5=~LED5;
              Delay_ms(200);
              LED5=0;
           }
           else if (pin==1) {
                LED6=~LED6;
                Delay_ms(200);
                LED6=0;
           }
           else if (pin==2) {
                LED7=~LED7;
                Delay_ms(200);
                LED7=0;
           }
           else if (pin==3) {
                LED8=~LED8;
                Delay_ms(200);
                LED8=0;
           }
           }
      }
}