#include "pila.h"
#include "lista.h"

#include <stdio.h>
struct _pila_t{
    lista_t* lista;
};

pila_t* pila_crear(){
    lista_t* lista = lista_crear();
    pila_t* pila = malloc(sizeof(pila_t));
    if(!pila)
        return NULL;

    pila->lista = lista;
    return pila;
}

pila_t* pila_apilar(pila_t* pila, void* elemento){
    if(!pila)
        return NULL;
    pila->lista = lista_insertar(pila->lista, elemento);
    return pila;
}

void* pila_desapilar(pila_t* pila){
    if(!pila)
        return NULL;

    return lista_quitar(pila->lista);
}

void* pila_tope(pila_t* pila){
    if(!pila || pila->lista->cantidad == 0)
        return NULL;
    return pila->lista->nodo_fin->elemento;
}

size_t pila_tamanio(pila_t* pila){
    if(!pila || pila->lista->cantidad == 0)
        return 0;
    return pila->lista->cantidad;
}

bool pila_vacia(pila_t* pila){
    return (pila_tamanio(pila) == 0);
}

void pila_destruir(pila_t* pila){
    if(pila){
        lista_destruir(pila->lista);
        free(pila);
    }
}