#include "conjuntos.h"
#include <stdio.h>
/// Incluir aqui las funciones que implementan las tres operaciones básicas
/// en la representación de CONJUNTOS DISJUNTOS mediante MATRICES
/// ......................................................................
///
/// Funcion que crea la partición inicial
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
    while (P[x] != x)
    { // Comprueba si es el representante de la clase de equivalencia
        x = P[x];
    }
    return x; // Devuelve el representante
}
///
/// Función que une las clases de equivalencia de x e y
///
int unir(tipoConjunto x, tipoConjunto y, particion P)
{
    if (P[x] == x && P[y] == y) // Si x e y son representantes
    {
        for (int i = 0; i < MAXIMO; i++) // Buscar por toda la partición y cambiar todo "y" por "x"
        {
            if (P[i] == y)
                P[i] = x;
        }
        return 1; // Unión satisfactoria
    }
    return 0; // No se ha podido unir
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
    printf("  índices vector\n");
}
