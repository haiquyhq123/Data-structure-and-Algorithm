#include <stdio.h>
#include <stdlib.h>
typedef struct LinkList{
    int data;
    struct LinkList* nextNode;
}LinkList;
void addBack(LinkList** head,LinkList** tail, int value);
void addFront(LinkList** head,LinkList** tail, int value);
void search(LinkList* head, int value);
void deleteLinkList(LinkList** head,LinkList** tail, int value);
void displayLinkList(LinkList* head);
void freeMemory(LinkList* head, LinkList* tail);
int main() {
    return 0;
}
void addFront(LinkList** head,LinkList** tail, int value){
    // init new node to add front
    LinkList* newNode = (LinkList*)malloc(sizeof(LinkList*));
    newNode->data = value;
    newNode->nextNode = NULL;
    //case 1: add first element
    if(*head == NULL){
        *head = newNode;
        *tail = newNode;
    }
    //case 2: add second element
    else if(*head == *tail){
        newNode->nextNode = *head;
        *head = newNode;
    }
    //case 3: add element to the list that already have 2 element
    else if(*head != *tail){
        newNode->nextNode = *head;
        *head = newNode;
    }
}
void addBack(LinkList** head,LinkList** tail, int value){
    LinkList* newNode = (LinkList*)malloc(sizeof(LinkList*));
    newNode->data = value;
    newNode->nextNode = NULL;
    //case 1: add first element 
    if(*head == NULL){
        *head = newNode;
        *tail = newNode;
    }
    //case 2: already have 1 or more
    else{
        (*tail)->nextNode = newNode;
        *tail = newNode;
    }
}
void search(LinkList* head, int value){
    LinkList* iteration = head;
    int i = 1;
    while(iteration != NULL){
        if(iteration->data == value){
            printf("Your value at %d position\n",i);
            break;
        }
        iteration = iteration->nextNode;
        i++;
    }
}
void deleteLinkList(LinkList** head,LinkList** tail, int value){
    if(*head == NULL){
        printf("Nothing to delete\n");
        exit(EXIT_FAILURE);
    }
    //case 1: have 1 element
    if(*head == *tail){
        if((*head)->data == value){
            printf("found!\n");
            LinkList* deleteElement = *head;
            (*head)->nextNode = NULL;
            (*tail)->nextNode = NULL;
            free(deleteElement);
            exit(EXIT_SUCCESS);
        }
        else{
            printf("Not found!\n");
        }
    }
    //case 2: have more than two
    else{
        LinkList* prev = NULL;
        LinkList* current = *head;
        while(current->nextNode != NULL && current->data != value){
            prev = current;
            current = current->nextNode;
        }
        // delete first one
        if(prev == NULL && current->data == value){
            *head = current->nextNode;
            free(current);
            LinkList* updateTail = *head;
            while(updateTail->nextNode != NULL){
                updateTail = updateTail->nextNode;
            }
            *tail = updateTail;
        }
        else if(current->data == value){
            prev->nextNode = current->nextNode;
            free(current);
            LinkList* updateTail = *head;
            while(updateTail->nextNode != NULL){
                updateTail = updateTail->nextNode;
            }
            *tail = updateTail;
        }
        else{
            printf("Not found!\n");
        }
    }
}
void displayLinkList(LinkList* head){
    LinkList* iteration = head;
    while(iteration != NULL){
        printf("%d ",iteration->data);
        iteration = iteration->nextNode;
    }
    printf("\n");
}
void freeMemory(LinkList* head, LinkList* tail){
    LinkList* iteration = head;
    LinkList* current;
    while(iteration != NULL){
        LinkList* current = iteration->nextNode;
        free(iteration);
        iteration = current;
    }
    head = NULL;
    tail = NULL;
}