#include "conjuntos.h"
#include <stdio.h>

/// Incluir aqui las funciones que implementan las tres operaciones básicas
/// en la representación de CONJUNTOS DISJUNTOS mediante ÁRBOLES
/// ......................................................................
///
/// Función que crea la partición
///
void crea(particion P)
{
    int i;
    for (i = 0; i < MAXIMO; i++)
        P[i] = i;
}
///
/// Función que busca el representante de la clase de equivalencia de x
///
tipoConjunto buscar(tipoElemento x, particion P)
{
    while (x != P[x]) // Mientras no sea representante de una clase de equivalencia
        x = P[x];     // Comprobar su nodo padre
    return x;         // Devuelve el representante
}
///
/// Función que une las clases de equivalencia de x e y
///
int unir(tipoConjunto x, tipoConjunto y, particion P)
{
    if (P[x] != x || P[y] != y) // Si x o y no son representantes
    {             
        return 0; // Devuelve FALSO
    }
    else //Si x e y son representantes
    {
        P[y] = x; // Unión arbitraria
        return 1; // Devuelve VERDADERO
    }
}
//
// Función auxiliar para ver contenido de Partición
//
void verParticion(particion P)
{
    int i;
    printf("\n");
    for (i = 0; i < MAXIMO; i++)
        printf("|%2d", P[i]);
    printf("| contenido  vector\n");
    for (i = 0; i < MAXIMO; i++)
        printf("---");
    printf("\n");
    for (i = 0; i < MAXIMO; i++)
        printf(" %2d", i);
    printf("  índices vector\n\n");
}
