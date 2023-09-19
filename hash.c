//
// Created by Usuario on 16/9/2023.
//

#include "hash.h"
#include "stdio.h"
#include "malloc.h"
#include "string.h"

Nodo * newNodo (char * nombre) {

    Nodo * aux = malloc(sizeof(Nodo));

    if (aux == NULL){
        printf("No hay espacio de memoria suficiente");
        exit(-1);
    }

    else{
        strcpy(aux->nombre,nombre);
        aux->sig = NULL;
    }
    return aux;
}
int hash (const char * nombre) {
    int hash = 0;
    for(int i = 0 ; nombre[i] != '\0' ; i++){
        hash += nombre[i];//segmentation fault aca
    }
    return hash % SIZE;
}

void insertar (Nodo * tablaDeHash[], char * nombre) {

    int posicion = hash(nombre);
    Nodo *nodoAInsertar = newNodo(nombre);

    if (tablaDeHash[posicion] == NULL) {
        tablaDeHash[posicion] = nodoAInsertar;
    } else {
        Nodo *actual = tablaDeHash[posicion];
        Nodo *anterior = NULL;

        while (actual != NULL) {
            if (strcmp(actual->nombre, nombre) == 0) {
                // El nombre ya existe, no lo insertamos nuevamente
                free(nodoAInsertar); // Liberamos el nodo que no se usará
                return;
            }
            anterior = actual;
            actual = actual->sig;
        }

        nodoAInsertar->sig = tablaDeHash[posicion]; // Enlazamos el nuevo nodo al principio
        tablaDeHash[posicion] = nodoAInsertar;
    }
}

void imprimir (Nodo * tablaDeHash[]) {

    printf("Tabla de Hash:\n");

    for(int i = 0 ; i < SIZE ; i++){
        if (tablaDeHash[i] != NULL){
            Nodo *aux = tablaDeHash[i];
            while (aux != NULL) {
                printf("En la posicion %d se encuentra en el nombre %s\n", i, aux->nombre);
                aux = aux->sig;
            }
        }

    }
}