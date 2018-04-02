#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float x=0;
    float y=0;
    float respuesta;
    float respuesta1;
    float respuesta2;
    float respuesta3;
    float respuesta4;
    float respuesta5;
    int initVarX=0;
    int initVarY=0;

    while(seguir=='s')
    {   system("cls");
        printf("1- Ingresar 1er operando (A= %.2f)\n", x);
        printf("2- Ingresar 2do operando (B= %.2f)\n", y);
        printf("3- Calcular la suma (%.2f + %.2f)\n", x, y);
        printf("4- Calcular la resta (%.2f - %.2f)\n", x, y);
        printf("5- Calcular la division (%.2f/%.2f)\n", x, y);
        printf("6- Calcular la multiplicacion (%.2f*%.2f)\n", x, y);
        printf("7- Calcular el factorial (%.2f!)\n",x);
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("Primer operando: ");
                scanf("%f", &x);

                initVarX = 1;

                system("pause");
                break;
            case 2:

                printf("Segundo operando: ");
                scanf("%f", &y);
                initVarY = 1;

                system("pause");
                break;
            case 3:
                 respuesta = sumar(x,y);
                if(initVarX != 1 && initVarY != 1){
                printf("Debe ingresar operandos\n");
                system("pause");
                }
                else{
                printf("La suma de %.2f + %.2f es: %.2f\n", x, y,respuesta);

                system("pause");
                }
                break;
            case 4:

                respuesta = restar(x,y);
                 if(initVarX != 1 && initVarY != 1){
                printf("Debe ingresar operandos\n");
                system("pause");
                }
                else{
                printf("La resta de %.2f - %.2f es: %.2f\n", x, y, respuesta);
                system("pause");
                }
                break;
            case 5:
                 if(initVarX != 1 && initVarY != 1){
                printf("Debe ingresar operandos\n");
                system("pause");
                }
                else{
                    if(y == 0){
                    printf("Error, no se puede dividir por 0\n");
                    system("pause");
                    }
                    else{

                    respuesta = division(x,y);

                    printf("La division entre %.2f y %.2f es: %.2f\n", x, y, respuesta);

                    system("pause");
                    }
                }
                break;
            case 6:
                respuesta = multiplicacion(x,y);
                 if(initVarX != 1 && initVarY != 1){
                    printf("Debe ingresar operandos\n");
                    system("pause");
                }
                else{
                    printf("La multiplicacion entre %.2f y %.2f es: %.2f\n",x, y, respuesta);
                    system("pause");
                        }
                break;
            case 7:
                 if(initVarX != 1 && initVarY != 1){
                    printf("Debe ingresar operandos\n");
                    system("pause");
                    }
                else{
                        if ( (x != (int)x) == 1){
                        printf ("Error, debe ingresar nro entero!\n");
                        system("pause");
                        }
                        else
                        {
                        respuesta = factorial(x);

                        printf("El factorial de %d es: %d\n",(int)x,(int)respuesta);
                        system("pause");
                        }
                    }
                break;
            case 8:
                 if(initVarX != 1 && initVarY != 1){
                    printf("Debe ingresar operandos\n");
                    system("pause");
                }
                else{
                    respuesta1 = sumar(x,y);
                    printf("La suma de %.2f + %.2f es: %.2f\n", x, y,respuesta1);

                    respuesta2 = restar(x,y);
                    printf("La resta de %.2f - %.2f es: %.2f\n", x, y, respuesta2);



                   if(y==0){
                        printf("Error, no se puede dividir por 0\n");

                    }
                    else{
                        respuesta3 = division(x,y);
                        printf("La division entre %.2f y %.2f es: %.2f\n", x, y, respuesta3);
                    }
                     respuesta4 = multiplicacion(x,y);
                    printf("La multiplicacion entre %.2f y %.2f es: %.2f\n",x, y, respuesta4);

                    if ( (x != (int)x) == 1){
                        printf ("Error, debe ingresar nro entero!\n");
                        system("pause");
                    }
                    else
                    {    respuesta5 = factorial(x);

                        printf("El factorial de %d es: %d\n",(int)x,(int)respuesta5);
                        system("pause");
                    }
                }
                break;
            case 9:
                seguir = 'n';
                break;
        }

    }
    return 0;
}
