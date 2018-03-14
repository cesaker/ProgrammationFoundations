/*************************************************
 * Examen Practico de Fundamentos Programacion.
 * Grado de Telecomunicacion Curso 2014/2015.
 * !POR FAVOR, RELLENAD LOS SIGUIENTES DATOS!
 *
 * Apellidos: Sanchez Martinez
 *
 * Nombre: Cesar Daniel
 *
 * Fecha: 02/01/2016
 *
 * Ordenador:
 *
 * Problema: mediana
 *
 *************************************************/

/***************************************************************************************************************
 Programa que obtiene la mediana (valor que deja el mismo numero de datos antes y despues de el, una vez
 ordenados estos) de un vector de enteros V de tamaÒo n.
 ***************************************************************************************************************/

#include <stdio.h>

#define DIM 1000

/***************************************************************************************************************
 LeerVector(int vector[], int *util_v) Funcion que lee un vector y un util util_vector pasado por referencia,
 que sera el numero de componentes del dispositivo de entrada. Recorre el vector v y va haciendo scanf
 ***************************************************************************************************************/

void LeerVector(int vector[], int *util_v)
{
    int i;
    
    /*printf("Introduzca el tamaño del vector");*/
    scanf("%d", util_v);
    
    for(i=0;i<(*util_v);i++)
        scanf("%d", &vector[i]);
}

/****************************************************************************************************************
 OrdenarVector(int v[], int util_v) Funcion que, dado un vector y su util util_v, lo recorre comparando parejas
 de componentes mediante dos bucles for, fijando la componente v[1] y comparando con v[0], v[1] ... hasta v[util_v-1]
 para ver cual de ellas es mayor, situando la menor a la izquierda. Despues, se fijara v[2], repitiendo el proceso
 hasta i<util_v, quedando el vector ordenado.
****************************************************************************************************************/

void OrdenaVector(int v[], int util_v)
{
    int i, j, aux;
    
    for (i=1; i<util_v; i++){
        for (j=0;j<util_v;j++){
            if(v[i]<v[j]){
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
        }
    }
}

/**************************************************************************************************************
 float Mediana(int v[], int util_v) Funcion que dado un vector v y su util util_v, lo ordena utilizando la funcion OrdenaVector y, si el util_v es impar, mediana toma el valor que ocupa la posicion central del vector y, si el util_v es par, la mediana es la media aritmetica de los dos datos que estan en el cetnro del vector ordenado, devolviendo al final la mediana.
 ***************************************************************************************************************/

float Mediana(int v[], int util_v)
{
    float mediana;
    
    OrdenaVector(v, util_v);
    
    if(util_v%2)
        mediana=v[util_v/2];
    else
        mediana=(v[(util_v/2)-1]+v[util_v/2])/2.0;
    
    return mediana;
}

int main(){
    
    int vector[DIM];
    int utilvector;
    float mediana;
    
    LeerVector(vector, &utilvector);
    mediana=Mediana(vector, utilvector);
    
    printf("%f", mediana);
    
    return 0;
}







