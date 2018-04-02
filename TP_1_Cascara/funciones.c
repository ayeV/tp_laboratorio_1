//sumar recibe dos numeros float, los suma y retorna resultado de tipo float

float sumar(float a, float b){

    float resultado;
        resultado = a + b;

    return resultado;
}
//restar recibe dos float, los resta y retorna el resultado de tipo float
float restar(float c, float d){
    float resultado;
        resultado = c-d;
    return resultado;

}
//division recibe dos float, los divide, y retorna el resultado tipo float
float division (float e, float f){
    float resultado;

        resultado = e/f;
    return resultado;
  }
//multiplicacion recibe dos float, los multiplica y retorna el resultado tipo float
float multiplicacion(float g, float h){
    float resultado;

    resultado = g*h;
    return resultado;
}
//factorial recibe un parametro tipo entero, calcula el factorial y retorna el resultado de tipo entero
int factorial(int i){
    int resultado;
        if(i == 1){
            return 1;
        }
        resultado = i*factorial(i-1);

        return resultado;
}
