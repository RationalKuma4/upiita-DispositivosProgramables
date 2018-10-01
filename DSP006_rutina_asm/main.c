/*//sumatoria.c cuentra n+(n-1)+...+1.
 //El programa llama la función ASM sumfunc
 #include <stdio.h>

 short sumfunc(short n);
 short i=0;
 main()
 {
 short n=6;
 short result;

 //c
 for(i=0; i<n; i++)
 {
 result=result+1+i;
 }

 result=0;
 result = sumfunc(n)S;
 printf("sum = %d", result);
 }*/
//factorial.c Encuentra n(n-1)(n-2)...1.
//El programa llama a la function factfunc.asm
#include <stdio.h>

short sumfunc(short n);
int i = 0, j = 0;

void main()
{
    int n = 3;                                        //Ajustar el valor n
    int result=0;                                  //resultado de la función asm

    //factorial en c
    /*if (n < 0)
        ;
    else
    {
        for (i = 1; i <= n; ++i)
        {
            result *= i;              // factorial = factorial*i;
        }
    }

    //printf("factorial = %d", result);

    result = 0;*/
    printf("factorial = %d", result);
    //result = sumfunc(n);
    ;//llamado a la función asm
    printf("factorial = %d", result); //Impresión del resultado de la función asm
}
