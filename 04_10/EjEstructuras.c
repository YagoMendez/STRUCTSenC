#include <string.h>
#include <ctype.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<time.h>
#define p printf
#define sc scanf
/*Estructuras

Encapsulador de datos:

Struct identificador_tipo_estructura{
    Tipo miembro_1; Declaracion miembros
    Tipo miembro_2;
};

typedef struct{     ej Struct "anonima o sin nombre"
    int codigo;
    char producto[30];
    float precio;
} registro;

struct Persona{  Al momento de la declaracion de struct, no se guarda memoria; eso sucede recien al momento de llamar al struct
    char nombre[50];
    int edad;
};*/

struct Persona{ // Al momento de la declaracion de struct, no se guarda memoria; eso sucede recien al momento de llamar al struct
    char nombre[50];
    int edad;
};

int main(){

    struct Persona person1; //declaracion de una variable tipo struct persona

    //Inicializacion de la variable person1
    strcpy(person1.nombre, "Juan");
    person1.edad = 30;

    //Mostrar la info de la persona
    p("Nombre: %s\n", person1.nombre);
    p("Edad: %d\n", person1.edad);


    return 0;
}
/*Distintas maneras de inicializar structs:
1)
struct Persona{
    int cod;
    char apellido
};Typedef struct persona Cliente
El "cliente al dinal redefine como llamar al struct" algo asi como el define
2)
Typedef struct cliente{
    int cod;
    char apellido
}cliente;
Al poner el "cliente" al final del struct, me ahorro llamarlo utilizando la palabra "struct"*/