#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<conio.h>
#include "funciones.h"
#include "input.h"
#define CANT 10

void initMovies(eMovie* movies, int tam)
{
    int i;

    if(movies != NULL && tam > 0)
    {
        for(i=0; i<tam; i++)
        {
            (movies+i)->estado = 0;
        }
    }
}
int buscarLibre(eMovie* movies)
{
    int indice = -1;
    int i;
    for(i=0; i<CANT; i++)
    {
        if((movies+i)->estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}



int guardarEnArchivo(eMovie * x)
{

    FILE *f;

    f=fopen("movies.dat","wb");
    if(f == NULL)
    {
        return 1;
    }

    fwrite(x,sizeof(eMovie),CANT,f);

    fclose(f);

    return 0;
}




void mostrarPelicula(eMovie* movie)
{


    printf("TITULO\t\tGENERO\tDURACION\tDESCRIPCION\t\tPUNTAJE\tLINK\n");
    printf("%s\t%s\t%d\t%s\t%d\t%s\n", movie->titulo, movie->genero, movie->duracion,movie->descripcion,movie->puntaje,movie->linkImagen);
}






void mostrarPeliculas(eMovie* movies, int tam)
{
    int i;
    printf("TITULO\tGENERO\tDURACION\tDESCRIPCION\t\tPUNTAJE\n");
    if(movies != NULL && tam > 0)
    {
        for( i=0; i< tam; i++)
        {

            if((movies+ i)->estado)
            {
                mostrarPelicula(movies+i);
            }
        }
    }
    else
    {
        printf("\nNo se pueden mostrar las peliculas\n");
    }

}

void alta(eMovie movies[])
{
    int index, i;
    char tituloAux[50];
    eMovie nuevaPeli;
    int encontro=0;
    /*Buscamos cual es el primer indice libre dentro del array*/
    index=buscarLibre(movies);
    if(index!=-1)//si hay lugar:
    {

        printf("INGRESO DE DATOS:\n");
        getString(tituloAux,"Titulo: ", "Error, rango valido 2-50",2,50);
        strlwr(tituloAux);
        /*Buscamos si el titulo ya existe*/

        for(i=0; i<CANT; i++)
        {
            if((strcmp(tituloAux,movies[i].titulo))==0)
            {
                encontro=1;//encontro en true
                break;
            }
        }
        if(!encontro)//entra si encontro==0
        {
            nuevaPeli.estado = 1;
            strcpy(nuevaPeli.titulo,tituloAux);
            getString(nuevaPeli.genero, "Genero: ","Error, rango valido 2-50",2,50);
            getInt(&nuevaPeli.duracion,"Duracion: ","Error, rango valido 5-180",5,180);
            getString(nuevaPeli.descripcion, "Descripcion: ","Error, rango valido 2-200",2,200);
            getInt(&nuevaPeli.puntaje,"Puntaje: ","Error, rango valido 0-10",0,10);
            getString(nuevaPeli.linkImagen, "Link: ","Error, rango valido 2-1000",2,1000);


            movies[index] = nuevaPeli;

            system("cls");
        }
        else
        {
            printf("­­El titulo ingresado ya existe!!");
            getch();
        }
    }
    else
    {
        printf("No queda espacio");
        getch();
    }
}

void baja(eMovie* movies)
{
    int flag=0;
    int i;
    char tituloAux[50];
    char opcion;

    getString(tituloAux,"Pelicula a dar de baja: ", "Error, rango valido 2-50",2,50);
    strlwr(tituloAux);


    for(i=0; i<CANT; i++)
    {
        if((strcmp(tituloAux,movies[i].titulo))==0)
        {
            printf("Datos a eliminar:\n");

            mostrarPelicula((movies+i));

            do
            {
                printf("Confirma la baja? S/N\n");
                fflush(stdin);
                scanf("%c", &opcion);
                opcion = tolower(opcion);
            }while(opcion != 's' && opcion != 'n');


            if(opcion=='s')
            {
                movies[i].estado=0;
                printf("­­Pelicula eliminada con exito--\n");
                mostrarPeliculas(movies, CANT);
            }
            else
            {
                printf("--Ha cancelado la baja--\n");
            }
            flag=1;
            break;
        }
    }
if( flag == 0)
    {
        printf("Pelicula inexistente\n");
        getch();
    }


}


int menuModificar()
{

    int opcion;

    system("cls");
    printf("---MODIFICAR PELICULA---\n\n");
    printf("1-Titulo\n");
    printf("2-Genero\n");
    printf("3-Duracion\n");
    printf("4-Descripcion\n");
    printf("5-Puntaje\n");
    printf("6-Link imagen\n");
    printf("7-Salir\n");
    printf("\nIndique opcion: ");
    scanf("%d", &opcion);

    return opcion;


}
void modificar(eMovie* movies)
{
    int salir=0;
    int i;
    int flag = 0;

    char tituloAux[50];
    eMovie peliModificada;

    char opcion;
    system("cls");
    getString(tituloAux,"Pelicula a modificar: ", "Error, rango valido 2-50",2,50);
    strlwr(tituloAux);
    for(i=0; i<CANT; i++)
    {
        if((strcmp(tituloAux,movies[i].titulo))==0 && movies[i].estado == 1)
        {

            printf("Pelicula a modificar:\n");

            mostrarPelicula(movies+i);


            do
            {
                printf("Confirma la modificacion? S/N\n");
                fflush(stdin);
                scanf("%c", &opcion);
                opcion = tolower(opcion);
            }
            while(opcion != 's' && opcion != 'n');

            if(opcion=='s')
            {
                do
                {
                    switch(menuModificar())
                    {
                    case 1:
                        getString(peliModificada.titulo,"Nuevo titulo: ","Rango valido[2-50]",2,50);
                        strcpy(movies[i].titulo, peliModificada.titulo);
                        break;
                    case 2:
                        getString(peliModificada.genero,"Nuevo genero: ","Rango valido[2-50]",2,50);
                        strcpy(movies[i].genero, peliModificada.genero);

                        break;
                    case 3:
                        getInt(&peliModificada.duracion,"Nueva duracion: ","Rango valido [2-180]",2,180);
                        movies[i].duracion = peliModificada.duracion;
                        break;
                    case 4:
                        getString(peliModificada.descripcion,"Nueva descripcion: ","Rango valido[2-50]",2,50);
                        strcpy(movies[i].descripcion, peliModificada.descripcion);
                        break;
                    case 5:
                        getInt(&peliModificada.puntaje,"Nuevo puntaje: ","Rango valido [0-10]",0,10);
                        movies[i].puntaje = peliModificada.puntaje;
                        break;
                    case 6:
                        getString(peliModificada.linkImagen,"Nuevo link: ","Rango valido[2-1000]",2,1000);
                        strcpy(movies[i].linkImagen, peliModificada.linkImagen);
                        break;
                    case 7:
                        salir = 1;
                        break;
                    default:
                        printf("Ingrese una opcion correcta [1-7]");
                        break;
                    }
                }
                while(salir != 1);
                printf("\nSe ha realizado la modificacion\n\n");
                mostrarPelicula(movies+i);
            }

            else
            {
                printf("\nSe ha cancelado la modificacion\n\n");
            }
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        printf("Pelicula inexistente\n");

    }
}


void generarPagina(eMovie lista[])
{

    int i;
    FILE* f;


    f = fopen("index.html", "w");
    fprintf(f,"<!DOCTYPE html><!-- Template by Quackit.com --><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags --><title>Lista peliculas</title><!-- Bootstrap Core CSS --><link href='css/bootstrap.min.css' rel='stylesheet'><!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles --><link href='css/custom.css' rel='stylesheet'><!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries --><!-- WARNING: Respond.js doesn't work if you view the page via file:// --><!--[if lt IE 9]><script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script><![endif]--></head><body><div class='container'><div class='row'>");
    for(i=0; i<CANT; i++)
    {

        if(lista[i].estado == 1)
        {
            fprintf(f,"	<!-- Repetir esto para cada pelicula --><article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a><h3><a href='#'>%s</a></h3><ul><li>GENERO: %s</li><li>PUNTAJE: %d</li><li>DURACION: %d</li></ul><p>SINOPSIS: %s</p></article><!-- Repetir esto para cada pelicula -->",lista[i].linkImagen,lista[i].titulo,lista[i].genero,lista[i].puntaje,lista[i].duracion,lista[i].descripcion);
        }


    }
    fprintf(f,"</div><!-- /.row --></div><!-- /.container --><!-- jQuery --><script src='js/jquery-1.11.3.min.js'></script><!-- Bootstrap Core JavaScript --><script src='js/bootstrap.min.js'></script><!-- IE10 viewport bug workaround --><script src='js/ie10-viewport-bug-workaround.js'></script>	<!-- Placeholder Images --><script src='js/holder.min.js'></script></body></html>");







    fclose(f);
}



int cargarDesdeArchivo(eMovie *x)
{
	int flag = 0;
	FILE *f;

	f=fopen("movies.dat", "rb");
	if(f==NULL)
	{
		f= fopen("movies.dat", "wb");
		if(f==NULL)
		{
			return 1;
		}

		flag=1;

	}

	if(flag ==0)
	{
	fread(x,sizeof(eMovie),CANT,f);
    }

	fclose(f);
	return 0;

}









