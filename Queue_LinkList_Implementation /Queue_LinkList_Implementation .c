#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode {
	int Data;
	struct QueueNode* NextNode;
} QueueNode;

typedef struct Queue {
	QueueNode* Front; //Head
	QueueNode* Back; //Tail
} Queue;
Queue* InitializeQueue();
void Enqueue(Queue* queue, int value);
int Dequeue(Queue* queue);
int Peek(Queue* queue);
void freeQueue(Queue* queue);
int main() {
    Queue* queue = InitializeQueue();
    Enqueue(queue, 5);
    Enqueue(queue, 3);
    Dequeue(queue);
    printf("%d",Peek(queue));
    freeQueue(queue);
    return 0;
}
Queue* InitializeQueue(){
    Queue* myQueue = (Queue*)malloc(sizeof(Queue*));
    if(myQueue == NULL){
        printf("Not enough ram!\n");
        exit(EXIT_FAILURE);
    }
    else{
        myQueue->Front = NULL;
        myQueue->Back = NULL;
    }
}
void Enqueue(Queue* queue, int value){
    QueueNode* queueNode = (QueueNode*)malloc(sizeof(QueueNode*));
    if(queueNode == NULL){
        printf("Not enough ram!\n");
        exit(EXIT_FAILURE);
    }
    queueNode->Data = value;
    queueNode->NextNode = NULL;
    // case 1: not have any node
    if(queue->Front == NULL){
        queue->Front = queueNode;
        queue->Back = queueNode;
    }
    // case 2: have 1 node
    if(queue->Front == queue->Back){
        queue->Back->NextNode = queueNode;
        queue->Back = queueNode;
    }
    // case 3: have more than 2 node
    if(queue->Front != queue->Back){
        queue->Back->NextNode = queueNode;
        queue->Back = queueNode;
    }

}
int Dequeue(Queue* queue){
    //case 1: nothing to delete
    if(queue->Front == NULL){
        printf("Nothing to delete");
        return -1;
    }
    //case 2: 1 to delete
    if(queue->Front == queue->Back){
        int needToReturn = queue->Front->Data;
        free(queue->Front);
        queue->Front = NULL;
        queue->Back = NULL;
        return needToReturn;
        
    }

    //case 3: more than 1 to delete
     if(queue->Front != queue->Back){
        int needToReturn = queue->Front->Data;
        QueueNode* needToDelete = queue->Front;
        queue->Front = queue->Front->NextNode;
        free(needToDelete);
        return needToReturn;
    }
}
int Peek(Queue* queue){
    return queue->Front->Data;
}
void freeQueue(Queue* queue){
    while(queue->Front!=queue->Back){
        free(queue->Front);
        queue->Front = queue->Front->NextNode;
    }
    free(queue->Back);
}