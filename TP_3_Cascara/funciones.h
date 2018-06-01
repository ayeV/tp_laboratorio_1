#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int estado;
    char titulo[50];
    char genero[50];
    int duracion;
    char descripcion[200];
    int puntaje;
    char linkImagen[1000];
} eMovie;
/** Inicializa la estructura para poder hacer carga aleatoria
 *
 * \param movies puntero a estructura
 * \param tam tamanio del array
 */
void initMovies(eMovie* movies, int tam);

/**
 * Obtiene el primer indice libre del array de estructura.
 * @param movies el puntero array se pasa como parametro.
 * @return el primer indice disponible
 */
int buscarLibre(eMovie* movies);

/** Guarda la informacion cargada en el archivo binario
 *
 * \param x puntero a estructura
 * \return  0 o 1 si se pudo o no guardar el archivo
 *
 */

int guardarEnArchivo(eMovie * x);
/** Muestra una pelicula y su informacion
 *
 * \param movie puntero a estructura
*/
void mostrarPelicula(eMovie* movie);
/** Obtiene la opcion del menu elegida por el usuario
 *
 *
 * \return la opcion elegida por el usuario
 *
 */

int menuModificar();

/** Modifica los campos de una pelicula
 *
 * \param movies el puntero array se pasa por parametro
 */
void modificar(eMovie* movies);
/** \brief Carga la estructura al archivo binario
 *
 * \param x puntero a estructura
  * \return 0 o 1 de acuerdo a si se pudo o no abrir el fichero
 *
 */

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
