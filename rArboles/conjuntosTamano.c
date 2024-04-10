#include "conjuntos.h"
#include <stdio.h>

/// Incluir aqui las funciones que implementan las tres operaciones básicas
/// en la representación de CONJUNTOS DISJUNTOS mediante ÁRBOLES para la unión por TAMAÑO
/// ......................................................................
///
/// Función que crea la partición
///
void crea(particion P)
{
    int i;
    for (i = 0; i < MAXIMO; i++)
        P[i] = -1; // Inicialmente todos los elementos son representantes de su clase de equivalencia, árboles de tamaño 1
}
///
/// Función que busca el representante de la clase de equivalencia de x
///
tipoConjunto buscar(tipoElemento x, particion P)
{
    int i;
    while (x > -1)  // Mientras no sea representante de una clase de equivalencia
    {
        i = x;      // Guardo el contenido del nodo hijo, es decir, la posición del nodo padre en la matriz
        x = P[x];   // Comprobar su nodo padre
    }         
    return i; // Devuelve el representante
}
///
/// Función que une las clases de equivalencia de x e y
///
int unir(tipoConjunto x, tipoConjunto y, particion P)
{
    if (P[x] >= 0 || P[y] >= 0) // Si x o y no son representantes
    {
        return 0; // Devuelve FALSO
    }
    else // Si x e y son representantes
    {
        if (P[x] <= P[y]) // Si el árbol de x es más grande que el de y, o sus tamaños son iguales
        {
            P[x] += P[y]; // Sumo el tamaño de y al de x
            P[y] = x;     // Hago a x el padre de y
        }
        else
        {
            P[y] += P[x]; // Sumo el tamaño de x al de y
            P[x] = y;     // Hago a y el padre de x
        }
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