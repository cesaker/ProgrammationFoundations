/*************************************************
 * Examen Practico de Fundamentos Programacion.
 * Grado de Telecomunicacion Curso 2013/2014.
 * !POR FAVOR, RELLENAD LOS SIGUIENTES DATOS!
 *
 * Apellidos: Sánchez Martínez
 *
 * Nombre: César Daniel
 *
 * Fecha: 30/12/2015
 *
 * Ordenador: Macbook Air
 *
 * Problema: libreria
 *
 *************************************************/
/*************************************************/
/*Programa para aceptar un vector de libros y lo */
/*ordenepor año de publicacion de forma          */
/*ascendente                                     */
/*************************************************/

#include <stdio.h>

#define DIM 1000

/****************************************************

struct libro. Para cada libro se mantiene un unico identificador numerico y el año de publicacion.

******************************************************/

struct libro{
    int id;
    int a_pub;
};


/***************************************************

LeerVector(struct libro v[], int *util_v) Funcion que lee un vector y un util pasado por referencia, que 
sera el numero de componentes del dispositivo de entrada. Recorre el vector v y va haciendo scanf, 
introduciendo cada valor a las 2 variables del struct

***************************************************/

void LeerVector(struct libro v[], int *util_v)
{
    int i;
    
    /*printf("Introduzca la dimension del vector:");*/
    scanf("%d", util_v);
    
    for (i=0; i<(*util_v); i++){
        scanf(" %d", &v[i].id);
        scanf(" %d", &v[i].a_pub);
    }
}


/****************************************************
 
OrdenarVector(int v[], int util_v) Funcion que, dado un vector y su util_v, lo recorre comparando parejas de componentes mediante bucles for, fijando la componente v[1].a_pub y comparando con v[0]a_pub, v[1]a_pub ... hasta v[util_v-1] para ver cual de ellas es mayor, situando la menor a la izquierda. Si son iguales, se comprueba cual de los dos libros tiene el id mas grande, colocando el mayor a la izquierda. Despues, se fijara v[2]a_pub, repitiendo el proceso hasta i<util_v, quedando el vector ordenado ascendentemente en año de publicacion y, si coincide el año en algunos, ordenados descendentemente por sus identificadores.
 
 *****************************************************/


void OrdenaVector(struct libro v[], int util_v)
{
    int i;
    int j;
    struct libro aux;
 
    for(i=1; i<util_v; i++){
        for(j=0; j<util_v; j++){
            if((v[i].a_pub)<(v[j].a_pub)){
                
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
            
            else if ((v[i].a_pub)==(v[j].a_pub)){
                if ((v[i].id)>(v[j].id)){
                    
                    aux=v[i];
                    v[i]=v[j];
                    v[j]=aux;
                }
            }
        }
    }
}


/***************************************************
 
 MostrarVector(int vector[], int util_v) Funcion que imprie en la salida una linea con las util_v componentes del vector de enteros v separadas por espacio. Recorre el vector v y va haciendo printf.
 
 **************************************************/

void MostrarVector (struct libro v[], int util_v)
{
    
    int i;
    
    for (i=0; i<util_v; i++)
        printf("%d %d\n", v[i].id, v[i].a_pub);
}

int main(){
    
    struct libro vector[DIM];
    int util_v;
    
    LeerVector(vector, &util_v);
    OrdenaVector(vector, util_v);
    MostrarVector(vector, util_v);
    
    return 0;
}




















