#include <stdio.h>
#include <stdlib.h>
typedef struct DoubleLinkList{
    int data;
    struct DoubleLinkList* nextNode;
    struct DoubleLinkList* prevNode;
}DoubleLinkList;
void addFront(DoubleLinkList** head, DoubleLinkList** tail, int value);
void addBack(DoubleLinkList** head, DoubleLinkList** tail, int value);
void deleteVal(DoubleLinkList** head, DoubleLinkList** tail, int value);
void printDoubleList(DoubleLinkList* head);
void freeList(DoubleLinkList** head);
int main() {
    return 0;
}
void addFront(DoubleLinkList** head, DoubleLinkList** tail, int value){
    DoubleLinkList* newNode = (DoubleLinkList*)malloc(sizeof(DoubleLinkList*));
    if(newNode == NULL){
        printf("No enough ram!");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->nextNode = NULL;
    newNode->prevNode = NULL;
    // case 1: nothing
    if((*head) == NULL){
        (*head) = newNode;
        (*tail) = newNode;
    }
    //case 2: already have more than 1
    else{
        newNode->nextNode = *head;
        (*head)->prevNode = newNode;
        *head = newNode;
    }
}
void addBack(DoubleLinkList** head, DoubleLinkList** tail, int value){
    DoubleLinkList* newNode = (DoubleLinkList*)malloc(sizeof(DoubleLinkList*));
    if(newNode == NULL){
        printf("No enough ram!");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->nextNode = NULL;
    newNode->prevNode = NULL;
    //case 1: nothing
    if((*head) == NULL){
        *head = newNode;
        *tail = newNode;
    }
    //case 2: have more than 1
    else{
        (*tail)->nextNode = newNode;
        newNode->prevNode = *tail;
        (*tail) = newNode;
    }
}
void deleteVal(DoubleLinkList** head, DoubleLinkList** tail, int value){
    if(*head == NULL){
        printf("Nothing to delete\n");
        exit(EXIT_FAILURE);
    }
    else{
        
        // case 1: have only 1
        if(*head == *tail && (*head)->data == value ){
            DoubleLinkList* needToDelete = *head;
            *head = NULL;
            *tail = NULL;
            free(needToDelete);
        }
        // case 2: have more than 2
        else{
            DoubleLinkList* iteration = *head;
            while(iteration->nextNode!=NULL && iteration->data != value){
                iteration = iteration->nextNode;
            }
            if(iteration->data == value){
                if(iteration->prevNode == NULL){
                    //delete first node
                    *head = iteration->nextNode;
                    (*head)->prevNode == NULL;
                    free(iteration);
                    
                }
                else if(iteration->nextNode == NULL){
                    //last element
                    *tail = iteration->prevNode;
                    (*tail) -> nextNode= NULL;
                    free(iteration);
                }
                else{
                    DoubleLinkList* previous = iteration->prevNode;
                    DoubleLinkList* next = iteration->nextNode;
                    previous->nextNode = next;
                    next->prevNode = previous;
                    free(iteration);
                    
                }
            }
        }
    }
    
}
void printDoubleList(DoubleLinkList* head){
    DoubleLinkList* iteration = head;
    while(iteration!=NULL){
        printf("%d ", iteration->data);
        iteration = iteration->nextNode;
    }
    printf("\n");
}
void freeList(DoubleLinkList** head)
{
	DoubleLinkList* current = *head;
	DoubleLinkList* nextStudent;

	while (current != NULL) {
		nextStudent = current->nextNode;
		free(current);
		current = nextStudent;
	}

	*head = NULL;
}