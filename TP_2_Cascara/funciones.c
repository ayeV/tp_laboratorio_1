#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"








int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int indice = 0;

    printf("%s",message);
    fflush(stdin);
    scanf("%[^\n]",input);

    while( strlen(input) < lowLimit || strlen(input) >hiLimit)
    {
        printf("%s", eMessage);
        fflush(stdin);
        scanf("%[^\n]",input);
    }
    if(*input >lowLimit || *input <hiLimit){
        return indice;
    }
    else{
        indice = -1;
        return indice;
    }



}



void inicializarPersonas(ePersona vec[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        vec[i].estado = 1;

    }
}


int obtenerEspacioLibre(ePersona lista[])
{
    int i;
    int indice = -1;

    for(i=0; i<20; i++)
    {
        if(lista[i].estado == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;


}


int buscarPorDni(ePersona lista[], int dni)
{
    int i;

    int indice = -1;
    for(i=0; i<3; i++)
    {
        if(lista[i].estado == 0 && lista[i].dni == dni )
        {
            indice = i;
            break;
        }
    }
    return indice;

}
void agregarPersona(ePersona vec[],int tam)
{
    ePersona nuevaPersona;
    int i;
    int flag = 0;
    int esta;
    int dni;
    int indice;
    char aux[15];

    system("cls");
    indice = obtenerEspacioLibre(vec);


    if(indice == -1)
    {
        printf("El sistema no admite mas personas\n");
    }
    else
    {
        printf("\nIngrese DNI: ");
        fflush(stdin);
        scanf("%s",aux);
        for(i=0 ; i<strlen(aux) ; i++)
        {
            if(!isdigit(aux[i]))
            {
                flag=1;
                while(flag==1)
                {
                    printf("\nIngrese DNI nuevamente: ");
                    fflush(stdin);
                    scanf("%s",aux);
                    i=-1;
                    flag=0;
                }
            }
        }
        dni=atoi(aux);

        esta = buscarPorDni(vec,dni);
        if(esta != -1 )
        {
            printf("\nEl dni %d ya esta dado de alta\n", dni);
            mostrarPersona(vec[esta]);
        }
        else
        {
            nuevaPersona.estado = 0;
            nuevaPersona.dni =dni;

            getString(nuevaPersona.nombre,"Nombre: ","Rango valido [2-50]",2,50);

        printf("\nIngrese edad: ");
        fflush(stdin);
        scanf("%s",aux);
        for( i=0 ; i<strlen(aux) ; i++)
        {
            if(!isdigit(aux[i]))
            {
                flag=1;
                while(flag==1)
                {
                    printf("\nIngrese edad nuevamente: ");
                    fflush(stdin);
                    scanf("%s",aux);
                    i=-1;
                    flag=0;
                }
            }
        }
        nuevaPersona.edad=atoi(aux);




            vec[indice] = nuevaPersona;
            printf("Alta exitosa\n");
        }
    }
}

void baja(ePersona vec[],int tam)
{
    int dni;
    char aux[15];
    int i;
    int flag = 0;
    char opc;
    int esta;

    system("cls");


        printf("\nIngrese DNI: ");
        fflush(stdin);
        scanf("%s",aux);
        for(i=0 ; i<strlen(aux) ; i++)
        {
            if(!isdigit(aux[i]))
            {
                flag=1;
                while(flag==1)
                {
                    printf("\nIngrese DNI nuevamente: ");
                    fflush(stdin);
                    scanf("%s",aux);
                    i=-1;
                    flag=0;
                }
            }
        }
    dni=atoi(aux);
    esta = buscarPorDni(vec, dni);
    if(esta == -1)
    {
        printf("DNI inexistente");
    }
    else
    {
        mostrarPersona(vec[esta]);
        do
        {
            printf("Confirma la baja? S/N\n");
            fflush(stdin);
            scanf("%c", &opc);
            opc = tolower(opc);
        }
        while(opc != 's' && opc != 'n');
        if(opc == 's')
        {
            vec[esta].estado = 1;
            printf("Baja exitosa\n");
        }
        else
        {
            printf("Se ha cancelado la baja\n");

        }
    }

}

void ordenarPorNombre(ePersona persona[], int tam)
{
    int i,j;
    ePersona aux;


    for (i = 0; i < tam - 1; i++)
    {

        for (j = i + 1; j < tam; j++)
        {
            if(strcmp(persona[i].nombre, persona[j].nombre)>0)
            {
                aux = persona[i];
                persona[i] = persona[j];
                persona[j] = aux;


            }
        }
    }
}

void mostrarPersonas(ePersona vec[], int tam)
{
    system("cls");
    printf("---Lista de Personas---\n\n");
    printf("DNI\t\tNombre\t\tEdad\n\n");
    for(int i=0; i< tam; i++)
    {
        if(vec[i].estado == 0)
        {
            mostrarPersona(vec[i]);
        }
    }
}
void mostrarPersona(ePersona vec)
{

    printf("%d\t\t%s\t\t%d\n", vec.dni, vec.nombre,vec.edad);
}

void graficar(int parametro1, int parametro2, int parametro3){
    int i;
    int max;
    int flag = 0;




    if(parametro1 >= parametro2 && parametro1 >= parametro3)
    {
        max = parametro1;
    }
    else{
        if(parametro2>= parametro1 && parametro2 >= parametro3)
        {
            max = parametro2;
        }
        else{
            max = parametro3;
        }
    }




        for(i=max;i>0;i--){
            if(i<= parametro1){
                    printf("*");

            }

            if(i<= parametro2){
                    flag = 1;
                printf("\t*");
            }

            if(i<= parametro3){
                if(flag == 0)
                    printf("\t\t*");
                if(flag == 1)
                    printf("\t*");
            }
            printf("\n");
        }


    printf("<18\t19-35\t>35\n");


}

