#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Stack{
    int topIndex;
    int* data;
}Stack;
const int maxSize = 5;
Stack* initializeStack(){
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->topIndex = -1;
    newStack->data = (int*)malloc(maxSize*sizeof(int));
    return newStack;
}
bool isStackEmpty(Stack* head);
bool isStackFull(Stack* head);
void add(Stack* head, int value);
int pop(Stack* head);
int peek(Stack* head);
int main() {
    Stack* stack = initializeStack();
    return 0;
}
bool isStackEmpty(Stack* head){
    if(head->topIndex==-1){
        return true;
    }
    return false;
}
bool isStackFull(Stack* head){
    if((head->topIndex)+1==maxSize){
        return true;
    }
    return false;
}
void add(Stack* head, int value){
    if(isStackFull(head)==true){
        printf("Stack is full\n");
    }
    else{
        head->data[++(head->topIndex)] = value;
    }
}
int pop(Stack* head){
    if(isStackEmpty(head)==true){
        printf("Empty\n");
        return -1;
    }
    else{
        return head->data[head->topIndex--];
    }
}
int peek(Stack* head){
    return head->data[head->topIndex];
}