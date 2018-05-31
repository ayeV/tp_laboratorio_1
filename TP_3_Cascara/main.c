#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define ARCH	".\\movies.dat"
#define CANT 10


int main()
{
    eMovie movies[CANT];

    char seguir='s';
    char guardar= 's';
    int opcion=0;

    initMovies(movies,CANT);

	if(cargarDesdeArchivo(movies))
	{
		printf("No se pudo abrir el fichero");
	}
	else
	{
		printf("Se cargaron las estructuras con exito\n");
	}

	system("pause");


	system("cls");

    while(seguir=='s')
    {


        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("--AGREGAR PELICULA--\n");
                alta(movies);
                system("pause");
                break;
            case 2:
                printf("--BORRAR PELICULA--\n");
                baja(movies);
                system("pause");
                break;
            case 3:
                printf("--MODIFICAR PELICULA--\n");
                modificar(movies);
                system("pause");
                break;

            case 4:
                printf("--GENERAR PAGINA WEB--\n");
                generarPagina(movies);
                system("pause");
               break;
            case 5:
                printf("\nGuardar cambios S/N ?: ");
				guardar = tolower(getche());

				if(guardar == 's')
				{
					if(guardarEnArchivo(movies))
					{
						printf("\nNo se pudo abrir el fichero\n");
					}
					else
					{
						printf("\nSe guardo la informacion con exito\n");
					}
				}
                seguir = 'n';
                break;
        }
    }

    printf("\n");
	system("pause");
    return 0;
}
