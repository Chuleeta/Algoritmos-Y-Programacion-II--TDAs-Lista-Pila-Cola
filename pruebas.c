#include "src/lista.h"
#include "src/pila.h"
#include "src/cola.h"
#include <stdio.h>
#include <stdlib.h>
#include "pa2mm.h"


void prueboCrear_y_DestruirUnaLista(){
  lista_t* lista;
  
  pa2m_afirmar((lista = lista_crear()),"Crear una lista devuelve una lista");
  pa2m_afirmar(lista->cantidad == 0, "Al crear una lista tiene 0 cantidad de elementos");
  pa2m_afirmar((lista->nodo_inicio == NULL && lista->nodo_fin == NULL),"Al crear una lista el nodo inicial y final apuntan a nada (la lista esta vacia)");
  
  lista_destruir(lista);
}


void prueboInsertarUnElementoAlFinalDeLaLista_DevuelveUnaLista(){
  lista_t* lista = lista_crear();
  
  int numero = 8;
  
  pa2m_afirmar(lista_insertar(NULL, &numero) == NULL, "Al insertar un elemento a una lista NULL devuelve NULL");
  pa2m_afirmar(lista_insertar(lista, &numero) != NULL, "Agregar un elemento cualquiera al final de la lista");
  pa2m_afirmar(lista->nodo_fin->elemento == &numero,"El elemento insertado es correcto");
  pa2m_afirmar(lista->cantidad == 1,"El tamaño de la lista es uno despues de agregar un elemento");
  pa2m_afirmar((lista->nodo_inicio == lista->nodo_fin),"Al insertar un elemento a una lista vacia el inicio y el fin son iguales");
  
  lista_destruir(lista);
}


void prueboInsertarUnElementoEnUnaPosicionDada_DevuelveUnaLista(){
  lista_t* lista = lista_crear();
  lista_t* vacia_lista_1 = lista_crear();
  lista_t* vacia_lista_2 = lista_crear();

  size_t posicion1 = 2;
  size_t posicion2 = 10;
  size_t posicion3 = 0;


  int numero_random_1 = 54;
  int numero_random_2 = 93;
  int numero_random_3 = 90;

  lista_insertar(lista, &numero_random_1);
  lista_insertar(lista, &numero_random_2);
  lista_insertar(lista, &numero_random_3);

  pa2m_afirmar(lista_insertar_en_posicion(NULL, &numero_random_1, posicion1) == NULL, "Al insertar una lista NULL devuelve NULL");
  pa2m_afirmar((vacia_lista_1 = lista_insertar_en_posicion(vacia_lista_1, &numero_random_1, 0)), "Al insertar un elemento al principio en una lista vacia devuelve la lista con un elemento");
  pa2m_afirmar(vacia_lista_1->cantidad == 1, "Al insertar un elemento al principio en una lista vacia el tamanio es 1");
  pa2m_afirmar(vacia_lista_1->nodo_fin != NULL, "Al insertar un elemento al principio en una lista vacia el nodo fin  apunta al unico elemento");
  
  pa2m_afirmar((vacia_lista_2 = lista_insertar_en_posicion(vacia_lista_2, &numero_random_1, 52)), "Al insertar un elemento al final en una lista vacia devuelve la lista con un elemento");
  pa2m_afirmar(vacia_lista_2->cantidad == 1, "Al insertar un elemento al final en una lista vacia el tamanio es 1");
  pa2m_afirmar(vacia_lista_2->nodo_inicio != NULL, "Al insertar un elemento al final en una lista vacia el nodo inicio  apunta al unico elemento");

  pa2m_afirmar((lista = lista_insertar_en_posicion(lista, &numero_random_1, posicion1)), "Al insertar un elemento en una posicion existente devuelve una lista");
  pa2m_afirmar(lista->cantidad == 4, "Al insertar un elemento en una posicion existente aumenta la cantidad de elementos de la lista");
  
  pa2m_afirmar((lista = lista_insertar_en_posicion(lista, &numero_random_2, posicion2)), "Al insertar un elemento en una posicion NO existente devuelve una lista");
  pa2m_afirmar(lista->cantidad == 5, "Al insertar un elemento en una posicion NO existente aumenta la cantidad de elementos de la lista");
  pa2m_afirmar(lista->nodo_fin->elemento == &numero_random_2, "Al insertar un elemento en una posicion NO existente lo inserta al final de la lista");
  
  pa2m_afirmar((lista = lista_insertar_en_posicion(lista, &numero_random_3, posicion3)), "Al insertar un elemento al principio devuelve una lista");
  pa2m_afirmar(lista->cantidad == 6, "Al insertar un elemento al principio aumenta la cantidad de elementos de la lista");
  pa2m_afirmar(lista->nodo_inicio->elemento == &numero_random_3, "Al insertar un elemento al principio lo inserta al principio de la lista");
  
  lista_destruir(lista);
  lista_destruir(vacia_lista_1);
  lista_destruir(vacia_lista_2);
}


