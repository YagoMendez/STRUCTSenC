#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define p printf
#define sc scanf

/**/
typedef struct{
    int id;
    float precio;
    char nombre[30];
}producto;

float descuento(producto*, int);
void mostrar(producto*);

int main(){
    int op, count = 0;
    float original;

    producto producto[2];

    p("Bienvenido:\n");

    do{
        do{
            if(count > 0){
                p("Segundo Producto:\n\n");
            }

            p("Ingrese el ID o presione  0 para salir:\n");
            sc("%d", &producto[count].id);
        
            if(producto[count].id < 0){
                p("El id ingresado es incorrecto, reintentelo...\n");
            }else if(producto[count].id == 0){
                p("Adios!\n");
                break;
            }
        }while(producto[count].id == 0);

        if(producto[count].id == 0){
            break;
        }

        do{
            fflush(stdin);
            p("Ingrese el nombre del producto:\n");
            gets(producto[count].nombre);
            

            p("Ingrese el precio:\n");
            sc("%f", &producto[count].precio);

            if(producto[count].precio <= 0){
                p("El precio ingresado es incorrecto, reintentelo...\n");
            }
        }while(producto[count].precio == 0);

        descuento(producto, count);

        if(count == 1){
            mostrar(producto);
        }

        count ++;
        
    }while(count < 2);

    return 0;
}

float descuento(producto *producto, int count){

    producto[count].precio =  producto[count].precio - producto[count].precio*0.2; 

    return producto->precio;
}

void mostrar(producto *producto){

    if(producto[0].precio > producto[1].precio){
        p("El producto mas caro con el descuento aplicado es: %3d, %.2f, %s",producto[0].id,producto[0].precio, producto[0].nombre);
    }else{
        p("El producto mas caro con el descuento aplicado es: %3d, %.2f, %s",producto[1].id,producto[1].precio, producto[1].nombre);   
    }
}