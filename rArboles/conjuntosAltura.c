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
        P[i] = -1; // Inicialmente todos los elementos son representantes de su clase de equivalencia, árboles de altura 0 + 1
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
        if (P[x] == P[y]) // Si sus alturas son iguales
        {
            P[x] -= 1;      // La altura de x aumenta en 1
            P[y] = x;       // Hago a x el padre de y
        }
        else if (P[x] < P[y]) // Si la altura de x es mayor que la de y
        {
            //La altura de x sigue siendo la misma
            P[y] = x;     // Hago a x el padre de y
        } else { // Si la altura de y es mayor que la de x
            //La altura de y sigue siendo la misma
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