void prueboQuitarUnElementoDelFinalDeUnaLista_DevuelveElElemento_DeNoSerAsiDevuelveNULL(){
  lista_t* lista = lista_crear();
  lista_t* lista_vacia = lista_crear();
  lista_t* lista_con_un_elemento = lista_crear();
  int numero_random_1 = 5222;
  int numero_random_2 = 0;
  int numero_random_3 = 8481;

  lista_insertar(lista, &numero_random_1);
  lista_insertar(lista, &numero_random_2);
  lista_insertar(lista, &numero_random_3);
  lista_insertar(lista_con_un_elemento, &numero_random_1);

  pa2m_afirmar(lista_quitar(NULL) == NULL,"Al quitar el ultimo elemento de una lista NULL devuelve NULL");
  pa2m_afirmar(lista_quitar(lista_vacia) == NULL,"Al quitar el ultimo elemento de una lista vacia devuelve NULL");
  pa2m_afirmar(lista_quitar(lista) == &numero_random_3,"Al quitar el ultimo elemento de una lista devuelve el ultimo elemento");
  pa2m_afirmar(lista_ultimo(lista) == &numero_random_2,"El ultimo elemento es el que antes era el anteultimo");
  pa2m_afirmar(lista->cantidad == 2,"Despues de quitar el ultimo elemento la cantidad disminuye");
  pa2m_afirmar(lista_quitar(lista_con_un_elemento) == &numero_random_1,"Al quitar el ultimo elemento de una lista con un elemento devuelve este");
  pa2m_afirmar(lista_con_un_elemento->cantidad == 0,"Despues de quitar el ultimo elemento de una lista con un elemento la cantidad es cero");

  lista_destruir(lista_con_un_elemento);
  lista_destruir(lista_vacia);
  lista_destruir(lista);
}


void prueboQuitarUnElementoDeUnaPosicionDada_DevuelveElElemento_DeNoSerAsiDevuelveNULL(){
  lista_t* lista = lista_crear();
  lista_t* lista_vacia = lista_crear();

  size_t posicion1 = 0;
  size_t posicion2 = 1212;
  size_t posicion3 = 3;

  int numero_random_1 = 82511;
  int numero_random_2 = 215;
  int numero_random_3 = 2222;
  int numero_random_4 = 744;
  int numero_random_5 = 8;
  int numero_random_6 = 241;
  int numero_random_7 = 26891;
  int numero_random_8 = 69;

  lista_insertar(lista, &numero_random_1);
  lista_insertar(lista, &numero_random_2);
  lista_insertar(lista, &numero_random_3);
  lista_insertar(lista, &numero_random_4);
  lista_insertar(lista, &numero_random_5);
  lista_insertar(lista, &numero_random_6);
  lista_insertar(lista, &numero_random_7);
  lista_insertar(lista, &numero_random_8);

  pa2m_afirmar(lista_quitar_de_posicion(NULL,posicion1) == NULL,"Al pasar una lista NULL devuelve NULL");
  pa2m_afirmar(lista_quitar_de_posicion(lista_vacia,posicion1) == NULL,"Al pasar una lista vacia devuelve NULL");

  pa2m_afirmar(lista_quitar_de_posicion(lista, posicion1) == &numero_random_1,"Elimina el primer elemento");
  pa2m_afirmar(lista->cantidad == 7,"Disminuye la cantidad de elementos al eliminar el primer elemento");

  pa2m_afirmar(lista_quitar_de_posicion(lista, posicion2) == &numero_random_8,"Al pasar una posicion NO existente elimina el ultimo elemento");
  pa2m_afirmar(lista->cantidad == 6,"Disminuye la cantidad de elementos al eliminar el ultimo elemento por pasar una poscion invalida");

  pa2m_afirmar(lista_quitar_de_posicion(lista, posicion3) == &numero_random_5,"Elimina un elemento en una posicion dada");
  pa2m_afirmar(lista->cantidad == 5,"Disminuye la cantidad de elementos al eliminar un elemento con una posicion dada");

  lista_destruir(lista_vacia);
  lista_destruir(lista);
}


