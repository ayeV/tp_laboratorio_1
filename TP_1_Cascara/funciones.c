/** \funcion que suma dos numeros tipo float
 *
 * \param primero numero que recibe tipo float
 * \param segundo numero que recibe tipo float
 * \return resultado de la suma
 *
 */


float sumar(float a, float b){

    float resultado;
        resultado = a + b;

    return resultado;
}
/** \funcion que resta dos numeros tipo float
 * \param 1er numero tipo float
 * \param 2do numero tipo float
 * \return rsultado de la resta
 *
 */

float restar(float c, float d){
    float resultado;
        resultado = c-d;
    return resultado;

}
/** \brief funcion que divide dos numeros tipo float
 *
 * \param 1er nro tipo float
 * \param 2do nro tipo float
 * \return resultado de la division
 *
 */

float division (float e, float f){
    float resultado;

        resultado = e/f;
    return resultado;
  }
/** \brief funcion que multiplica dos nros
 *
 * \param 1er nro float
 * \param 2do nro float
 * \return resultado de la multiplicacion
 *
 */

float multiplicacion(float g, float h){
    float resultado;

    resultado = g*h;
    return resultado;
}
/** \brief funcion que calcula el factorial de un nro
 *
 * \param unico nro tipo float que recibe
 *
 * \return resultado del factorial
 *
 */

int factorial(int i){
    int resultado;
        if(i == 1){
            return 1;
        }
        resultado = i*factorial(i-1);

        return resultado;
}
