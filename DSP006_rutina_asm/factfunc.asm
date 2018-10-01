S;factfunc.asm Función en ensamblador que calcula n + (n-1) + ... + 1
                         .def _factfunc           ;Función llamada desde C
_factfunc:       MV       A4,A1          ;ajustar el contador en A1
                 SUB      A1,1,A1       ;decrementar la cuenta del bucle
LOOP:            MPYI     A4,A1,A4     ;acumulación en A4
                 NOP                         ;retardo para la terminar de realizar la multiplicación
                 SUB      A1,1,A1       ;decremento para la siguiente multiplicación
           [A1]        B          LOOP          ;salto a to LOOP si A1 # 0
                         NOP     5                  ;Cinco ciclos de retardo
                         B          B3                ;retorno al programa en C
                         NOP     5                  ;cinco ciclos de retardo
                        .end