void prueboDevolverElElementoDeUnaPosicionDada_DevuelveElElemento_DeNoSerAsiDevuelve_NULL(){
  lista_t* lista = lista_crear();
  lista_t* lista_vacia = lista_crear();

  size_t posicion1 = 0;
  size_t posicion2 = 1212;
  size_t posicion3 = 3;
  size_t posicion4 = 1;

  int numero_random_1 = 82511;
  int numero_random_2 = 215;
  int numero_random_3 = 2222;
  int numero_random_4 = 744;
  int numero_random_5 = 8;
  int numero_random_6 = 241;
  int numero_random_7 = 26891;
  int numero_random_8 = 69;

  lista_insertar(lista, &numero_random_1);
  lista_insertar(lista, &numero_random_2);
  lista_insertar(lista, &numero_random_3);
  lista_insertar(lista, &numero_random_4);
  lista_insertar(lista, &numero_random_5);
  lista_insertar(lista, &numero_random_6);
  lista_insertar(lista, &numero_random_7);
  lista_insertar(lista, &numero_random_8);

  pa2m_afirmar(lista_elemento_en_posicion(NULL, posicion1) == NULL,"Devuelve NULL si la lista es NULL");
  pa2m_afirmar(lista_elemento_en_posicion(lista_vacia, posicion1) == NULL,"Devuelve NULL si la lista esta vacia");
  pa2m_afirmar(lista_elemento_en_posicion(lista, posicion2) == NULL,"Devuelve NULL si la posicion NO existe");
  pa2m_afirmar(lista_elemento_en_posicion(lista, posicion3) == &numero_random_4,"Devuelve el elemento de la posicion 3");
  pa2m_afirmar(lista_elemento_en_posicion(lista, posicion4) == &numero_random_2,"Devuelve el elemento de la posicion 1");

  lista_destruir(lista_vacia);
  lista_destruir(lista);
}


void prueboPedirElPrimerElementoDeLaLista_DevuelveElElemento_DeNoSerAsiDevuelveNULL(){
  lista_t* lista = lista_crear();
  lista_t* lista_vacia = lista_crear();

  int numero_random_1 = 82511;
  int numero_random_2 = 215;
  int numero_random_3 = 2222;

  lista_insertar(lista, &numero_random_1);
  lista_insertar(lista, &numero_random_2);
  lista_insertar(lista, &numero_random_3);

  pa2m_afirmar(lista_primero(NULL) == NULL,"Devuelve NULL si la lista es NULL");
  pa2m_afirmar(lista_primero(lista_vacia) == NULL,"Devuelve NULL si la lista esta vacia");
  pa2m_afirmar(lista_primero(lista) == &numero_random_1,"Devuelve el primer elemento de la lista");


  lista_destruir(lista_vacia);
  lista_destruir(lista);
}


void prueboPedirElUltimoElementoDeLaLista_DevuelveElElemento_DeNoSerAsiDevuelveNULL(){
  lista_t* lista = lista_crear();
  lista_t* lista_vacia = lista_crear();

  int numero_random_1 = 82511;
  int numero_random_2 = 215;
  int numero_random_3 = 2222;

  lista_insertar(lista, &numero_random_1);
  lista_insertar(lista, &numero_random_2);
  lista_insertar(lista, &numero_random_3);

  pa2m_afirmar(lista_ultimo(NULL) == NULL,"Devuelve NULL si la lista es NULL");
  pa2m_afirmar(lista_ultimo(lista_vacia) == NULL,"Devuelve NULL si la lista esta vacia");
  pa2m_afirmar(lista_ultimo(lista) == &numero_random_3,"Devuelve el ultimo elemento de la lista");


  lista_destruir(lista_vacia);
  lista_destruir(lista);
}


void prueboVerSiLaListaEstaVacia_O_NoExiste_DevuelveTrueSiEstaVaciaONoExiste_AlRevezEnElCasoContrario(){
  lista_t* lista = lista_crear();
  lista_t* vacia_lista = lista_crear();

  int numero_random_1 = 82511;
  int numero_random_2 = 215;
  int numero_random_3 = 2222;

  lista_insertar(lista, &numero_random_1);
  lista_insertar(lista, &numero_random_2);
  lista_insertar(lista, &numero_random_3);

  pa2m_afirmar(!lista_vacia(lista),"Devuelve false si la lista no esta vacia");
  pa2m_afirmar(lista_vacia(vacia_lista),"Devuelve true si la lista esta vacia");
  pa2m_afirmar(lista_vacia(NULL),"Devuelve true si la lista es NULL");


  lista_destruir(vacia_lista);
  lista_destruir(lista);
}


