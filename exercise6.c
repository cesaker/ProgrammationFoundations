/*************************************************
 * Examen Practico de Fundamentos Programacion.
 * Grado de Telecomunicacion Curso 2014/2015.
 * !POR FAVOR, RELLENAD LOS SIGUIENTES DATOS!
 *
 * Apellidos: Sanchez Martinez
 *
 * Nombre: César Daniel
 *
 * Fecha: 02/01/2016
 *
 * Ordenador:
 *
 * Problema: parimpar
 *
 *************************************************/

/***************************************************************************************************************
 Programa que recibe como entrada una cadena de caracteres y, tras quitar todos los espacios en blanco que
 aparezcan en ella, devuelve como salida si es un palindromo, es par, impar o ninguno
 ***************************************************************************************************************/

#include <stdio.h>
#include <string.h>
#define DIM 1000

/**************************************************************************************************************
 int NumeroComponentes(char v[]) Funcion que recibe una cadena de caracteres y aumenta el contador i (numero de
 componentes de la cadena de caracteres) mientras que no se encuentre el caracter '\0'
 **************************************************************************************************************/

int NumeroComponentes (char v[])
{
    int i;
    i=1;
    
    while(v[i]!='\0')
        i++;
    return i;
}


/***********************************************
 EliminarEspacios(char v[], int *util_v) Funcion que recibe una cadena de caracteres y su util pasado por referencia que, dese i=0 hasta i<util_v, si encuentra un caracter de espacio, lo muerva hasta el final de la cadena (para v[util_v], decremente el util en una unidad y tambien decremente el contador al haber eliminado el espacio
 ***********************************************/

void EliminarEspacios(char v[], int *util_v)
{
    int i;
    int j;
    
    for (i=0;i<(*util_v); i++){
        if(v[i]==' '){
            for (j=i;j<(*util_v);j++)
                v[j]=v[j+1];
            
            (*util_v)--;
            i--;
        }
    }

}

/*********************************************
 PalindromoParOImpar(char v[], int util_v) Funcion que comprueba si la cadena de caracteres sin espacios se lee igual de derecha a izquierda que de izquiera a derecha (palindromo). Para ello, hacemos un bucle for desde cero hasta la mitad de la cadena y, si se cumple que el caracter v[i] es distinto al caracter v[util_v-i-1], diremos que no es palindromo y saldriamos del bucle. Por ultimo, imprimimos por pantalla si es palindromo, par (si no es u palindormo, es de longitud par mayor de 2 y las dos letras centrales coinciden), impar (no es un palindromo, es de longitud impar mayor o igual a 3 y la primera letra coincide con la letra central de la cadena) o ninguno, dependiendo de lo que cumpla la cadena.
 *********************************************/

void PalindromoParOImpar(char v[], int util_v){
    
    int i;
    int palindromo;
    
    palindromo=1;
    for(i=0;(i<(util_v)/2)&&(palindromo);i++){
        if(v[i]!=v[util_v-i-1])
            palindromo=0;
    }
    
    if(palindromo)
        printf("PALINDROMO");
    else if ((!palindromo)&&((util_v%2)==0)&&(util_v>2)&&(v[(util_v/2)-1]==v[util_v/2]))
        printf("PAR");
    else if ((!palindromo)&&((util_v%2)==1)&&(util_v>=3)&&(v[0]==v[util_v/2]))
        printf("IMPAR");
    else
        printf("NINGUNO");
    
}


/******************************************
 MostrarVector(char v[], int util_v) Funcion que imprime en la salida una linea con las util_v componentes del vector de enteros v separadas por espacio. Recorre el vector v y va haciendo printf.
 *****************************************/

void MostrarVector(char v[], int util_v)
{
    int i;
    
    for (i=0;i<util_v;i++)
        printf("%c", v[i]);
}

int main(){
    char nombre[DIM];
    int componentes;
    
    gets(nombre);
    componentes=NumeroComponentes(nombre);
    EliminarEspacios(nombre, &componentes);
    PalindromoParOImpar(nombre, componentes);
    
    return 0;
}