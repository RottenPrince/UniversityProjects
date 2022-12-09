#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int x;
    int y;
}Point;

typedef struct    // a
{
    Point *arr;
    unsigned int size;
}Stack;

void initStack(Stack *stack);
void printStack(Stack *stack);
int getStackSize(Stack *stack);
void push(Stack *stack, Point p);
Point top(Stack *stack);
Point pop(Stack *stack);
void destroyStack(Stack *stack);
Point createPoint(double x, double y);
double getDistance(Point a, Point b);

int main()
{   
    Stack Taskas;
    Taskas.size = 5;
    Point t1, t2, t3, t4, t5;
    initStack(&Taskas); // paimama atmintis stackui

    /* Sukuriami taskai kiekvienai is 5 strukturu */
    t1 = createPoint(1, 5);
    t2 = createPoint(4, -8);
    t3 = createPoint(-3, -6);
    t4 = createPoint(23, -9);
    t5 = createPoint(6.8, -7.1);
    
    /* Idedami taskai i masyva */
    push(&Taskas, t1);
    push(&Taskas, t2);
    push(&Taskas, t3);
    push(&Taskas, t4);
    push(&Taskas, t5);
    
    printStack(&Taskas);
    destroyStack(&Taskas);
    
    return 0;
}

double getDistance(Point a, Point b)
{
    double distance = sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
    return distance;
}

Point createPoint(double x, double y)
{
    Point p;
    p.x = x;
    p.y = y;
    return p;
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
    Point centre;
    centre.x = 0, centre.y = 0; 

    for(i = 0; i < stack->size; ++i)
    {
        printf("%d)x = %2.1d, ", i+1, stack->arr[i].x);
        printf("y = %2.1d, ", stack->arr[i].y);
        printf("distance = %2.1lf\n", getDistance(centre, createPoint(stack->arr[i].x, stack->arr[i].y)));
    }
    printf("\n");
}

int getStackSize(Stack *stack) // d
{
    return stack->size;
}

void push(Stack *stack, Point p) // d
{
    ++(stack->size); // padidinamas masyvo dydis vienu daugiau
    stack->arr = realloc(stack->arr, (stack->size * sizeof(Point))); // atlaisvinama masyvui daugiau atminties
    stack->arr[stack->size - 1].x = p.x; // masyvo elementui x priskiriama x reiksme
    stack->arr[stack->size - 1].y = p.y; // masyvo elementui y priskiriama y reiksme
}

Point top(Stack *stack) // e
{
    Point empty;
    empty.x = 0, empty.y = 0; // pagaminama nuline struktura
    if(stack->arr != NULL) // tikrinama ar masyvas nera tuscias
        return stack->arr[stack->size - 1]; // grazinama Point struktura
    return empty; // grazinama tuscia struktura
}

Point pop(Stack *stack) // f
{
    //stack->arr[stack->size - 1] = NULL; // paskutini masyvo elementa panaikina
    --(stack->size); // sumazinamas masyvo dydis per viena
    return top(stack);
}

void destroyStack(Stack *stack) // g
{
    free(stack->arr);// atlaisvinama masyvo uzimamos atminties dalis
}