void prueboDevolverElTamanioDeUnaLista(){
  lista_t* lista = lista_crear();
  lista_t* vacia_lista = lista_crear();

  int numero_random_1 = 82511;
  int numero_random_2 = 215;
  int numero_random_3 = 2222;

  lista_insertar(lista, &numero_random_1);
  lista_insertar(lista, &numero_random_2);
  lista_insertar(lista, &numero_random_3);

  pa2m_afirmar(lista_tamanio(NULL) == 0,"Lista NULL devuelve 0");
  pa2m_afirmar(lista_tamanio(vacia_lista) == 0,"Lista vacia devuelve 0");
  pa2m_afirmar(lista_tamanio(lista) == 3,"Lista tiene tamanio 3");


  lista_destruir(vacia_lista);
  lista_destruir(lista);
}


void prueboCrearUnaListaIterador_DevuelveUnPunteroAlIteradorCreado(){
  lista_t* lista = lista_crear();
  lista_t* vacia_lista = lista_crear();
  lista_iterador_t* lista_iterador;
  lista_iterador_t* lista_iterador_lista_vacia;

  int numero_random_1 = 82511;
  int numero_random_2 = 215;
  int numero_random_3 = 2222;

  lista_insertar(lista, &numero_random_1);
  lista_insertar(lista, &numero_random_2);
  lista_insertar(lista, &numero_random_3);

  pa2m_afirmar(lista_iterador_crear(NULL) == NULL, "Crear una lista iterador con una lista NULL devuelve NULL");
  pa2m_afirmar((lista_iterador_lista_vacia = lista_iterador_crear(vacia_lista)),"Crear una lista iterador con una lista vacia devuelve NULL");
  pa2m_afirmar((lista_iterador = lista_iterador_crear(lista)), "Crear una lista iterador devuelve un puntero a una lista iterador");
  pa2m_afirmar(lista_iterador->corriente == lista->nodo_inicio, "Al crear la lista iterador, el nodo corriente apunta al primer nodo de la lista dada");

  lista_iterador_destruir(lista_iterador_lista_vacia);
  lista_iterador_destruir(lista_iterador);
  lista_destruir(vacia_lista);
  lista_destruir(lista);
}


void prueboVerSiHayUnElementoOMasParaIterar_SiEsAsiDevuelveTrue(){
  lista_t* lista = lista_crear();
  lista_t* lista_con_un_elemento = lista_crear();
  int numero_random_1 = 82511;
  int numero_random_2 = 215;
  int numero_random_3 = 2222;

  lista_insertar(lista, &numero_random_1);
  lista_insertar(lista, &numero_random_2);
  lista_insertar(lista, &numero_random_3);
  lista_insertar(lista_con_un_elemento, &numero_random_3);
  
  lista_iterador_t* lista_iterador = lista_iterador_crear(lista);
  lista_iterador_t* lista_iterador_con_una_lista_de_un_elemento = lista_iterador_crear(lista_con_un_elemento);


  pa2m_afirmar(!lista_iterador_tiene_siguiente(lista_iterador_con_una_lista_de_un_elemento),"Lista no tiene mas elementos sobre los que deba iterar");
  pa2m_afirmar(!lista_iterador_tiene_siguiente(NULL),"Lista NULL no tiene elementos sobre los que deba iterar");
  pa2m_afirmar(lista_iterador_tiene_siguiente(lista_iterador),"Lista tiene mas elementos sobre los cuales deba iterar");

  lista_iterador_avanzar(lista_iterador);
  lista_iterador_avanzar(lista_iterador);
  lista_iterador_avanzar(lista_iterador);


  pa2m_afirmar(!lista_iterador_tiene_siguiente(lista_iterador),"Lista NO tiene mas elementos sobre los cuales deba iterar");
  lista_iterador_destruir(lista_iterador);
  lista_destruir(lista);
  lista_iterador_destruir(lista_iterador_con_una_lista_de_un_elemento);
  lista_destruir(lista_con_un_elemento);
}


