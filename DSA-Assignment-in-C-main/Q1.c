//Program to evaluate postfix expression using Stack in C

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

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

int pop(st* s){
    if(isEmpty(s)){
        printf("The stack is empty");
        return 0;
    }
    else{
        int poppedItem = s->items[s->top];
        s->top--;
        return poppedItem;
    }
    count--;
}

void printStack(st *s){
    printf("Stack ");
    for (int i = 0; i < count; i++) {
        printf("%d",s->items[i]);
    }
    printf("\n");
}

int isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '/' || ch == '*'){
        return 1;
    }
    else
    {
        return 0;
    }
}

int evaluate(st *s, char* expression){
    int i = 0;
    char symbol = expression[i];
    int operand1, operand2, result;
    
    while(symbol != '\0'){
        if(symbol >= '0' && symbol <= '9'){
            int number = symbol - '0';
            push(s,number);
        }
        else if(isOperator(symbol)){
            operand2 = pop(s);
            operand1 = pop(s);
            switch(symbol){
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
            }
            push(s, result);
        }
        i++;
        symbol = expression[i];
    }
    result = pop(s);
    return result;
    
}

int main(){
    st *s = (st *)malloc(sizeof(st));
    char expression[] = "5 6 7 + * 8 -";
    int result = evaluate(s, expression);
    printf("Result is %d", result);
}
