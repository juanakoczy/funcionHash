//
// Created by Usuario on 16/9/2023.
//

#include "hash.h"
#include "stdio.h"
#include "malloc.h"
#include "string.h"

Nodo * newNodo (char * nombre) {

    Nodo * aux = NULL;
    aux = malloc(sizeof(Nodo));

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
    Nodo * nodoAInsertar = newNodo(nombre);//creo el nodo a insertar

    if(tablaDeHash[posicion] == NULL){//el nodo no esta en la tabla
        tablaDeHash[posicion] = nodoAInsertar;
    }
    else{
        nodoAInsertar->sig = tablaDeHash[posicion];//persisto la tabla detras del nodo anterior
        tablaDeHash[posicion] = nodoAInsertar;
   }
}

void imprimir (Nodo * tablaDeHash[]) {

    printf("Tabla de Hash:\n");

    for(int i = 0 ; i < SIZE ; i++){

        if(tablaDeHash[i]!=NULL)
        printf("En la posicion %d se encuentra en el nombre %s",tablaDeHash[i],tablaDeHash[i]->nombre);
    }
}