void prueboAvanzarElIteradorUnElemento_DevuelveTrueSiPudoHacerlo(){
  lista_t* lista = lista_crear();

  int numero_random_1 = 82511;
  int numero_random_2 = 215;
  int numero_random_3 = 2222;

  lista_insertar(lista, &numero_random_1);
  lista_insertar(lista, &numero_random_2);
  lista_insertar(lista, &numero_random_3);
  
  lista_iterador_t* lista_iterador = lista_iterador_crear(lista);
  pa2m_afirmar(lista_iterador_elemento_actual(lista_iterador) == &numero_random_1,"El elemento corriente es correcto");
  pa2m_afirmar(lista_iterador_avanzar(lista_iterador),"Pudo avanzar un lugar en el iterador");
  pa2m_afirmar(lista_iterador_elemento_actual(lista_iterador) == &numero_random_2,"El elemento corriente es correcto");
  pa2m_afirmar(lista_iterador->corriente == lista->nodo_inicio->siguiente,"El elemento en el cual avanzo es el correcto");
  pa2m_afirmar(!lista_iterador_avanzar(NULL),"Avanzar en un iterador NULL devuelve NULL");

  lista_iterador_avanzar(lista_iterador);
  pa2m_afirmar(lista_iterador_elemento_actual(lista_iterador) == &numero_random_3,"El elemento corriente es correcto");
  lista_iterador_avanzar(lista_iterador);
  pa2m_afirmar(!lista_iterador_tiene_siguiente(lista_iterador), "No se puede avanzar mas");

  lista_iterador_destruir(lista_iterador);
  lista_destruir(lista);
}


void prueboPedirElElementoActualDelIterador(){
  lista_t* lista = lista_crear();

  int numero_random_1 = 82511;
  int numero_random_2 = 215;
  int numero_random_3 = 2222;

  lista_insertar(lista, &numero_random_1);
  lista_insertar(lista, &numero_random_2);
  lista_insertar(lista, &numero_random_3);
  
  lista_iterador_t* lista_iterador = lista_iterador_crear(lista);
  
  pa2m_afirmar(lista_iterador_elemento_actual(lista_iterador) == lista->nodo_inicio->elemento,"Elemento Actual del Iterador es el correcto");
  pa2m_afirmar(lista_iterador_elemento_actual(NULL) == NULL,"Iterador NULL devuelve NULL");

  lista_iterador->corriente = NULL;
  pa2m_afirmar(lista_iterador_elemento_actual(lista_iterador) == NULL,"Nodo actual NULL devuelve NULL");


  lista_iterador_destruir(lista_iterador);
  lista_destruir(lista);
}


bool comparar_elemento(void* elemento, void* contador){
  if(elemento && contador && (*(int*)elemento) > 0){
    (*(int*)contador)++;
    return true;
  }
  return false;
}


void prueboRecorrerLaLista_DevuelveCantidadElementosQueRecorrio(){
  lista_t* lista = lista_crear();
  lista_t* vacia_lista = lista_crear();
  lista_t* lista_con_un_elemento = lista_crear();

  int numero_random_1 = 82511;
  int numero_random_2 = 215;
  int numero_random_3 = 2222;
  int numero_random_4 = 0;

  lista_insertar(lista, &numero_random_1);
  lista_insertar(lista, &numero_random_2);
  lista_insertar(lista, &numero_random_3);
  lista_insertar(lista, &numero_random_4);

  lista_insertar(lista_con_un_elemento, &numero_random_1);
  
  lista_iterador_t* lista_iterador = lista_iterador_crear(lista);
  int contador = 0;
  pa2m_afirmar(lista_con_cada_elemento(lista, comparar_elemento, (void*)&contador) == 3,"Recorrio la lista y tiene 3 elementos validos");
  pa2m_afirmar(lista_con_cada_elemento(lista_con_un_elemento, comparar_elemento, (void*)&contador) == 1,"Recorrio la lista y tiene 1 elementos validos");
  pa2m_afirmar(lista_con_cada_elemento(NULL, comparar_elemento, (void*)&contador) == 0,"Lista iterador NULL devuelve 0");
  pa2m_afirmar(lista_con_cada_elemento(lista, NULL, (void*)&contador) == 0,"Lista iterador con funcion para comaparar NULL devuelve 0");
  pa2m_afirmar(lista_con_cada_elemento(vacia_lista, comparar_elemento, (void*)&contador) == 0,"Lista vacia devuelve 0");



  lista_iterador_destruir(lista_iterador);
  lista_destruir(lista);
  lista_destruir(vacia_lista);
  lista_destruir(lista_con_un_elemento);
}


