/*************************************************
 * Examen Practico de Fundamentos Programacion.
 * Grado de Telecomunicacion Curso 2014/2015.
 * !POR FAVOR, RELLENAD LOS SIGUIENTES DATOS!
 *
 * Apellidos: Sanchez Martinez
 *
 * Nombre: Cesar Daniel
 *
 * Fecha: 19/01/2015
 *
 * Ordenador:
 *
 * Problema: ordenar
 *
 *************************************************/

/***************************************************************************************************************
 Programa que ordena las columnas de una matriz M de enteros positivos de forma ascendente (de izquierda a
 derecha), de acuerdo a la media de los elementos de cada columna.
 ***************************************************************************************************************/
#include <stdio.h>

#define DIM_FIL 100
#define DIM_COL 100

/******************************************************************************************************************
 LeerMatriz(int matriz[][DIM_COLUMNAS], int *util_filas, int util_columnas) Funcion que, fijado un numero de
 columnas, recorre las filas que determinamos con util_filas y se introducen numeros en su correspondientes
 posiciones.
 ******************************************************************************************************************/

void LeerMatriz(int m[][DIM_COL], int *util_filas, int *util_columnas){
    
    int i;
    int j;
    
    /*printf("Introduzca el numero de filas:");*/
    scanf("%d", util_filas);
    /*printf("Introduzca el numero de columnas:");*/
    scanf("%d", util_columnas);
    
    for(i=0;i<(*util_filas);i++){
        for(j=0;j<(*util_columnas);j++)
            scanf("%d", &m[i][j]);
    }
    
}

/******************************************************************************************************************
 OrdenarMatriz(int m[][DIM_COL],int util_filas, int util_columnas) Funcion que calcula la media de cada columna
 mediante dos bucles for, fijando la columna y sumando todas las componentes de la misma hasta util_filas, asi con
 cada una de ellas, para despues con dos bucles for ordenar el vector de medias de menor a mayor. Si el vector a la
 derecha es menor,  con tres bucles for desde k=0 hasta k<util_v, transladamos ese vector a un vector auxiliar para
 pasar componente a componente la columna menor hacia la izquierda y guardar en la de la derecha ese vector auxiliar
 ******************************************************************************************************************/

void OrdenarMatriz(int m[][DIM_COL],int util_filas, int util_columnas){
    
    int i;
    int j;
    int k;
    float vmedias[DIM_FIL];
    int vaux[DIM_COL];
    float aux;
    float suma;
    
    for(i=0;i<util_columnas;i++){
        suma=0;
        
        for(j=0;j<util_filas;j++)
            suma=suma+m[j][i];
        
        vmedias[i]=suma/util_filas;
    }
    
    for(i=1;i<util_columnas;i++){
        for(j=0;j<util_columnas;j++){
            if(vmedias[i]<vmedias[j]){
                
                aux=vmedias[i];
                vmedias[i]=vmedias[j];
                vmedias[j]=aux;
                
                for(k=0;k<util_filas;k++)
                    vaux[k]=m[k][i];
                
                for (k=0;k<util_filas;k++)
                    m[k][i]=m[k][j];
                
                for (k=0;k<util_filas;k++)
                    m[k][j]=vaux[k];
                
            }
        }
    }
}

/**********************************************************************************************************************
 MostrarMatriz(int m[][DIM_COL], int util_filas, int util_columnas) Funcion que imprime en la salida una linea con
 las util_filas filas y las util_columnas columnas de la matriz. Recorre cada componente por fila y va haciendo printf.
 **********************************************************************************************************************/

void MostrarMatriz(int m[][DIM_COL], int util_filas, int util_columnas){
    
    int i;
    int j;
    
    for(i=0;i<util_filas;i++){
        for(j=0;j<util_columnas;j++)
            printf("%d ", m[i][j]);
        
        printf("\n");
    }
}

int main(){
    int matriz[DIM_FIL][DIM_COL];
    int util_filas;
    int util_columnas;
    
    LeerMatriz(matriz,&util_filas,&util_columnas);
    OrdenarMatriz(matriz,util_filas,util_columnas);
    MostrarMatriz(matriz, util_filas, util_columnas);
    
    return 0;
}















