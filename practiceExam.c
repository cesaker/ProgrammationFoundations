/*************************************************
* Examen Práctico de Fundamentos Programación.
* Grado de Telecomunicación Curso 2015/2016.
* !POR FAVOR, RELLENAD LOS SIGUIENTES DATOS!
*
* Apellidos:Sanchez Martinez
*
* Nombre:Cesar Daniel
*
* Fecha:19/1/16
*
* Ordenador:ei142155
*
* Problema:circulos
*
*************************************************/
#include <stdio.h>
#include <math.h>
#define DIM 1000

/**************************************************
Aqui definimos los puntos y los circulos
**************************************************/
struct Punto{
    int x,y;
};

struct Circulo{
    struct Punto centro;
    int radio;
};
/****************************************************
Aqui lo que hacemos es leer las coordenadas del circulo y su radio. Para ello lo que hacemos es obtener
un util del vector e ir coordenada a coordenada introduciendo los valores
****************************************************/
void LeerCirculo(struct Circulo v[], int *util_v){
    int i;

    scanf("%d", util_v);

    for (i=0; i<*util_v;i++){
        scanf("%d",&v[i].centro.x);
        scanf("%d",&v[i].centro.y);
        scanf("%d",&v[i].radio);
    }
}
/*********************************************************************************************************
Aqui, en la funcion LeerPunto lo que hacemos es introducir las coordenadas de un punto para luego poder
utilizarlo
**********************************************************************************************************/
void LeerPunto(struct Punto v[]){
    int i;
    scanf("%d", &v[i].x);
    scanf("%d", &v[i].y);

}
/******************************************************************************************
Esta funcion lo que hace es inicializar a 0 tanto el vector de circulos dentro como el de fuera, despues
lo que hacemos es utilizar la formula usada en el guion para poder ir añadiendo elementos tanto a los
vectores que estan dentro como a los que estan fuera.
********************************************************************************************/

void DentroFuera(struct Circulo v[], int util_v, struct Punto un_punto, struct Circulo vin[], int *util_vin, struct Circulo vout[], int *util_vout){

int i;

*util_vin=0;
*util_vout=0;

    for (i=0; i<util_v; i++){

        if ((pow((un_punto.x - v[i].centro.x),2)+pow((un_punto.y - v[i].centro.y),2))<=(pow((v[i].radio),2))){
            (*util_vin)++;
            vin[*util_vin-1]=v[i];
        }

        else{
                (*util_vout)++;
                vout[*util_vout-1]=v[i];
        }
    }
}
/****************************************************************************************
Esta funcion lo que hace es mostrar por pantalla los resultados, tanto de la primera coordenada, como de la segunda y
el radio del circulo
**************************************************************************************/

void MostrarVector(struct Circulo v[], int util_v){

    int i;

    for (i=0;i<util_v;i++){
        printf(" %d" " %d" " %d", v[i].centro.x, v[i].centro.y, v[i].radio);
        printf("\n");

    }

}

int main(){

struct Circulo vcirculos[DIM];
int util_circulos;
struct Circulo v[DIM];
struct Punto un_punto;
struct Circulo cirdentro[DIM];
struct Circulo cirfuera[DIM];
int util_dentro, util_fuera;

LeerCirculo(vcirculos, &util_circulos);
LeerPunto(&un_punto);
DentroFuera(vcirculos, util_circulos, un_punto, cirdentro, &util_dentro, cirfuera, &util_fuera);

printf("\nDENTRO\n");
MostrarVector(cirdentro, util_dentro);
printf("\nFUERA\n");
MostrarVector(cirfuera, util_fuera);

return 0;
}