void prueboCrearUnaCola_DevuelveCola_SiNoDevuelveNULL(){
  cola_t* cola;

  pa2m_afirmar((cola = cola_crear()),"Crear Cola devuelve una cola");
  pa2m_afirmar(cola_tamanio(cola) == 0,"El tamanio de la cola recien creada es cero");

  cola_destruir(cola);
}


void prueboEncolarUnElemento_DevuelveLaCola_SiFallaDevuelveNULL(){
  cola_t* cola = cola_crear();

  int numero_random_1 = 154;

  pa2m_afirmar(cola_encolar(NULL, &numero_random_1) == NULL,"Encolar un elemento a una cola NULL devuelve NULL");
  pa2m_afirmar(cola_encolar(cola, &numero_random_1),"Al encolar un elemento se encola correctamente");
  pa2m_afirmar(cola_tamanio(cola) == 1,"Al encolar un elemento aumenta la cantidad");
  //pa2m_afirmar((cola->lista->nodo_fin->elemento == &numero_random_1),"El elemento encolado es correcto");

  cola_destruir(cola);
}


void prueboDesencolarUnElemento_DevuelveElElementoDesencolado_SiNoDevuelveNULL(){
  cola_t* cola = cola_crear();
  cola_t* cola_vacia = cola_crear();

  int numero_random_1 = 154;
  int numero_random_2 = 5451;
  int numero_random_3 = 36;

  cola_encolar(cola, &numero_random_1);
  cola_encolar(cola, &numero_random_2);
  cola_encolar(cola, &numero_random_3);

  pa2m_afirmar(cola_desencolar(cola_vacia) == NULL,"Desencolar una cola vacia devuelve NULL");
  pa2m_afirmar(cola_desencolar(cola),"Se desencola un elemento correctamente");
  pa2m_afirmar(cola_desencolar(cola) == &numero_random_2, "Se desencola el elemento correcto");
  pa2m_afirmar(cola_tamanio(cola) == 1,"Al desencolar un elemento se reduce la cantidad");
  
  cola_destruir(cola_vacia);
  cola_destruir(cola);
}


void prueboVerElElementoEnfrenteDeLaCola_DevuelveElElemento_SiNoDevuelveNULL(){
  cola_t* cola = cola_crear();
  cola_t* cola_vacia = cola_crear();

  int numero_random_1 = 154;
  int numero_random_2 = 5451;
  int numero_random_3 = 36;

  cola_encolar(cola, &numero_random_1);
  cola_encolar(cola, &numero_random_2);
  cola_encolar(cola, &numero_random_3);

  pa2m_afirmar(cola_frente(cola_vacia) == NULL,"Ver el elemento primero de una cola vacia es NULL");
  pa2m_afirmar(cola_frente(NULL) == NULL,"Ver el elemento primero de una cola NULL es NULL");
  pa2m_afirmar(cola_frente(cola) == &numero_random_1,"Ver el elemento primero de una cola devuelve el primer elemento");

  
  cola_destruir(cola_vacia);
  cola_destruir(cola);
}


void prueboVerSiLaColaEstaVacia_DevuelveTrueSiEstaVacia_CasoContrarioDevuelveFalse(){
  cola_t* cola = cola_crear();
  cola_t* vacia_cola = cola_crear();

  int numero_random_1 = 154;
  int numero_random_2 = 5451;
  int numero_random_3 = 36;

  cola_encolar(cola, &numero_random_1);
  cola_encolar(cola, &numero_random_2);
  cola_encolar(cola, &numero_random_3);

  pa2m_afirmar(cola_vacia(vacia_cola),"Cola vacia devuelve true");
  pa2m_afirmar(cola_vacia(NULL),"Cola Null devuelve true");
  pa2m_afirmar(!cola_vacia(cola),"Cola NO vacia devuelve false");

  
  cola_destruir(vacia_cola);
  cola_destruir(cola);
}


void prueboCrearUnaPila_DevuelveLaPila_SiNoDevuelveNULL(){
  pila_t* pila;

  pa2m_afirmar((pila = pila_crear()), "Crear una pila devuelve una pila");
  pa2m_afirmar(pila_tamanio(pila) == 0,"Al crear una pila esta se crea vacia");

  pila_destruir(pila);
}


