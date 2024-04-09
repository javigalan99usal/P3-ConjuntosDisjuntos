#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conjuntos.h"

/// Incluir aqui las funciones que implementan las tres operaciones básicas
/// en la representación de CONJUNTOS DISJUNTOS mediante LISTAS
/// ......................................................................
///
/// Crear una partición inicial con n conjuntos unitarios
///
void crea(particion P)
{
  int i;
  for (i = 0; i < MAXIMO; i++)
  {
    P[i].primero = (tipoCelda *)malloc(sizeof(tipoCelda));
    P[i].primero->elemento = i;
    P[i].primero->sig = NULL;
    P[i].ultimo = P[i].primero;
  }
}
///
/// Buscar el representante de la clase de equivalencia de x
///
tipoConjunto buscar(tipoElemento x, particion P)
{
  int i;
  tipoCelda *aux;
  for (i = 0; i < MAXIMO; i++) // Buscar en todas las listas de la particion
  {
    aux = P[i].primero;
    while (aux != NULL) // Si la lista no está vacía
    {
      if (aux->elemento == x) // Comprombar si el elemento está en la lista
        return i; // Si está, devolver el representante
      aux = aux->sig; // Si no, sigue buscando en la lista
    }
  }
  return -1; // Si no puede encontrar el elemento, devolver -1
}
///
/// Unir las clases de equivalencia de x e y
///
int unir(tipoConjunto x, tipoConjunto y, particion P)
{
  if (P[x].primero != NULL && P[y].primero!= NULL) // Comprobar si x e y son representantes
  {
    P[x].ultimo->sig = P[y].primero; // Unir las listas
    P[x].ultimo = P[y].ultimo; // Actualizar el último de la lista
    P[y].primero = NULL; // Vaciar la lista de y
    return 1;
  } else {
    return 0;
  }
}
/// ......................................................................
void verParticion(particion P)
{
  int i;
  tipoCelda *aux;
  for (i = 0; i < MAXIMO; i++)
  {
    aux = P[i].primero;
    if (aux != NULL)
      printf("\n\nClase equivalencia representante %d: ", i);
    while (aux != NULL)
    {
      printf("%d ", aux->elemento);
      aux = aux->sig;
    }
  }
}

void verClaseEquivalencia(tipoElemento x, particion P)
{
  int representante;
  tipoCelda *aux;

  representante = buscar(x, P);
  printf("\n\nClase de Equivalencia de %d cuyo representante es %d: ", x, representante);
  aux = P[representante].primero;
  while (aux)
  {
    printf(" %d ", aux->elemento);
    aux = aux->sig;
  }
  printf("\n\n");
}
