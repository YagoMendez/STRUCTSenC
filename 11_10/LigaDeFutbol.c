#include <string.h>
#include <ctype.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<unistd.h>
#define p printf
#define sc scanf
#define Num_Equipos 28

/*El objetivo de este ejercicio es crear un programa que simule una temporada de la Liga Argentina de Fútbol con 28 equipos. 
Los equipos jugarán todos contra todos y se calcularán los puntos en función de los resultados de los partidos. 
Al final de la temporada, se mostrará una tabla de posiciones ordenada por puntos. 

Descripción del Programa: 

El programa simula una temporada de la Liga Argentina de Fútbol con 28 equipos. Las características del programa son las siguientes: 

Se definen 28 equipos con un código único y un nombre. 

Se simulan partidos entre los equipos, donde el resultado de cada partido es aleatorio, y se otorgan puntos de acuerdo con 
los resultados (3 puntos por victoria, 1 punto por empate, 0 puntos por derrota). 

Al final de la temporada, se calcula la tabla de posiciones, que muestra el código del equipo, 
el nombre del equipo y la cantidad de puntos acumulados. 

La tabla de posiciones se ordena en función de la cantidad de puntos, de mayor a menor, para determinar al campeón de la temporada. 

Tareas Para Realizar por los Alumnos: 

 

Comprender el código proporcionado, que incluye la estructura Equipo, las funciones inicializarEquipos,
jugarPartido, mostrarTablaPosiciones y ordenarCampeonatoPorPuntos, así como la simulación de los partidos. */

typedef struct{
    int codigo;
    char nombre[30];
    int pts;
    int jugados;
    int golesAF;
} equipo;

void inicializarEquipos(equipo*);
void partidos(equipo*);
void mostrarTabla(equipo*, int);
void ordenarTabla(equipo*);

int main(){
    int acum = 0;

    system("cls");
    srand(time(NULL));
    system("color 23");

    equipo teams [Num_Equipos];

    inicializarEquipos(teams);
    mostrarTabla(teams, acum);
    acum +=1;
    partidos(teams);
    mostrarTabla(teams, acum);


}

void inicializarEquipos(equipo teams[]){ // lo que mas hace es cargar los nombres e incializar todo en 0
    char nombres[28][30] = {"Argentinos Juniors","Arsenal","Atletico de Tucuman","Banfield","Barracas Central","Belgrano","Boca Juniors","Central Cordoba","Colon","Defensa y Justicia","Estudiantes","Gimnasia","Godoy Cruz","Huracan","Independiente", "Instituto","Lanus","Newell's","Platense","Racing Club","River Plate","Rosario Central","San Lorenzo","Sarmiento","Talleres","Tigre","Union","Velez"};

    for(int i = 0; i < Num_Equipos; i++){
        teams[i].codigo = i+1;
        strcpy(teams[i].nombre ,nombres[i]); // asignacion de nombres del equipo al struct
        teams[i].pts = 0;
        teams[i].jugados = 0;
        teams[i].golesAF = 0;
    }
}

void mostrarTabla(equipo teams[], int acum){
    int aux;
    char aux1[28];

    if(acum == 0){ // Para la primera muestra
        p("Bienvenido!\n");
        sleep(1);
    }

    for(int i = 0; i < Num_Equipos; i++){ //orden por pts
        for(int x = i+1; x < Num_Equipos; x++){
            if(teams[i].pts < teams[x].pts){

                aux = teams[i].codigo;
                teams[i].codigo = teams[x].codigo;
                teams[x].codigo = aux;

                strcpy(aux1, teams[i].nombre);
                strcpy(teams[i].nombre, teams[x].nombre);
                strcpy(teams[x].nombre, aux1);

                aux = teams[i].pts;
                teams[i].pts = teams[x].pts;
                teams[x].pts = aux;

                aux = teams[i].golesAF;
                teams[i].golesAF = teams[x].golesAF;
                teams[x].golesAF = aux;

            }
        }
    }

    for(int i = 0; i < Num_Equipos; i++){ //orden por goles AF si el puntaje es el mismo
        for(int x = i+1; x < Num_Equipos; x++){
            if(teams[i].pts == teams[x].pts && teams[i].golesAF < teams[x].golesAF){

                aux = teams[i].codigo;
                teams[i].codigo = teams[x].codigo;
                teams[x].codigo = aux;

                strcpy(aux1, teams[i].nombre);
                strcpy(teams[i].nombre, teams[x].nombre);
                strcpy(teams[x].nombre, aux1);

                aux = teams[i].pts;
                teams[i].pts = teams[x].pts;
                teams[x].pts = aux;

                aux = teams[i].golesAF;
                teams[i].golesAF = teams[x].golesAF;
                teams[x].golesAF = aux;

            }
        }
    }
    
    
    p("TABLA DE CLASIFICACION LIGA ARGENTINA 2023:\n\n");
    p("%-10s   %-30s   %-10s   %-10s\n\n", "CODIGO", "EQUIPO", "PUNTOS", "GOLESAF");
    for(int i = 0; i < Num_Equipos; i++){
        p("%-10d   %-30s   %-10d   %-10d\n", teams[i].codigo, teams[i].nombre, teams[i].pts, teams[i].golesAF);
    }
      
    if(acum == 0){// Para la primera pasada por la funcion
        p("\nLuego de una dura campania, estos son los puntajes de cada equipo:\n");
        p("Cuando este listo, presione ENTER\n");
        system("PAUSE");
    }  
}

void partidos(equipo teams[]){
    int resultado, goles1 = 0, goles = 0;

    for(int i = 0; i < 28; i++){
        for(int j = i+1; j < 28; j++){  
                goles = rand() % 13; // goles de 0  a 12 
                goles1 = rand() % 13;
                teams[i].golesAF += goles;
                teams[j].golesAF += goles1;

                if(goles > goles1){
                    resultado = 1;// 1 es que gano el equipo "i"
                }else if(goles1 > goles){
                    resultado = 2; // 2 al reves
                }else if(goles1 == goles){
                    resultado = 0;
                }

                switch(resultado){ // asignacion de pts
                    case 0:
                        teams[i].pts += 1;
                        teams[j].pts += 1;
                        break; 

                    case 1:
                        teams[i].pts += 3;
                        break;

                    case 2:
                        teams[j].pts += 3;
                        break;
                    default:
                        p("mamala\n");
                        break;
                }

                teams[i].jugados+=1;
                teams[j].jugados+=1; 
        
            /*for(int x = i+1; x < Num_Equipos; x++){ // orden por partidos jugados, intento de que sea un todos contra todos real
                if(teams[i].jugados < teams[x].jugados){

                    aux = teams[i].codigo;
                    teams[i].codigo = teams[x].codigo;
                    teams[x].codigo = aux;

                    strcpy(aux1, teams[i].nombre);
                    strcpy(teams[i].nombre, teams[x].nombre);
                    strcpy(teams[x].nombre, aux1);

                    aux = teams[i].pts;
                    teams[i].pts = teams[x].pts;
                    teams[x].pts = aux;
                }
            }*/
        }
    }
}    