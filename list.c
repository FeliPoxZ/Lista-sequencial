#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <stdint.h>


void remove_from_right(List*, int);
void remove_from_middle(List*, int);
void resize_array_remove(List*);
void resize_array_add(List*);
void shift_insert (List*, int);


struct list{
    int *array; //inicializa o array da lista
    int size;//valor total do array
    int length; //casa utilizada
};

List* list_create(){
    List* list = (List*)malloc(sizeof(List));
    if (list != NULL){ //verifica se a alocação deu certo
        list->array = (int*)malloc(sizeof(int)*5); //alocou um vetor de 5 posições inteiro
        list->size = 5; 
        list->length = 0;
        return list; 
    }
}

void list_free(List* list){
    free(list->array);//libera apenas o array da lista
    free (list); //libera lista por completo
}

void list_add(List* list, int value){ //adiciona um item a lista
    if (list->length == list->size){
        resize_array_add(list); //realoca o tamanho do array de forma dinamica
        list->array[list->length] = value;
        list->length = list->length + 1;
    }
    else{
        list->array[list->length] = value;
        list->length = list->length + 1;
    }
}


int list_remove(List* list, int index){ //remove um intem da lista a partir do seu index
    int value;
    if (list->length == 0) { //verifica se a lista esta vazia
        printf("Error: lista vazia\n");
        return -1;
    }

    if ((index >= list->length) || (index < 0)){ //verifica se o index e valido
        printf("Endereço invalido\n");
        return -1;
    }

    value = list->array[index];

    if (index == list->length - 1){
        remove_from_right(list, index); //remove o ultimo item
        
    }
    else{
        remove_from_middle(list, index); //remove um item do meio da lista
    }

    if (list->length < list->size/2){
        resize_array_remove(list); //realoca o tamanho do array de forma dinamica
    }

    return value; //retorna o valor removido
    
}

void list_display (List* list){ //printa toda a lista
    for (int i = 0; i < list->length; i++){
        printf("%i ", list->array[i]);
    }
    
}

void list_set (List* list, int index, int value){ //modifica um valor da lista
    if ((index >= list->length) || (index < 0)) //verificação do index
    {
        printf("Index Invalido");
        return;
    }
    else{
        list->array[index] = value;
    }
    
    
        
}

void list_insert(List* list, int index, int value){ //realiza uma inserção na lista sem perder os outros itens
    if (list->length >= list->size){ 
        resize_array_add(list); //dobra o array
        shift_insert(list,index);
        list->array[index] = value; //insere um novo valor na posição desejada (que ja esta zerada)
        list->length = list->length+1;
    }
    else{
        shift_insert(list, index);
        list->array[index] = value; 
        list->length = list->length+1;
    }
}




void remove_from_right(List* list, int index){//função que remove o ultimo item da lista
    list->array[index] = (uintptr_t)NULL; 
    list->length = list->length - 1;     

}

void remove_from_middle(List* list, int index){ //função que remove um item do meio da lista e a reorganiza
    list->array[index] = (uintptr_t)NULL; 
    for (int i = index; i < list->length - 1; i++){
        list->array[i] = list->array[i+1];
    }
    list->array[list->length-1] =(uintptr_t)NULL; 
    list->length = list->length - 1;  
}

void resize_array_remove(List* list){ //função que realoca o tamanho da lista para metade do seu valor
    list->array = realloc (list->array, sizeof(int) * list->size/2);
    list->size = list->size/2;
}




void resize_array_add(List* list){//função que realoca o tamanho  da lista para o dobro do seu valor
    list->array = realloc (list->array, sizeof(int) * list->size * 2);
    list->size = list->size * 2;
}

void shift_insert (List* list, int index){ //função que faz o shift (invserso) da função insert
    list->array[list->length] = list->array[list->length-1];
    for (int i = list->length-1; i >index; i--)
    {
        list->array[i] = list->array[i-1];
    }
    list->array[index] = (uintptr_t)NULL;   //zera a posição do index 
}