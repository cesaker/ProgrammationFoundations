/*************************************************
 * Examen Practico de Fundamentos Programacion.
 * Grado de Telecomunicacion Curso 2014/2015.
 * !POR FAVOR, RELLENAD LOS SIGUIENTES DATOS!
 *
 * Apellidos: Sanchez Martinez
 *
 * Nombre: Cesar Daniel
 *
 * Fecha: 16/01/2016
 *
 * Ordenador:
 *
 * Problema: frecuencias
 *
 *************************************************/

/***************************************************************************************************************
 Programa que acepta un vector de enteros, donde pueden repetirse numeros, que devuelva dos vectores:
 un vector ordenador con los enteros aparecidos sin repeticion y otro con las frecuencias de aparicion de
 los enteros en el vector ordenador
 ***************************************************************************************************************/

#include <stdio.h>

#define DIM 1000

/***************************************************************************************************************
 LeerVector(int vector[], int *util_v) Funcion que lee un vector y un util util_vector pasado por referencia,
 que sera el numero de componentes del dispositivo de entrada. Recorre el vector v y va haciendo scanf
 ***************************************************************************************************************/

void LeerVector(int vector[], int *util_vector){
    
    int i;
    
    /*printf("Introduzca la dimension del vector:");*/
    scanf("%d", util_vector);
    
    for(i=0;i<*util_vector;i++) {
        /*printf("Introduzca un numero:");*/
        scanf("%d", &vector[i]);
    }
}

/********************************************************************************************************************
 VectorNoRepetidos(int v[], int util_v, int vsinrep[], int *util_sinrep) Funcion que tiene como entrada un vector
 y su util, otro vector para guardar las componentes que no esten repetidas en el primer vector y su util
 util_sinrep pasado por referencia para almacenar el numero de componentes del vector sin repetidos.
 Para ello utilizamos un doble bucle for, en el que utiliza la primera componente del vector para ir comparandolas
 con las siguientes hasta util_v, mientras que no haya algun repetido. Si no lo hay, ese valor se almacena en
 vsinrep, incrementando util_sinrep en uno. Despues, pasariamos a la siguiente componente del vector original,
 repitiendo el proceso hasta i<util_v.
 ********************************************************************************************************************/

void VectorNoRepetidos(int v[], int util_v, int vsinrep[], int *util_sinrep){
    
    int i;
    int j;
    int no_repetido;
    
    *util_sinrep=0;
    
    for (i=0;i<util_v;i++){
        no_repetido=1;
        
        for (j=(i+1);(j<util_v)&&(no_repetido);j++){ /*Con un doble for vamos comparando si hay alg˙n elemento repetido*/
            if (v[i]==v[j]){
                no_repetido=0;         /*En cuanto veamos que est· repetido salimos del bucle*/
            }
        }
        
        if (no_repetido){   /*Creamos un nuevo vector para los elementos que no est·n repetidos*/
            vsinrep[*util_sinrep]=v[i];
            (*util_sinrep)++; /*Cada vez que entra un elemento al vector nuevo incrementamos sus dimensiones*/
        }
    }
}

/**********************************************************************************************************************
 VectorFrecuencias(int v[],int util_v, int vsinrep[],int util_sinrep, int vfrec[], int *util_vfrec) Funcion que tiene
 como entradas el vector de enteros y el vector que no repite numeros, junto a sus utiles, y un vector de frecuencias
 vfrec[] en el que iremos introduciendo el numero de veces que aparece los enteros del vector ordenado, junto con el
 util_vfrec pasado por referencia. Para ello, hacemos un doble bucle en el que para el primer numero del vector sin
 repeticiones se recorre todo el vector original, y si el numero coincide, aumenta la variable repeticiones en 1
 (inicializada a cero), introduciendo el valor en el vector de frecuencias. Se repetiria la operacion con cada
 numero del vector sin repeticiones.
 **********************************************************************************************************************/

void VectorFrecuencias(int v[],int util_v, int vsinrep[],int util_sinrep, int vfrec[], int *util_vfrec){
    
    int i;
    int j;
    int repeticiones;
    
    *(util_vfrec)=util_sinrep;
    
    for(i=0;i<util_sinrep;i++){
        repeticiones=0;
        
        for (j=0;j<util_v;j++){
            if (vsinrep[i]==v[j])
                repeticiones++;
        }
        
        vfrec[i]=repeticiones;
    }
}

/***********************************************************************************************************
 MostrarVector(int vector[], int util_vector) Funcion que imprime en la salida una linea con
 las util_v componentes del vector de enteros v separadas por espacio. Recorre el vector v y va haciendo printf.
 ************************************************************************************************************/

void MostrarVector(int vector[], int util_vector){
    
    int i;
    
    for(i=0;i<util_vector;i++){
        printf("%d ", vector[i]);
    }
}

/*******************************************************************************************************************
 OrdenarVector(int v[], int util_v) Funcion que, dado un vector y su util util_v, lo recorre comparando parejas
 de componentes mediante dos bucles for, fijando la componente v[1] y comparando con v[0], v[1] ... hasta v[util_v-1]
 para ver cual de ellas es mayor, situando la menor a la izquierda. Despues, se fijara v[2], repitiendo el proceso
 hasta i<util_v, quedando el vector ordenado.
 ********************************************************************************************************************/
void OrdenarVector(int v[],int util_v){
    
    int i;
    int j;
    int aux;
    
    for (i=1;i<util_v;i++){
        for(j=0;j<util_v;j++){
            if(v[i]<v[j]){
                
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
        }
    }
}

int main(){
    int vector[DIM];
    int util_vector;
    int vnorep[DIM];
    int util_norep;
    int vfrec[DIM];
    int util_vfrec;
    
    LeerVector(vector,&util_vector);
    
    VectorNoRepetidos(vector,util_vector,vnorep,&util_norep);
    OrdenarVector(vnorep,util_norep);
    VectorFrecuencias(vector,util_vector,vnorep,util_norep,vfrec, &util_vfrec);
    printf("VORDENADO\n");
    MostrarVector(vnorep,util_norep);
    printf("\n");
    printf("VFRECUENCIAS\n");
    MostrarVector(vfrec,util_vfrec);
    
    return 0;
    
}