void prueboApilarUnElementoEnUnaPila_DevuelveLaPila_SiNoDevuelveNULL(){
  pila_t* pila = pila_crear();

  int numero_random_1 = 6516;

  pa2m_afirmar(pila_apilar(NULL, &numero_random_1) == NULL,"Al apilar un elemento en una pila NULL devuelve NULL");
  pa2m_afirmar((pila = pila_apilar(pila, &numero_random_1)), "Al apilar un elemento una pila devuelve una pila");
  pa2m_afirmar(pila_tamanio(pila) == 1,"Al apilar un elemento una pila el tamanio de esta aumenta");

  pila_destruir(pila);
}


void prueboDesapilarUnElementoEnUnaPila_DevuelveElElementoDesapilado_SiNoDevuelveNULL(){
  pila_t* pila = pila_crear();
  pila_t* vacia_pila = pila_crear();

  int numero_random_1 = 6516;
  int numero_random_2 = 21;
  int numero_random_3 = 78;

  pila = pila_apilar(pila, &numero_random_1);
  pila = pila_apilar(pila, &numero_random_2);
  pila = pila_apilar(pila, &numero_random_3);

  pa2m_afirmar(pila_desapilar(NULL) == NULL,"Al desapilar un elemento en una pila NULL devuelve NULL");
  pa2m_afirmar(pila_desapilar(vacia_pila) == NULL,"Al desapilar un elemento en una pila vacia devuelve NULL");
  pa2m_afirmar(pila_desapilar(pila) == &numero_random_3, "Al desapilar un elemento de una pila devuelve el elemento desapilado");
  pa2m_afirmar(pila_tamanio(pila) == 2,"Al desapilar un elemento de una pila la cantidad de elementos disminuye");

  pila_destruir(vacia_pila);
  pila_destruir(pila);
}


void prueboVerElTopeDeUnaPila_DevuelveElElementoEnLaPosicionTopeDeLaPila_SiFallaOEstaVaciaDevuelveNULL(){
  pila_t* pila = pila_crear();
  pila_t* vacia_pila = pila_crear();

  int numero_random_1 = 6516;
  int numero_random_2 = 21;
  int numero_random_3 = 78;

  pila = pila_apilar(pila, &numero_random_1);
  pila = pila_apilar(pila, &numero_random_2);
  pila = pila_apilar(pila, &numero_random_3);

  pa2m_afirmar(pila_tope(NULL) == NULL,"Al ver el tope de una pila NULL devuelve NULL");
  pa2m_afirmar(pila_tope(vacia_pila) == NULL,"Al ver el tope de una pila vacia devuelve NULL");
  pa2m_afirmar(pila_tope(pila) == &numero_random_3, "Al ver el tope de una pila devuelve el elemento en esa posicion");

  pila_destruir(vacia_pila);
  pila_destruir(pila);
}


void prueboVerSiLaPilaEstaVacia_DevuelveTrueSiEstaVacia_CasoContrarioDevuelveFalse(){
  pila_t* pila = pila_crear();
  pila_t* vacia_pila = pila_crear();

  int numero_random_1 = 6516;
  int numero_random_2 = 21;
  int numero_random_3 = 78;

  pila = pila_apilar(pila, &numero_random_1);
  pila = pila_apilar(pila, &numero_random_2);
  pila = pila_apilar(pila, &numero_random_3);

  pa2m_afirmar(pila_vacia(NULL),"Al ver si una pila NULL esta vacia devuelve true");
  pa2m_afirmar(pila_vacia(vacia_pila),"Al ver si una pila vacia esta vacia devuelve true");
  pa2m_afirmar(!pila_vacia(pila), "Al ver si una pila esta vacia devuelve false");

  pila_destruir(vacia_pila);
  pila_destruir(pila);
}


