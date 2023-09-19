//
// Created by Usuario on 16/9/2023.
//

#ifndef FUNCIONHASH_HASH_H
#define FUNCIONHASH_HASH_H
#define SIZE 127 //definido en el enunciado

typedef struct nodo{

    char nombre[50];
    struct nodo * sig;

}Nodo;

Nodo * newNodo (char * nombre);//funcion para crear nodos
int hash ( const char * nombre);//funcion de hash

void insertar (Nodo * tablaDeHash[], char * nombre);//inserta los nombres en la tabla
void imprimir (Nodo * tablaDeHash[]);//imprime la tabla


#endif //FUNCIONHASH_HASH_H
