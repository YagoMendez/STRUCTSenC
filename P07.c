#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define p printf
#define sc scanf
#define maxAlu 3

typedef struct{
    int legajo;
    char nombre[50];
    float notas[3];
    float promedio;
}alumno;

void ingreso(alumno*, int);
void mostrarMayor(alumno*);
int menu(int);

int main(){
    int count = 0, op, killswitch;

    alumno a[maxAlu] = {0, " ", 0};
    do{
        ingreso(a, count);
        count++;
    }while(count != maxAlu);

    mostrarMayor(a);

    /*do{
        killswitch= menu(op);
    }while(killswitch != 0);*/
    


    return 0;
}

void ingreso(alumno *a, int count){
    
    a[count].legajo = count+1;

    fflush(stdin);
    p("\nIngrese Nombre y apellido:\n");
    gets(a[count].nombre);

    p("\nIngrese la nota 1: ");
    sc("%f", &a[count].notas[0]);
    p("\nIngrese la nota 2: ");
    sc("%f", &a[count].notas[1]);
    p("\nIngrese la nota 3: ");
    sc("%f", &a[count].notas[2]);

    a[count].promedio = (a[count].notas[0]+a[count].notas[1]+a[count].notas[2]) / 3;
}

void mostrarMayor(alumno *a){
    float aux;
    int aux1;
    char auxstr[50];

    for(int i = 0; i < maxAlu; i++){
        for(int j = 1; j < maxAlu; j++){
            if(a[i].promedio < a[j].promedio){
                aux1 = a[i].legajo;
                a[i].legajo = a[j].legajo;
                a[j].legajo = aux1;

                aux = a[i].promedio;
                a[i].promedio = a[j].promedio;
                a[j].promedio = aux;

                aux = a[i].notas[0];
                a[i].notas[0] = a[j].notas[0];
                a[j].notas[0] = aux;

                aux = a[i].notas[1];
                a[i].notas[1] = a[j].notas[1];
                a[j].notas[1] = aux;

                aux = a[i].notas[2];
                a[i].notas[2] = a[j].notas[2];
                a[j].notas[2] = aux;

                strcpy(auxstr,a[i].nombre);
                strcpy(a[i].nombre, a[j].nombre);
                strcpy(a[j].nombre, auxstr);
            }
        }
    }

    p("\n\nEl mayor promedio es de : %.2f", a[0].promedio);
    p("\n Perteneciente al alumno %s de legajo %d, FELICITACIONES NIONIO!", a[0].nombre, a[0].legajo);
}

/*int menu(int op){
    int op;

    if(acum == 0){
        p("Bienvenido!\n");
    }

    p(" __________________________\n");
    p("| 1)  INGRESAR EMPLEADOS   |\n");
    p("|__________________________|\n");
    p("| 2)  MOSTRAR LISTADO      |\n");
    p("|__________________________|\n");
    p("| 0)  SALIR                |\n");
    p("|__________________________|\n");

    do{
        sc("%d", &op);

        if(op != 1 && op != 2 && op != 0){
            p("Entrada invalida, reintentelo:\n");
        }

    }while(op != 1 && op != 2 && op != 0);
    
    switch(op){
        case 1:
            ingreso(slaves, count);
            break;
        case 2:
            ordenarYmostrar(slaves, swap);
            break;
    }
    return op;
}*/