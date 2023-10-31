#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define p printf
#define sc scanf
#define maxSlaves 6

/*1) Una pyme necesita informatizar los datos de sus 6 empleados. Para ello te encomienda realizar
un programa que permita ingresar, por cada uno de ellos:
Nombre
Apellido
Categoría ("A", "B' o "C") (validar)
Luego, que muestre la siguiente información respecto a ellos:
Listar los datos ordenados alfabéticamente por apellido.
Informar la cantidad de empleados por cada categoría*/

typedef struct 
{
    char ape[50];
    char nom[50];
    char cat;
}registro; 

int menu(registro[], int *); //recibe también un PUNTERO de entero
void ingreso(registro[], int); //recibe un entero
void ordenarYmostrar(registro[], int); //recibe un entero

int main(){
    int killswitch, count = 0; //variable count inicializada

    registro slaves[maxSlaves];

    //system("cls");

    p("Bienvenido!\n");

    do{
        killswitch = menu(slaves, &count); //le paso la dirección de la variable count
    }while(killswitch != 0);
    p("ADIOS!\n");
}

int menu(registro slaves[], int *pCount){ //recibe un PUNTERO pCount que apunta a la dirección de count del main
    int op;

    p(" __________________________\n");
    p("| 1)  INGRESAR EMPLEADOS   |\n");
    p("|__________________________|\n");
    p("| 2)  MOSTRAR LISTADO      |\n");
    p("|__________________________|\n");
    p("| 0)  SALIR                |\n");
    p("|__________________________|\n");
    p("\nIngrese que opcion desea: ");

    do{
        sc("%d", &op);

        if(op != 1 && op != 2 && op != 0){
            p("Entrada invalida, reintentelo:\n");
        }

    }while(op != 1 && op != 2 && op != 0);
    
    system("cls");

    switch(op){
        case 1:
            ingreso(slaves, *pCount); //le paso el CONTENIDO del puntero de count
            (*pCount)++; //incremento el CONTENIDO del puntero (si, se declara así de falopa)
            break;
        case 2:
            ordenarYmostrar(slaves, *pCount); //le paso el CONTENIDO del puntero de count
            system("pause");
            system("cls");
            break;
    }
    return op;
}

void ingreso(registro slaves[], int count){ //recibe el CONTENIDO como un entero cualquiera
    char temp;

    if(count == maxSlaves){
        p("Todos los empleados han sido ingresados, regresando al menu...\n");
        sleep(2);
    }else{
        p("Ingrese el apellido:\n");
        sc(" %s", slaves[count].ape);
        p("Ingrese el nombre:\n");
        sc(" %s", slaves[count].nom);

        p("Ingrese la categoria (A, B, C):\n");

        do{
            fflush(stdin);
            sc(" %c", &temp);

            //Ya lo asigno en mayuscula
            slaves[count].cat = toupper(temp);

            if(slaves[count].cat != 'A' &&  slaves[count].cat != 'B' && slaves[count].cat != 'C'){
                p("Categoria incorrecta, ingrese A, B o C:\n");
            }
        }while(slaves[count].cat != 'A' && slaves[count].cat != 'B' && slaves[count].cat != 'C');
    } 
}

void ordenarYmostrar(registro slaves[], int slavesRegistrados){ //recibe el CONTENIDO como un entero cualquiera
    char auxStr[50], apemin[slavesRegistrados];
    char auxChar;
    int cantidadCat[3] = {0}; //Inicializo como 0 el vector

    for(int i = 0; i < slavesRegistrados; i++){
        apemin[i]= tolower(slaves[i].ape[0]);
    }

    for(int i = 0; i < slavesRegistrados; i++){
        for(int j = i + 1; j < slavesRegistrados; j++){ //j = i + 1
            if(apemin[i] > apemin[j]){ //Mayor qué en vez de menor qué

                strcpy(auxStr, slaves[j].ape);
                strcpy(slaves[j].ape,slaves[i].ape);
                strcpy(slaves[i].ape, auxStr);

                strcpy(auxStr, slaves[j].nom);
                strcpy(slaves[j].nom,slaves[i].nom);
                strcpy(slaves[i].nom, auxStr);

                auxChar = slaves[j].cat;
                slaves[j].cat = slaves[i].cat;
                slaves[i].cat = auxChar;
            }
        }
    }
    
    if(slavesRegistrados != 0) {
        p("____________________________________________\n");
        p("|   APELLIDO      NOMBRE      CATEGORIA     |\n");
        p("____________________________________________\n");

        for(int i = 0; i < slavesRegistrados; i++){
            p("|   %3s   %3s   %3c   |\n", slaves[i].ape, slaves[i].nom, slaves[i].cat);
            p("____________________________________________\n");
        }
        

        for(int i = 0; i < slavesRegistrados; i++){
            if(slaves[i].cat == 'A'){
                cantidadCat[0]++;
            }else if(slaves[i].cat == 'B'){
                cantidadCat[1]++;
            }else{
                cantidadCat[2]++;
            }
        }

        p("Cantidad de Categorias 'A': %d\n", cantidadCat[0]);
        p("Cantidad de Categorias 'B': %d\n", cantidadCat[1]);
        p("Cantidad de Categorias 'C': %d\n", cantidadCat[2]);
    } else {
        p("Todavia no se ingresaron esclavos...\n");
    }
        
}