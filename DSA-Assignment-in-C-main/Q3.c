#include <stdio.h>
#include <stdlib.h>
#define MAX 7

int count = 0;

struct stack{
    int top;
    int items[MAX];
};

typedef struct stack st;

void createEmptyStack(st *s){
    s->top = -1;
}

int isFull(st *s){
    if(s->top == MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(st *s){
    if(s-> top == -1){
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(st *s, int newItem){
    if(isFull(s)){
        printf("Stack is already full");
    }
    else{
        s->top++;
        s->items[s->top] = newItem;
    }
    count++;
}

void pop(st* s){
    if(isEmpty(s)){
        printf("The stack is empty");
    }
    else{
        s->top--;
    }
    count--;
}

void printStack(st *s){
    printf("Stack ");
    for (int i = 0; i < count; i++) {
        printf("%d ",s->items[i]);
    }
    printf("\n");
}
int main()
{
  st *s = (st *)malloc(sizeof(st));

  createEmptyStack(s);

  push(s, 99);
  push(s, 20);
  push(s, 4);
  push(s, 27);
  printf("Before operation stack is ");
  printf("\n");
  printStack(s);
  
  push(s,5);
  printf("After pushing stack is ");
  printf("\n");
  printStack(s);
  printf("And position of top is %d",s->top);
  printf("\n");
  push(s,7);
  printf("After pushing stack is ");
  printf("\n");
  printStack(s);
  printf("And position of top is %d",s->top);
  printf("\n");
  pop(s);
  printf("After popping stack is ");
  printf("\n");
  printStack(s);
  printf("And position of top is %d",s->top);
  printf("\n");
  pop(s);
  printf("After popping stack is ");
  printf("\n");
  printStack(s);
  printf("And position of top is %d",s->top);
  printf("\n");
  pop(s);
  printf("After popping stack is ");
  printf("\n");
  printStack(s);
  printf("And position of top is %d",s->top);
  printf("\n");
}
