#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    char item;
    struct Stack * prox;
}Stack;

Stack * push(Stack * stack, char item){
    Stack * tmp = (Stack*) malloc(sizeof(Stack));
    tmp->item = item;
    tmp->prox = stack;
    stack = tmp;
    return stack;
}

Stack * pop(Stack * stack){
    Stack * top = stack;
    stack = stack->prox;
    free(top);
    return stack;
}