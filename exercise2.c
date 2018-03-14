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
 * Problema: cercana
 *
 *************************************************/

/***********************************************************************************************************
 Programa que acepta un vector de enteros, una matriz de enteros y un vector vectorfilas que contiene
 indices de filas de la matriz y encuentra el indice de la fila mas cercana al vector V entre las filas
 cuyos indices estan contenidos en el vector vectorfilas.
 **********************************************************************************************************/

#include <stdio.h>
#include <math.h>

#define DIM_FILAS 100
#define DIM_COLUMNAS 100

/***************************************************************************************************************
 LeerVector(int vector[], int *util_v) Funcion que lee un vector y un util util_vector pasado por referencia,
 que sera el numero de componentes del dispositivo de entrada. Recorre el vector v y va haciendo scanf
 ***************************************************************************************************************/

void LeerVector(int vector[], int *util_vector){
    
    int i;
    
    /* printf("Introduzca la dimension del vector:"); */
    scanf("%d", util_vector);
    
    for(i=0;i<*util_vector;i++) {
        /*printf("Introduzca un numero:");*/
        scanf("%d", &vector[i]);
    }
}

/******************************************************************************************************************
 LeerMatriz(int matriz[][DIM_COLUMNAS], int *util_filas, int util_columnas) Funcion que, fijado un numero de
 columnas, recorre las filas que determinamos con util_filas y se introducen numeros en su correspondientes
 posiciones.
 ******************************************************************************************************************/

void LeerMatriz(int matriz[][DIM_COLUMNAS], int *util_filas, int util_columnas){
    
    int i;
    int j;
    
    /*printf("Introduzca las filas de la matriz M");*/
    scanf("%d",util_filas);
    
    for(i=0;i<*util_filas;i++){
        for(j=0;j<util_columnas;j++){
            /*printf("Introduzca el numero en la posicion %d %d", i,j);*/
            scanf("%d", &matriz[i][j]);
        }
    }
}

/*****************************************************************************************************************
 int Cercana(int v[], int util_v, int vfilas[], int util_vfilas, int m[][DIM_COLUMNAS], int util_filasm)
 Funcion que, dado un vector de enteros, una matriz de enteros y un vector vectorfilas, junto a sus
 correspondientes utiles util_v, util_vfilas y util_filasm, calcula la distancia mas cercana al vector
 (con distancia euclidea menor)
 *****************************************************************************************************************/

int Cercana(int v[], int util_v, int vfilas[], int util_vfilas, int m[][DIM_COLUMNAS], int util_filasm){
    
    int i;
    int j;
    int fila_cercana;
    float distancia;
    float d_min;
    
    distancia=0;
    i=vfilas[0];
    
    for(j=0;j<util_v;j++){
        distancia=distancia+pow((v[j]-m[i][j]),2);
    }
    
    distancia=sqrt(distancia);
    
    d_min=distancia;
    fila_cercana=vfilas[0];
    
    for(i=1;i<util_vfilas;i++){
        distancia=0;
        
        for(j=0;j<util_v;j++){
            distancia=distancia+pow((v[j]-m[vfilas[i]][j]),2);
        }
        
        distancia=sqrt(distancia);
        
        if(distancia<d_min){
            d_min=distancia;
            fila_cercana=vfilas[i];
        }
    }
    
    return fila_cercana;
}

int main(){
    int vector[DIM_FILAS];
    int util_v;
    int vectorfilas[DIM_FILAS];
    int util_vfilas;
    int m[DIM_FILAS][DIM_COLUMNAS];
    int util_filasm;
    int cercana;
    
    LeerVector(vector,&util_v);
    LeerVector(vectorfilas, &util_vfilas);
    LeerMatriz(m,&util_filasm,util_v);
    
    cercana=Cercana(vector,util_v,vectorfilas,util_vfilas,m,util_filasm);
    
    printf("%d",cercana);
    
    return 0;
}