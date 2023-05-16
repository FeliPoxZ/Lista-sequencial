#include <stdio.h> //testar com return stack apos o if na função create
#include <stdlib.h>
#include <stdint.h>
#include "stack.h"
typedef enum {false, true} bool;
bool stack_has_elementy (Stack*);

struct stack
{
    int stack_size;
    int stack_length;
    int* stack_array;
};


//Create a stack in memory heap
Stack* stack_create(int size){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    //verify if alocation happened with success
    if (stack != NULL){ 
        stack->stack_size = size;
        stack->stack_length = 0;
        stack->stack_array = (int*)malloc(sizeof(int)*size);
        return stack; //return a pointer with a adress memory
    }   
}

//free the memory what the stack use in heap memory  
void stack_free(Stack* stack){
    free(stack->stack_array);
    free(stack);
}



/* Verify if the stack are full or not
    if the stack is full this function return true (true == 1)
    if the stack isn't full this function return false (false == 0)
*/
int stack_is_full(Stack* stack){
    if (stack->stack_length == stack->stack_size){
        return true;
    }
    else{
        return false;
    }
}


/* Verify if the stack are empty ore not
    if the stack is empty this function return true (true == 1)
    if the stack isn't empty this function return false (false == 0)
*/
int stack_is_empty(Stack* stack){
    if (stack->stack_length == 0){
        return true;
    }
    else{
        return false;
    }
}

/*Verify if the stack has an element (so isn't empty)
    return 1 (or true) if stack has at least one item
    return 0 (or false) if stack don't have any item
*/

bool stack_has_elementy (Stack* stack){
    return !stack_is_empty(stack);
}


//add a new item at the end of stack (at the top of it)
void stack_push(Stack* stack, int value){
    if (stack_is_full(stack)){
        printf("ERROR\nThe stack is FULL!\n");
        return;
    }
    //if the stack isn't full
    else{
        stack->stack_array[stack->stack_length] = value;
        stack->stack_length = stack->stack_length + 1;
        return;
    }
}

/*Remove and return the last item (at the top of it) of stack*/
int stack_pop(Stack* stack){
    int value_removed = stack->stack_array[stack->stack_length - 1];
    //if the stack has any item
    if (stack_has_elementy(stack)){
        stack->stack_array[stack->stack_length-1] = (uintptr_t)NULL;
        stack->stack_length = stack->stack_length - 1;
        return value_removed;
    }
    //if the stack is empty
    else{
        printf("ERROR!\nThe stack is empty\n");
        return -1; 
    }
}

//return (but don't remove) the item of the index passed by the user
int stack_peek(Stack* stack, int index){
    int return_value;
    //if the stack has any item
    if (stack_has_elementy(stack)){
        if ((index >=0) || (index < stack->stack_length)){
            return_value = stack->stack_array[index];
            return return_value;
        }
        else{
            printf("ERROR!\nInvalid index");
            return -1;           
        }
    }
    // if the stack is empty
    else{
        printf("ERROR!\nThe stack is empty\n");
        return -1;
    }
}


//return (but don't remove) the last item of the stack
int stack_top(Stack* stack){
    int return_value;
    //if the stack has any item
    if (stack_has_elementy(stack)){
        return_value = stack->stack_array[stack->stack_length-1];
        return return_value;
    }
    //if the stack is empty
    else{
        printf("ERROR!\nThe stack is empty\n");
        return -1;

    }
}

void stack_display(Stack* stack){
    for (int i = 0; i < stack->stack_length; i++)
    {
        printf("%i ", stack->stack_array[i]);
    }

    printf("\n");
    printf("size -> %i", stack->stack_size);
    printf("\n");
    printf("length -> %i", stack->stack_length);
    printf("\n");
    
}

//always data stucture start at 0