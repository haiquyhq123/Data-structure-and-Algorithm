#include <stdio.h>
#include <stdlib.h>
typedef struct sortedLinkList{
    int data;
    struct sortedLinkList* nextNode;
}sortedLinkList;
void insert(sortedLinkList** head, int value);
void display(sortedLinkList* head);
void deleteHead(sortedLinkList** head);
void deleteTail(sortedLinkList** head);
void deleteValue(sortedLinkList** head, int value);
void FreeList(sortedLinkList** head);
int main() {
    sortedLinkList* head = NULL;
    return 0;
}
void insert(sortedLinkList** head, int value){
    sortedLinkList* newNode = (sortedLinkList*)malloc(sizeof(sortedLinkList*));
    if(newNode == NULL){
        printf("Not enough ram!\n");
        return;
    }
    newNode->data = value;
    newNode->nextNode = NULL;
    if(*head == NULL || (*head)->data > value){
        //insert front
        newNode->nextNode = *head;
        *head = newNode;
        return;
    }
    sortedLinkList* iteration = *head;
    while(iteration->nextNode!=NULL && iteration->nextNode->data < value){
        iteration = iteration->nextNode;
    }
    sortedLinkList* insertNodeBefore = iteration->nextNode;
    iteration->nextNode = newNode;
    newNode->nextNode = insertNodeBefore;
}
void display(sortedLinkList* head){
    sortedLinkList* iteration = head;
    while(iteration!=NULL){
        printf("%d ",iteration->data);
        iteration = iteration->nextNode;
    }
}
void deleteHead(sortedLinkList** head){
    //case 1: nothing
    if(*head == NULL){
        printf("Nothing to delete!");
        return;
    }
    //case 2: 1 element
    else if((*head)->nextNode == NULL){
        sortedLinkList* needToBeFree = *head;
        *head = NULL;
        free(needToBeFree);
    }
    //case 3: over 2
    else{
        sortedLinkList* needToBeFree = *head;
        *head = (*head)->nextNode;
        free(needToBeFree);
    }
}
void deleteTail(sortedLinkList** head){
    //case 1: nothing
    if(*head == NULL){
        printf("Nothing to delete!");
        return;
    }
    //case 2: 1 element
    else if((*head)->nextNode == NULL){
        sortedLinkList* needToBeFree = *head;
        *head = NULL;
        free(needToBeFree);
    }
    //case 3: over 2
    else{
        sortedLinkList* currentElement = *head;
        while(currentElement->nextNode->nextNode != NULL){
            currentElement = currentElement->nextNode;
        }
        sortedLinkList* nodeToBeDelete = currentElement->nextNode;
        currentElement->nextNode = NULL;
        free(nodeToBeDelete);
    }
}
void deleteValue(sortedLinkList** head, int value){
    if(*head == NULL){
        printf("Nothing to delete!");
        return;
    }
    //case 2: 1 element
    else if((*head)->nextNode == NULL && (*head)->data == value){
        sortedLinkList* needToBeFree = *head;
        *head = NULL;
        free(needToBeFree);
    }
    //case 3: over 2
    else{
        sortedLinkList* prev = NULL;
        sortedLinkList* currentElement = *head;
        while(currentElement->nextNode != NULL && currentElement->data != value){
            prev = currentElement;
            currentElement = currentElement->nextNode;
        }
        //case 1: delete head
        if(prev==NULL && currentElement->data == value){
            sortedLinkList* needToBeDelete = *head;
            (*head) = (*head)->nextNode;
            free(needToBeDelete);
        }
        //case 2: delete mid and end
        else if(currentElement->data == value){
            sortedLinkList* needToBeDelete = currentElement;
            prev->nextNode = currentElement->nextNode;
            free(needToBeDelete);
        }
    }
}
void FreeList(sortedLinkList** head){
    sortedLinkList* currentElement = *head;
    sortedLinkList* nextNode;
    while(currentElement!=NULL){
        nextNode = currentElement->nextNode;
        free(currentElement);
        currentElement = nextNode;
    }
    *head = NULL;
}