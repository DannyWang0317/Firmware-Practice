#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

void initQueue(Queue* q){
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

bool empty(Queue* q){
    return (q->front == NULL);
}

void push(Queue* q, int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if(empty(q)){
        q->front = newNode;
        q->rear = newNode;
    }
    else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

void pop(Queue* q){
    if(empty(q)){
        printf("No element\n");
        return;
    }
    Node* temp = q->front;
    q->front = q->front->next;
    if(q->front == NULL){
        q->rear = NULL;
    }
    q->size--;
    free(temp);
}

int back(Queue* q){
    if(empty(q)){
        printf("No element\n");
        return -1;
    }

    return q->rear->data;
}

int front(Queue* q){
    if(empty(q)){
        printf("No element\n");
    }
    return q->front->data;
}

int main() {
    Queue q;
    initQueue(&q);

    push(&q, 10);
    push(&q, 20);
    push(&q, 30);

    printf("Current Front: %d\n", front(&q)); // 應為 10
    printf("Current Back: %d\n", back(&q));   // 應為 30

    pop(&q); // 移除 10

    printf("Current Front: %d\n", front(&q)); // 應為 20

    pop(&q); // 移除 20
    pop(&q); // 移除 30 (變空了)
    
    if (empty(&q)) {
        printf("Queue is empty now.\n");
    }

    return 0;
}