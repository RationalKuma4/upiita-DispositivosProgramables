// TFT module connections
unsigned int TFT_DataPort at GPIOB_ODR;
sbit TFT_RST at GPIOC_ODR.B0;
sbit TFT_CS at GPIOC_ODR.B1;
sbit TFT_RS at GPIOC_ODR.B2;
sbit TFT_WR at GPIOC_ODR.B3;
sbit TFT_RD at GPIOC_ODR.B4;
// End TFT module connections

int i = 0;
int vector[242] = {89, 88, 88, 87, 86, 85, 84, 83, 81, 80, 78, 76, 74, 72, 70, 68, 66, 64, 61, 59, 56, 53, 51, 48, 45, 43, 40, 37, 34, 32, 29,
                   26, 24, 21, 19, 17, 14, 12, 10, 9, 7, 5, 4, 3, 2, 1, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 8, 10, 13, 15, 18, 22, 25, 29, 33, 37, 41, 46, 51, 56,
                   61, 67, 72, 78, 84, 91, 97, 103, 110, 117, 124, 131, 138, 145, 152, 159, 166, 173, 180, 187, 194, 201, 208, 215, 222, 228, 234, 241, 247, 253,
                   258, 264, 269, 274, 279, 284, 288, 292, 296, 299, 302, 305, 308, 310, 312, 313, 314, 315, 316, 316, 316, 315, 314, 313, 312, 310, 308, 305,
                   302, 299, 296, 292, 288, 284, 279, 274, 269, 264, 258, 253, 247, 241, 234, 228, 222, 215, 208, 201, 194, 187, 180, 173, 166, 159, 152, 145,
                   138, 131, 124, 117, 110, 103, 97, 91, 84, 78, 72, 67, 61, 56, 51, 46, 41, 37, 33, 29, 25, 22, 18, 15, 13, 10, 8, 6, 4, 3, 2, 1, 0, 0, 0, 0,
                   0, 0, 1, 2, 3, 4, 5, 7, 9, 10, 12, 14, 17, 19, 21, 24, 26, 29, 32, 34, 37, 40, 43, 45, 48, 51, 53, 56, 59, 61, 64, 66, 68, 70, 72, 74, 76,
                   78, 80, 81, 83, 84, 85, 86, 87, 88, 88};

int vector2[242] = {0, 4, 8, 12, 15, 19, 23, 27, 31, 35, 38, 42, 46, 49, 53, 57, 60, 64, 67, 71, 74, 78, 81, 84, 87, 90, 93, 96, 99, 102, 105, 108, 110, 113, 116, 118, 120, 123,
                    125, 127, 129, 131, 133, 134, 136, 138, 139, 141, 142, 143, 144, 145, 146, 147, 148, 148, 149, 149, 150, 150, 150, 150, 150, 150, 149, 149, 149, 148, 147, 147, 146, 145, 144,
                    143, 141, 140, 138, 137, 135, 134, 132, 130, 128, 126, 124, 121, 119, 117, 114, 112, 109, 106, 104, 101, 98, 95, 92, 89, 86, 82, 79, 76, 72, 69, 66, 62, 59, 55, 51, 48, 44, 40, 36,
                    33, 29, 25, 21, 17, 14, 10, 6, 2, -2, -6, -10, -14, -17, -21, -25, -29, -33, -36, -40, -44, -48, -51, -55, -59, -62, -66, -69, -72, -76, -79, -82, -86, -89, -92, -95, -98, -101,
                    -104, -106, -109, -112, -114, -117, -119, -121, -124, -126, -128, -130, -132, -134, -135, -137, -138, -140, -141, -143, -144, -145, -146, -147, -147, -148, -149, -149,
                    -149, -150, -150, -150, -150, -150, -150, -149, -149, -148, -148, -147, -146, -145, -144, -143, -142, -141, -139, -138, -136, -134, -133, -131, -129, -127, -125, -123,
                    -120, -118, -116, -113, -110, -108, -105, -102, -99, -96, -93, -90, -87, -84, -81, -78, -74, -71, -67, -64, -60, -57, -53, -49, -46, -42, -38, -35, -31, -27, -23, -19, -15,
                    -12, -8};

int pasa = 0;

void Proceso();

void main()
{
    // Initialize 240x320 TFT display
    //GPIO_Config(&GPIOA_BASE, _GPIO_PINMASK_0 | _GPIO_PINMASK_1 | _GPIO_PINMASK_2 | _GPIO_PINMASK_3
    //                     | _GPIO_PINMASK_4,_GPIO_CFG_MODE_OUTPUT | _GPIO_CFG_SPEED_2MHZ | _GPIO_CFG_OTYPE_PP);
    //GPIO_Digital_Output(&GPIOA_BASE,_GPIO_PINMASK_0 | _GPIO_PINMASK_1 | _GPIO_PINMASK_2 | _GPIO_PINMASK_3 | _GPIO_PINMASK_4);
    GPIO_Config(&GPIOB_BASE, _GPIO_PINMASK_0 | _GPIO_PINMASK_1 | _GPIO_PINMASK_2 | _GPIO_PINMASK_3 | _GPIO_PINMASK_4 | _GPIO_PINMASK_5 | _GPIO_PINMASK_6 | _GPIO_PINMASK_7, _GPIO_CFG_MODE_OUTPUT | _GPIO_CFG_SPEED_2MHZ | _GPIO_CFG_OTYPE_PP);
    GPIO_Digital_Output(&GPIOB_BASE, _GPIO_PINMASK_0 | _GPIO_PINMASK_1 | _GPIO_PINMASK_2 | _GPIO_PINMASK_3 | _GPIO_PINMASK_4 | _GPIO_PINMASK_5 | _GPIO_PINMASK_6 | _GPIO_PINMASK_7);
    TFT_Init(240, 320);
    TFT_Init_ILI9341_8bit(240, 320);
    TFT_Fill_Screen(CL_BLACK);
    while (1) //Bucle principal
        Proceso();
}

void Proceso()
{
    //TFT_Write_Char('A', 5, 5);
    TFT_Set_Font(TFT_defaultFont, CL_WHITE, FO_HORIZONTAL);

    //TFT_Write_Text("TFT LIBRARY DEMO, WELCOME !", 5, 20);
    TFT_Set_Pen(CL_WHITE, 1);
    //TFT_Circle(120, 100, 50);
    //TFT_Rectangle_Round_Edges(5, 170, 235, 275, 12);

    if (pasa == 0)
    {
        for (i = 0; i < 242; i++)
            vector[i] = vector[i] / 2.5;

        for (i = 0; i < 242; i++)
            vector2[i] = (vector2[i] / 2.5) + 250;

        pasa = 1;
    }

    for (i = 0; i < 242; i++)
        TFT_Line(i, vector2[i], i + 1, vector2[i + 1]);

    for (i = 0; i < 242; i++)
        TFT_Line(i, vector[i], i + 1, vector[i + 1]);

    delay_ms(500);
}