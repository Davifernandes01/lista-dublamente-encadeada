#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>


// node da lista duplamente encadeada
 typedef struct _doubly_node{

   int val;
   struct _doubly_node *next;
   struct _doubly_node *prev;

 } Node;

 //lista duplamente encadeada

 typedef struct _doubly_list {
    
    Node *begin;
    Node *end;
    size_t size;
 } List;



/**
 * @brief funcao que retorna se a lista esta vazia ou não
 * @param list a lista em si
 * @author davi fernandes
*/
bool list_is_empty(const List *list){

  return list->size == 0;

}

/**
 * @brief criação do nó em si
 * @return retorna um nó
 * @author davi fernandes
*/

Node *create_doubly_node(int val){

  Node *node = (Node*) calloc(1, sizeof(Node));
  node->next = NULL;
  node->prev = NULL;
  node->val = val;

  return node;

}

/***
 * @brief criação da 'cabeça do nó' e setando o begin, end como null e size como 0
 * @return retorna uma lista encadeada
 * @author davi fernandes
*/
List *create_doubly_list(){

  List *list = (List*) calloc(1, sizeof(List));
  list->begin = NULL;
  list->end = NULL;
  list->size = 0;

}


/**
 * 
 * @brief funcao criada para destruir a lista duplamente encadeada, junto com seus nodes
 * primeiro se cria os nodes auxilizares, 'pos' e 'previous', apos isso faço um while para percorrer
 * todos os nodes da lista, enquanto estiver no while, o 'previous' passará a valor o valor do 'pos' e o 'pos', valerá o seu proximo
 * valor, no final do while, desalocamos o 'previous', apagando o valor contido nele, isso, enquanto a lista nao estiver nula
 * quando estiver, quer dizer que a lista esta vazia, entao desalocamos a lista em si.
 * 
 * @param list, referencia da lista que criamos
 * @author davi fernandes
*/
void destroy_doubly_list(List **list){

    List *aux = *list;
    Node *node = aux->begin;
     Node *previous = NULL;
     
    while(node != NULL){

      previous = node;
      node = node->next;
      free(previous);

    }

    free(aux);

    *list = NULL;
}


/***
 * @param list a lista duplamente encadeada  que criamos
 * @param val valor do nó
 * @return void
 * 
 * @brief função para adicionar o primeiro elemento na lista!, primeiro criamos o node, apos isso no if:
 *  caso esteja vazia, apontamos os ponteiro begin e end para o node,
 * caso a lista ja tenha elementos:
 * apontamos o node criado para o elemento do começo da lista.
 * depois fazemos com que o atributo 'prev'(anterior) do elemento do começo da lista, aponte para o node criado.
 * apos isso o começo da lista, recebe o node criado, assim colocamos ele no começo da lista
 * 
 * em ambos os casos, aumentamos o tamanho da lista em 1;
 * @author davi fernandes

*/

void list_add_first(List *list, int val){

  Node *node = create_doubly_node(val);

  if(list_is_empty(list)){
      
      list->end = node;
     
  }else{

      node->next = list->begin; //aponta para o elemento do começo da lista
      list->begin->prev = node; //ponteiro 'prev'(anterior) do elemento apontando pelo begin, aponta para o node
  }

  list->begin = node; //begin passa a apontar para o node criados
  list->size++; //aumenta a lista em 1
}


void list_add_last(List *list, int val){

  Node *node = create_doubly_node(val);

  if(list_is_empty(list)){

      list->begin = node;
      

  }else{

      list->end->next = node;
      node->prev = list->end;
      
  }
    list->end = node;
    list->size++;
}

/***
 * @brief printando os elementos da lista, um a um, primeiro criamos um no apontando para o primeiro 
 * item da lista, apos isso, fazemos um while para, quanto o node não apontar para nulo, printamos na tela o valor
 * que o node aponta atualmente e depois, apontamos o node para o proximo elemento da lista.
 * @param list a lista encadeada criada
 * 
*/
void List_print(const List *list){

    Node *node = list->begin;

  printf("List: ");
    while(node != NULL){
         printf("%d ->", node->val);
         
         node =node->next;
    }


    printf("Size: %lu\n", list->size);
    puts("");

}

/**
 * @brief faz a mesma coisa que a função anterior, so que printa os elementos da lista começando do final dela;
*/
void List_print_inverted(const List *list){

    Node *node = list->end; //aponta para o final dela

  printf("List -> end: ");
    while(node != NULL){
         printf("%d ->", node->val);
         
         node =node->prev; //ponteiro 'prev' aponta para o nó anterior do elemento node;
    }


    printf("Size: %lu\n", list->size);
    puts("");

}




