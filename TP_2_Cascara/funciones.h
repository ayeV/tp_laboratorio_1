#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{

    char nombre[51];
    int edad;
    int estado;
    int dni;

} ePersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePersona lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(ePersona lista[], int dni);


/**
 * Inicializa el array de personas
 * \param vec el array se pasa por parametro
 * \param tam tamanio del array
 */

void inicializarPersonas(ePersona vec[], int tam);

/**
 * Muestra una sola persona
 * \param vec array se pasa por parametro
 */
void mostrarPersona(ePersona vec);

/**
 * Agrega una persona al sistema
 * \param vec array se pasa por parametro
 * \param tam tamanio que recibe el array se pasa por paramrtro
 */
void agregarPersona(ePersona vec[], int tam);

/**
 * Borra a una persona del sistema
 * \param vec array se pasa por parametro
 * \param tam tamanio que recibe el array se pasa por parametro
 */
void baja(ePersona vec[], int tam);

/**
 * Ordena el array nombre alfabeticamente
 * \param persona array se pasa por parametro
 * \param tam tamanio que recibe el array se pasa por parametro
 * \return
 *
 */
void ordenarPorNombre(ePersona persona[], int tam);

/**
 * Muestra una Lista de personas agregadas
 * \param persona array se pasa por parametro
 * \param tam tamanio que recibe el array se pasa por parametro
 *
 * \return
 *
 */
void mostrarPersonas(ePersona persona[],int tam);


/**
 * Muestra una sola persona
 * \param vec variable que representa una sola persona
 * \param
 * \return
 *
 */
void mostrarPersona(ePersona vec);


/** \brief
 *
 * \param parametro 1 es el primer parametro del grafico
    * \param parametro 2 es el segundo parametro del grafico
 * \param parametro 3 es el tercer parametro del grafico
 */
void graficar(int parametro1, int parametro2, int parametro3);


/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit);

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit);

/**
* \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el caracter [0] si no [-1]
*
*/
int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit);


/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);

#endif // FUNCIONES_H_INCLUDED
