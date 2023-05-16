#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <stdint.h>
typedef enum {false, true} bool;
void queue_deque_shift (Queue*);
bool queue_has_element(Queue*);


struct queue
{
    int queue_size;
    int queue_length;
    int *queue_array;
};

/*cria a fila a partir do tamanho dado pelo usuario e verifica a locacação
  em caso de exito retorna o ponteiro da fila
  em caso negativo retorna um ponteiro vazio
  */

Queue* queue_create(int size){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue != NULL){
        queue->queue_size = size;
        queue->queue_length = 0;
        queue->queue_array = (int*)malloc(sizeof(int)*size);
        return queue;
    }
    else{
        queue = NULL;
        return queue;
    }    
}

//libera a memoria
void queue_free(Queue* queue){
    free(queue->queue_array);
    free(queue);
}


/*verifica se a fila esta cheia
    em caso positivo (esta cheia) retorna 1 (ou true)
    em caso negativo (não esta cheia) retorna 0 (ou false)
*/
int queue_is_full(Queue* queue){
    if (queue->queue_length == queue->queue_size){
        return true; //return 1 (true) if queue is full
    }
    else{
        return false; //return 0 (false) if queue is not full
    }
}


/*Verifica se a fila esta vazia
    em caso positivo (esta vazia) retorna 1 (ou true)
    em caso negativo (nao esta vaiza) retorna 0 (ou false)
*/
int queue_is_empty (Queue* queue){
    if (queue->queue_length == 0){
        return true; //return 1(true) if queue is empty (vazia)
    }
    else{
        return false; //return 0 (false) if queue isn't empty (não está vazia)
    }
}



//adiciona um item no final da fila, fazendo as verificações do estatus da fila
void queue_enqueue(Queue* queue, int value){
    //se a fila estiver cheia
    if (queue_is_full(queue)){
        printf("FIla cheia\n"); 
        return;
    }
    //se a fila não estiver cheia
    else{   //em caso 

        queue->queue_array[queue->queue_length] = value;
        queue->queue_length++;
    }
    
}

 /*verifica se a file tem algum elemento (ou seja, não está vazia)
 retorna 1 se a fila tem ao menos um elemento
 retorna 0 se a fila não tem nenhum elemento
*/
bool queue_has_element(Queue *queue) {
    return !queue_is_empty(queue);
}

//retira e retorna o primeiro o item da fila (fazendo suas devidas vericações)
int queue_dequeue (Queue* queue){
    // se a fila tiver ao menos um elemento:
    int remove_value;
    if (queue_has_element(queue)){
        remove_value = queue->queue_array[0];
        queue_deque_shift (queue);
        return remove_value;
        
    }
    // se a file estiver vazia:
    else{
        printf("Erro\nFila fazia");
        return false;
    }
    
}

//apenas retorna o primeiro item da fila
int queue_first(Queue* queue){
    //se a fila tiver ao menos 1 item
    if (queue_has_element(queue))
    {
        int value = queue->queue_array[0];
        return value;
    }
    //se a fila esta vaiza
    else{
        return false;
    }

}    

//apenas retorna o ultimo item da fila
int queue_last(Queue* queue){
    //se a fila tiver ao menos 1 item
    if (queue_has_element(queue))
    {
        int value = queue->queue_array[queue->queue_length-1];
        return value;
    }
    //se a fila esta vazia
    else{
        return false;
    }

}

//printa toda a fila
void queue_display(Queue* queue){
    for (int i = 0; i < queue->queue_length; i++)
    {
        printf("%i ", queue->queue_array[i]);
    }
    
}


//reorganiza a fila após exclusão
void queue_deque_shift (Queue* queue){
    queue->queue_array[0] = (uintptr_t) NULL; //apaga o primeiro item
    for (int i = 0; i < queue->queue_length-1; i++){
        queue->queue_array[i] = queue->queue_array[i+1];
    }
    queue->queue_array[queue->queue_length-1] = (uintptr_t) NULL;
    queue->queue_length = queue->queue_length - 1; //reorganiza p lenght
}
