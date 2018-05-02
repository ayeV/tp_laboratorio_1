#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANT 3

int main()
{
    char seguir='s';
    int opcion=0;
    ePersona personas[CANT];
    int i;
    int contadorMenor18=0;
    int contador19a35=0;
    int contadorMayor35=0;


    inicializarPersonas(personas,CANT);
    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            printf("--Agregar persona--\n");

            agregarPersona(personas,CANT);

            system("pause");

            break;
        case 2:
            printf("--Borrar Persona--\n");

            baja(personas,CANT);
            system("pause");
            break;
        case 3:
            printf("--Listado--\n\n");
            ordenarPorNombre(personas,CANT);
            mostrarPersonas(personas,CANT);
            system("pause");
            break;
        case 4:


    for(i=0; i<CANT; i++)
    {
        if(personas[i].edad<=18)
        {
            contadorMenor18++;
        }
        else if(personas[i].edad>= 19 && personas[i].edad <=35)
        {
            contador19a35++;
        }
        else
        {
            contadorMayor35++;
        }

    }

            graficar(contadorMenor18,contador19a35,contadorMayor35);



                system("pause");
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
