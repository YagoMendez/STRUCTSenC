#include <string.h>
#include <ctype.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<time.h>
#define p printf
#define sc scanf
#define MAXALUMNO 30

typedef struct{
    int legajo;
    char alumno[30];
    float nota;
}registro;

int menu(void);
void mostrarAlumnos(registro*, int);
int cargarAlumnos(registro*, int);
void sumaPromedio(registro*, int);

int main(){
    
    menu();
    
    return 0;
}

int menu(){
    int op;
    int acum = 0, count = 0;
    registro clase[MAXALUMNO];

    for(int i = 0; i < MAXALUMNO; i++){

        clase[i].nota = 0;
    }

    do{
        if(acum == 0){
            system("cls");
            p("Bienvenido! Ingrese la opcion deseada:\n\n");
        }

        p("\n1) Ingresar un alumno\n\n");
        p("2) Mostrar Promedio de Notas de los alumnos\n\n");
        p("3) Mostrar Listado de alumnos con sus respectivas notas\n\n");

        sc("%d", &op);

        switch(op){
            case 1:
                acum = cargarAlumnos(clase, acum);
                break;
            case 2:
                sumaPromedio(clase, acum);
                break;    
            case 3:
                mostrarAlumnos(clase, acum);
                break;    
        }
        
    }while(op > 0 && op < 4);
}

int cargarAlumnos(registro clase[], int acum){


    p("\nIngrese el Legajo o presione 0 para salir:\n");
    sc("%d", &clase[acum].legajo);
    fflush(stdin);
    p("Ingrese Nombre y Apellido:\n");
    gets(clase[acum].alumno);
    fflush(stdin);

    if(strlen(clase[acum].alumno) > 30){
       p("Limite su nombre a 30 caracteres\n");
       Sleep(1);
       p("Ingrese Nombre y Apellido:\n");
       gets(clase[acum].alumno);
       fflush;
    }

    p("Ingrese la nota:\n");
    sc("%f", &clase[acum].nota);

    acum++;

    return acum;
}

void sumaPromedio(registro clase[], int acum){
    float prom = 0, sum = 0;

    for(int i = 0; i < acum; i++){
        
        sum+=clase[i].nota; 
    }

    prom = sum / (float)(acum);

    p("El promedio de todos los alumnos unidos es: %1.2f\n", prom);
    sleep(2);
}

void mostrarAlumnos(registro clase[], int acum){
    float aux;
    char aux1;

    for (int i = 0; i < acum; i++){//Orden de los alumnos segun promedio

        for(int j = 1; j <= acum; j++){
            if(clase[j].nota > clase[i].nota){
                aux = clase[j].nota;
                clase[j].nota = clase[i].nota;
                clase[i].nota = aux;

                strcpy(aux1,clase[j].alumno);
                strcpy(clase[j].alumno,clase[i].alumno);
                strcpy(clase[i].alumno,aux1);

                aux = clase[j].legajo;
                clase[j].legajo = clase[i].legajo;
                clase[i].legajo = aux;
            }
        }
    }

    p("Listado de Alumnos segun Promedio:\n");
    p("|\tLEGAJO\t|\tNOMBRE Y APELLIDO\t|\tPROMEDIO\t|\n");

    for(int i = 0; i < acum; i++){
        p("|\t%d\t|\t%s\t\t|\t%1.2f\t\n",clase[i].legajo, clase[i].alumno, clase[i].nota);
    }
}