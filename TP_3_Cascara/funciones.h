#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    int estado;
    char titulo[50];
    char genero[50];
    int duracion;
    char descripcion[200];
    int puntaje;
    char linkImagen[1000];
}eMovie;
void initMovies(eMovie* movies, int tam);
int buscarLibre(eMovie* movies);
int guardarEnArchivo(eMovie * x);
void mostrarPelicula(eMovie* movie);
int menuModificar();
void modificar(eMovie* movies);
int cargarDesdeArchivo(eMovie *x);


/**
 *  Agrega una pelicula al archivo binario
 *  @param movies la estructura a ser agregada al archivo
 *
 */
void alta(eMovie movies[]);
/**
 *  Borra una pelicula del archivo binario
 *  @param movies puntero la estructura a ser eliminada al archivo
 *
 */
 void baja(eMovie* movies);


/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *
 */
void generarPagina(eMovie lista[]);

#endif // FUNCIONES_H_INCLUDED
int buscarPeli(eMovie* movies, char* tituloAux);
