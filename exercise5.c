/*************************************************
 * Examen Practico de Fundamentos Programacion.
 * Grado de Telecomunicacion Curso 2014/2015.
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
 * Problema: cabalistico
 *
 *************************************************/

/*************************************************************************************************************
 Programa que calcula el maximo multiplicador cabalistico de un numero n, MMC(n)= m
 *****************************************************************************************************************/

#include <stdio.h>
#include <math.h>

#define DIM 1000

/****************************************************************************************************************
 int ObtenerCifras(int numero) Funcion que, al introducir un numero, calculara sus cifras con un bucle en el
 que mientras la division entre 10 sea positiva, va sumando cifras al contador
 ****************************************************************************************************************/

int ObtenerCifras(int numero){
    
    int contador;
    contador=1;                                           /*Como mÌnimo habr· una cifra*/
    
    while((numero/10)>0){
        numero=numero/10;
        contador++;
    }
    
    return contador;
}

/************************************************************************************************************
 PasarCifraVector(int numero, int v[], int cifra) Funcion que, dado un numero y su numero de cifras, va
 dividiendo el numero entre el orden de magnitud (centenas, decenas de la primera cifra hasta la ultima del
 numero, quedandose con el resto de la division y guardando asÌ cifra a cifra el numero en un vector ordenado,
 *************************************************************************************************************/

void PasarCifraVector(int numero, int v[], int cifra){
    
    int i;
    int divisor;
    for(i=0;i<cifra;i++){
        divisor=pow(10,cifra-i-1);
        v[i]=numero/divisor;
        numero=numero%divisor;
    }
}

/**********************************************************************************************************************
 int Cabalistico(int numero) Funcion que, dado un numero, devuelve su MMC. Para ello, calcula sus cifras e introduce
 el numero cifra a cifra en un vector utilizando las funciones anteriores. DespuÈs, multiplica ese numero por n=1,
 pasandolo a vector al obtener las cifras,y se compara si el primer numero del vector original aparece en el
 segundo vector, despues el segundo numero del original, etc., mientras que se encuentre. Si no aparece alguna de las
 cifras en el vector del numero multiplicado o no tiene el mismo numero de cifras, se acabaria el bucle, mientras que
 si los digitos son los mismos pero en distinto orden, se aumenta n en 1 y se vuelve a operar con n=2.
 **********************************************************************************************************************/
int Cabalistico(int numero){
    
    int i;
    int j;
    int cifras_iguales;
    int cifra;
    int cifra_multiplo;
    int v1[DIM];
    int v2[DIM];
    int multiplo;
    int n;
    
    n=1;
    cifra=ObtenerCifras(numero);
    
    PasarCifraVector(numero,v1,cifra);
    
    do{
        
        multiplo=n*numero;
        cifra_multiplo=ObtenerCifras(multiplo);
        PasarCifraVector(multiplo,v2,cifra);
        
        cifras_iguales=1;
        
        for(i=0;((i<cifra)&&(cifras_iguales));i++){
            cifras_iguales=0;
            
            for(j=0;((j<cifra)&&(!cifras_iguales));j++){
                if(v1[i]==v2[j])
                    cifras_iguales=1;
            }
        }
        
        if(cifras_iguales)
            n++;
        else
            n--; /*Al no ser iguales tenemos m+1, por lo que restamos 1*/
        
    } while((cifras_iguales)&&(cifra==cifra_multiplo));
    
    return n;
}

int main(){
    int numero;
    int cabalistico;
    
    /* printf("Introduce un numero: ") */
    scanf("%d",&numero);
    cabalistico=Cabalistico(numero);
    printf("%d",cabalistico);
    
    return 0;
}





