/*************************************************
 * Examen Practico de Fundamentos Programacion.
 * Grado de Telecomunicacion Curso 2014/2015.
 * !POR FAVOR, RELLENAD LOS SIGUIENTES DATOS!
 *
 * Apellidos: Sanchez Martinez
 *
 * Nombre: Cesar Daniel
 *
 * Fecha: 28/12/2015
 *
 * Ordenador:
 *
 * Problema: productoreales
 *
 *************************************************/

/**************************************************
Programa que, a partir de dos realies positivos, representados considerando un tamaño de 20 posiciones para los vectores de entrada, determina el real resultante de multiplicar estos reales
****************************************************/

#include <stdio.h>
#include <math.h>
#define DIM 1000

/**************************************************
LeerVector(int v[], int *util_v) Funcion que lee un vector y su util pasado por referencia, que sera el numero de componentes del dispositivo de entrada. Recorre el vector v y va haciendo scanf
*************************************************/

void LeerVector(int v[])
{
    int i;
    for(i=0;i<20;i++){
        scanf("%d", &v[i]);
    }
}

/*************************************************
float Pasarareal(int v[], int *posicion_coma) Funcion que, dado un vector y la posicion de la coma en el numero real, devolvemos el numero real con un bucle for suponiendo que el vector tiene 20 posiciones, y vamos multiplicando cada componente por la posicion respecto de la coma (pow(10,(*posicion_coma)-i-1))
***************************************************/

float Pasarareal(int v[], int *posicion_coma){
    int i;
    float numero;
    numero=0;
    
    scanf("%d", posicion_coma);
    
    for (i=0; i<20; i++)
        numero=numero+v[i]*pow(10,(*posicion_coma)-i-1);
    
    return numero;
}


/**************************************************
 float Multiplicar(int v1[], int v2[]) Funcion que recibe dos vectores de entrada, los pasa a numero real con la funcion Pasarareal y realiza el producto de los dos numeros reales
 *************************************************/

float Multiplicar(int v1[], int v2[])
{
    float numero1, numero2, producto;
    int posicion_coma1, posicion_coma2;
    
    LeerVector(v1);
    numero1=Pasarareal(v1, &posicion_coma1);
    LeerVector(v2);
    numero2=Pasarareal(v2, &posicion_coma2);
    
    producto=numero1*numero2;
    
    return producto;

}

int main(){
    int vector1[DIM], vector2[DIM];
    float producto;
    
    producto=Multiplicar(vector1, vector2);
    
    printf("%f", producto);
    
    return 0;
}










