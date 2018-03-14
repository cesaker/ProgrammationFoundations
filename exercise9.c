/*************************************************
 * Examen Practico de Fundamentos Programacion.
 * Grado de Telecomunicacion Curso 2014/2015.
 * !POR FAVOR, RELLENAD LOS SIGUIENTES DATOS!
 *
 * Apellidos: Sanchez Martinez
 *
 * Nombre: Cesar Daniel
 *
 * Fecha: 9/01/2016
 *
 * Ordenador:
 *
 * Problema: circulos
 *
 *************************************************/

/**************************************************
 Programa cuya entrada es un vector de circulos V y un punto cualquiera que genera un vector con aquellos circulos que contienen el punto (Vin) y otro diferente con los circulos que no lo contienen (Vout)
 ***************************************************/

#include <stdio.h>
#include <math.h>

#define DIM 1000

/***************************************************
 struct Punto registra dos variables, x e y para almacenar las coordenadas de un punto en el plano
 ****************************************************/

struct Punto{
    
    int x, y;
    
};

/***************************************************
 struct Circulo define el circulo a traves del punto central y su radio
 ****************************************************/

struct Circulo{
    
    struct Punto centro;
    int radio;
    
};

/************************************************
 LeerCirculos(struct Circulo v[], int *util_v) Funcion que recibe el vector de enteros y su util util_v, leyendo el numero de circulos y pasandolo por referencia, e introduciendo los centros y radios desde 0 hasta el util en cada una de las variables del struct, ordenados en el vector
 ***********************************************/

void LeerCirculos(struct Circulo v[], int *util_v){
    
    int i;
    
    /* printf("Introduzca el numero de circulos: "); */
    scanf("%d", util_v);
    
    /* printf("Ahora, introduzca los centros y radios de los mismos"); */
    for(i=0;i<(*util_v);i++){
        scanf("%d", &v[i].centro.x);
        scanf("%d", &v[i].centro.y);
        scanf("%d", &v[i].radio);
    }
}


/***************************************************
 LeerPunto(struct Punto *punto) Funcion que lee un punto pasado por referencia y lo almacena en cada uno de los campos del struct
 ***************************************************/

void LeerPunto (struct Punto *punto){
    
    scanf("%d", &(*punto).x);
    scanf("%d", &(*punto).y);
    
}

/****************************************************
 DentroFuera(struct Circulo v[], int util_v, struct Punto un_punto, struct Circulo vin[], int              *util_vin, struct Circulo vout[], int *util_vout)
 Funcion que recibe un vector de circulos junto al numero de ellos (util_v), un punto cualquiera (un_punto), y determina, mediante dos vectores vin, vout y dos utiles pasados por referencia inicializados a cero util_vin y util_vout si un circulo contiene o no a ese punto. Recorriendo desde i=0 hasta el util, si se verifica la condicion para que el circulo este contenido o no, se incrementa uno u otro util para que a la hora de mostrarlo el bucle se pare correctamente y se introduce al vin o al vout restandole 1
 ****************************************************/

void DentroFuera(struct Circulo v[], int util_v, struct Punto un_punto, struct Circulo vin[], int  *util_vin, struct Circulo vout[], int *util_vout){
    
    int i;
    
    *util_vin=0;
    *util_vout=0;
    
    for (i=0; i<util_v; i++){
        if ((pow((un_punto.x-v[i].centro.x),2)+pow((un_punto.y-v[i].centro.y),2))<=pow((v[i].radio),2)){
            (*util_vin)++;
            vin[(*util_vin)-1]=v[i];
        }
        else{
            (*util_vout)++;
            vout[(*util_vout)-1]=v[i];
        }
    }
}

/*******************************************************
 MostrarVector(struct Circulo v[], int util_v) Funcion que imprime en el dispositivo de salida util_v lineas con los vectores almacenados en vin o en vout
 *****************************************************/

void MostrarVector(struct Circulo v[], int util_v){
    
    int i;
    
    for (i=0; i<util_v; i++)
        printf("%d " "%d " "%d\n", v[i].centro.x, v[i].centro.y, v[i].radio);
}

int main(){
    
    struct Circulo vcirculos[DIM];
    int util_circulos;
    struct Punto un_punto;
    struct Circulo circdentro[DIM];
    struct Circulo circfuera[DIM];
    int util_dentro, util_fuera;
    
    LeerCirculos(vcirculos, &util_circulos);
    LeerPunto(&un_punto);
    DentroFuera(vcirculos, util_circulos, un_punto, circdentro, &util_dentro, circfuera, &util_fuera);
    printf("DENTRO\n");
    MostrarVector(circdentro, util_dentro);
    printf("FUERA\n");
    MostrarVector(circfuera, util_fuera);
    
    return 0;
    
}



