#include <string.h>
#include <ctype.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<unistd.h>
#define p printf
#define sc scanf
#define cantAlum 100

typedef struct 
{
    int cod[50];
    char apyno[100];
    int promedio[50];
} registro;

int menu(registro*, int, int*);
int ingreso(registro*, int*);
void mostrarAlumnos(registro*, int*);
void concatenar(registro*, char[], char[], int*);


int main(){

    int acum = 0, *flag = 0, killswitch, ingresados = 0;

    srand(time(NULL));
    flag = &ingresados;
    
    registro alumno[cantAlum] = {0 ," ", 0};

    do{
        killswitch = menu(alumno, acum, flag);
        acum++;
        *flag++;
    }while(killswitch != 0);
    
    

    return 0;
}

int menu(registro *alumno, int acum, int *flag){
    int op;

    do{
        if(acum == 0){
            p("Bienvenido! Ingrese la opcion deseada o presione 0 para salir!\n\n");
        }else{
            p("\nIngrese la opcion deseada o presione 0 para salir!\n\n"); 
        }

        p("1) INGRESO DE ALUMNOS\n\n");
        p("2) MOSTRAR ALUMNOS\n\n");
        p("0) SALIR\n");
        sc("%d", &op);

        if(op > 2 || op < 0){

            p("Opcion invalida, reintentelo");

        }else{

            switch(op){
            case 1:
                ingreso(alumno, &flag);
                break;
            case 2:
                mostrarAlumnos(alumno, &flag);
                break;  
            }
        }
    }while(op > 2 || op < 0);
   
    return op;
}

int ingreso(registro *alumno, int *flag){
    char nombre[50], apellido[50];

    p("Ingrese el CODIGO o presione 0 para salir\n");
    sc("%d", &alumno[*flag].cod);

    fflush(stdin);

    if(alumno[*flag].cod != 0){

        
        p("Ingrese Nombre:\n");
        gets(nombre);     
        
        p("Ingrese Apellido:\n");
        gets(apellido); 
        

        concatenar(alumno, nombre, apellido, &flag);

        *alumno[*flag].promedio = rand () % 10 + 1; 

        p("%d", *flag);
        
        return *flag;
    }else{
        return *flag;
    }
}

void mostrarAlumnos(registro alumno[], int *flag){
    int aux;
    char aux1[50];

    if(*flag >= 2){
        for (int i = 0; i < *flag-1; i++){//Orden de los alumnos segun promedio

            for(int j = 1; j < *flag; j++){
                if(alumno[j].promedio > alumno[i].promedio){

                    aux = alumno[j].promedio;
                    *alumno[j].promedio = alumno[i].promedio;
                    *alumno[i].promedio = aux;

                    strcpy(alumno[j].apyno,aux1);
                    strcpy(alumno[i].apyno,alumno[j].apyno);
                    strcpy(aux1, alumno[i].apyno);

                    aux = alumno[j].cod;
                    *alumno[j].cod = alumno[i].cod;
                    *alumno[i].cod = aux;
                }
            }
        }
    }
    
    p("\nCODIGO   NOMBRE Y APELLIDO   PROM:\n");
    
    for(int j = 0; j < *flag; j++){
        p("\n%3d      %3s      %3d\n", alumno[j].cod, alumno[j].apyno, alumno[j].promedio);
    }
}   

void concatenar(registro *alumno, char nom[50], char ape[50], int *flag){
    int tamNom = strlen(nom);

    strcpy(alumno[*flag].apyno,nom);
    alumno[*flag].apyno[tamNom] = ' ';
    strcpy(alumno[*flag].apyno + tamNom + 1, ape);
}

    