//Funcion hashing que recibe una cadena de caracteres.Los suma y devuelve un nro entre 0 y 127

#include <stdio.h>
#include "hash.h"

int main() {
    Nodo * nuevatabla[SIZE];

    insertar(nuevatabla,"juan");
    insertar(nuevatabla,"maria");
    insertar(nuevatabla,"carlos");
    insertar(nuevatabla,"raul");
    insertar(nuevatabla,"franco");

    imprimir(nuevatabla);

    return 0;
}
