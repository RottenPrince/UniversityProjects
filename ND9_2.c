#include <stdio.h>
#include <stdlib.h>

typedef struct    // a
{
    int *arr;
    unsigned int size;
}Stack;

void initStack(Stack *stack);
void printStack(Stack *stack);
int getStackSize(Stack *stack);
void push(Stack *stack, int value);
int top(Stack *stack);
int pop(Stack *stack);
void destroyStack(Stack *stack);

int main()
{
    Stack element;
    int value;

    initStack(&element);
    printStack(&element);

    unsigned int SIZE = getStackSize(&element);

    push(&element, value);

    int last = top(&element);
    last = pop(&element);

    destroyStack(&element);
    return 0;
}

void initStack(Stack *stack) // b
{
    stack->arr = calloc(sizeof(int), 1); // masyvui atlaisvinama int dydzio vietos atmintyje
    if(stack->arr == NULL) // tikrinama ar masyvui pavyko atlaisvinti atminties
        free(stack); // jei ne tai steko vieta yra atlaisvinama
    stack->size = 0; // (*stack).size = 0 
}

void printStack(Stack *stack) // c
{
    int i;
    for(i = 0; i < stack->size; ++i)
    {
        printf("%d  ", stack->arr[i]);
    }
    printf("\n");
}

int getStackSize(Stack *stack) // d
{
    return stack->size;
}

void push(Stack *stack, int value) // d
{
    ++(stack->size); // padidinamas masyvo dydis vienu daugiau
    stack->arr = realloc(stack->arr, (stack->size*sizeof(int))); // atlaisvinama masyvui daugiau atminties
    stack->arr[stack->size - 1] = value;
}

int top(Stack *stack) // e
{
    if(stack->arr == NULL) // tikrinama ar masyvas nera tuscias
        return 0;
    return stack->arr[stack->size - 1]; // grazinama paskutine masyvo reiksme
}

int pop(Stack *stack) // f
{
    //stack->arr[stack->size - 1] = NULL; // paskutini masyvo elementa panaikina
    --(stack->size); // sumazinamas masyvo dydis per viena
    return top(stack);
}

void destroyStack(Stack *stack) // g
{
    free(stack->arr);// atlaisvinama masyvo uzimamos atminties dalis
}