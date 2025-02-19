//first approach
#include <stdio.h>
#include<stdlib.h>
typedef struct stackImplementation{
    int data;
    struct stackImplementation* nextNode;
}stackImplementation;
void addStack(stackImplementation** head, int data);
void viewStack(stackImplementation* head);
void popStack(stackImplementation** head);
int peekStack(stackImplementation* head);
int main(void) {
    stackImplementation* head = NULL;
    addStack(&head,10);
    addStack(&head,11);
    addStack(&head,2);
    popStack(&head);
    addStack(&head,15);
    printf("%d\n",peekStack(head));
    viewStack(head);
    return 0;
}
void addStack(stackImplementation** head, int data){
    //add to the start
    stackImplementation* newStack = (stackImplementation*)malloc(sizeof(stackImplementation));
    if(newStack == NULL){
        printf("Out of ram\n");
        exit(EXIT_FAILURE);
    }
    newStack->data = data;
    newStack->nextNode = NULL;
    //check if head node empty
    if(*head == NULL){
        *head = newStack;
    }
    else{
        newStack->nextNode = *head;
        *head = newStack; // update head again
    }
}
void viewStack(stackImplementation* head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->nextNode;
    }
}
void popStack(stackImplementation** head){
    if(*head == NULL){
        printf("You don't have node to deleted\n");
    }
    else{
        stackImplementation* currentNode = *head;
        *head = currentNode->nextNode;
        free(currentNode);
    }
}
int peekStack(stackImplementation* head){
    return head->data;
}