int main() {
  pa2m_nuevo_grupo("Pruebas de Crear Lista y Destruirla");
  prueboCrear_y_DestruirUnaLista();

  pa2m_nuevo_grupo("Pruebas de Insertar un Elemento al Final de la Lista");
  prueboInsertarUnElementoAlFinalDeLaLista_DevuelveUnaLista();

  pa2m_nuevo_grupo("Pruebas de Insertar un Elemento en Una Posicion Dada");
  prueboInsertarUnElementoEnUnaPosicionDada_DevuelveUnaLista();

  pa2m_nuevo_grupo("Pruebas de Quitar Elemento del Final de Una Lista");
  prueboQuitarUnElementoDelFinalDeUnaLista_DevuelveElElemento_DeNoSerAsiDevuelveNULL();

  pa2m_nuevo_grupo("Pruebas de Quitar Elemento en Posicion de Una Lista");
  prueboQuitarUnElementoDeUnaPosicionDada_DevuelveElElemento_DeNoSerAsiDevuelveNULL();

  pa2m_nuevo_grupo("Pruebas de Devolver Elemento de Una Posicion Dada");
  prueboDevolverElElementoDeUnaPosicionDada_DevuelveElElemento_DeNoSerAsiDevuelve_NULL();
  
  pa2m_nuevo_grupo("Pruebas de Devolver el Primer Elemento de Una Lista");
  prueboPedirElPrimerElementoDeLaLista_DevuelveElElemento_DeNoSerAsiDevuelveNULL();

  pa2m_nuevo_grupo("Pruebas de Devolver el Ultimo Elemento de Una Lista");
  prueboPedirElUltimoElementoDeLaLista_DevuelveElElemento_DeNoSerAsiDevuelveNULL();

  pa2m_nuevo_grupo("Pruebas de Ver Si La Lista Esta Vacia o Si No Existe");
  prueboVerSiLaListaEstaVacia_O_NoExiste_DevuelveTrueSiEstaVaciaONoExiste_AlRevezEnElCasoContrario();

  pa2m_nuevo_grupo("Pruebas de Tamanio de Lista");
  prueboDevolverElTamanioDeUnaLista();

  pa2m_nuevo_grupo("Pruebas de Crear Una Lista Iterador");
  prueboCrearUnaListaIterador_DevuelveUnPunteroAlIteradorCreado();

  pa2m_nuevo_grupo("Pruebas de Ver Si Hay Un Elemento o Mas Para Iterar");
  prueboVerSiHayUnElementoOMasParaIterar_SiEsAsiDevuelveTrue();

  pa2m_nuevo_grupo("Pruebas de Avanzar El Iterador Una Posicion");
  prueboAvanzarElIteradorUnElemento_DevuelveTrueSiPudoHacerlo();

  pa2m_nuevo_grupo("Pruebas de Saber El Elemento Actual Del Iterador");
  prueboPedirElElementoActualDelIterador();

  pa2m_nuevo_grupo("Pruebas de Lista Con Cada Elemento");
  prueboRecorrerLaLista_DevuelveCantidadElementosQueRecorrio();

  pa2m_nuevo_grupo("Pruebas de Crear Una Cola");
  prueboCrearUnaCola_DevuelveCola_SiNoDevuelveNULL();

  pa2m_nuevo_grupo("Pruebas de encolar un elemento");
  prueboEncolarUnElemento_DevuelveLaCola_SiFallaDevuelveNULL();

  pa2m_nuevo_grupo("Pruebas de desencolar un elemento");
  prueboDesencolarUnElemento_DevuelveElElementoDesencolado_SiNoDevuelveNULL();

  pa2m_nuevo_grupo("Pruebas de elemento del frente de la cola");
  prueboVerElElementoEnfrenteDeLaCola_DevuelveElElemento_SiNoDevuelveNULL();

  pa2m_nuevo_grupo("Pruebas de ver si la cola esta vacia");
  prueboVerSiLaColaEstaVacia_DevuelveTrueSiEstaVacia_CasoContrarioDevuelveFalse();

  pa2m_nuevo_grupo("Pruebas de Crear Una Pila");
  prueboCrearUnaPila_DevuelveLaPila_SiNoDevuelveNULL();

  pa2m_nuevo_grupo("Pruebas de Apilar Un Elemento en Una Pila");
  prueboApilarUnElementoEnUnaPila_DevuelveLaPila_SiNoDevuelveNULL();

  pa2m_nuevo_grupo("Pruebas de Desapilar Elementos de Una Pila");
  prueboDesapilarUnElementoEnUnaPila_DevuelveElElementoDesapilado_SiNoDevuelveNULL();

  pa2m_nuevo_grupo("Pruebas de Saber El Tope de Una Pila");
  prueboVerElTopeDeUnaPila_DevuelveElElementoEnLaPosicionTopeDeLaPila_SiFallaOEstaVaciaDevuelveNULL();

  pa2m_nuevo_grupo("Pruebas de ver si la Pila esta vacia");
  prueboVerSiLaPilaEstaVacia_DevuelveTrueSiEstaVacia_CasoContrarioDevuelveFalse();

  return pa2m_mostrar_reporte();
}
