#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int front;
    int rear;
    int capacity;
}Queue;

Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if(queue == NULL) {
        printf("khong the cap phat bo nho");
        exit(1);
    }
    queue->array = (int*)malloc(size * sizeof(int));
    if(queue->array == NULL) {
        printf("khong the cap phat bo nho");
        free(queue);
        exit(1);
    }
    queue->capacity = size;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

int main() {
    int size=5;
    Queue* queue = createQueue(size);
    printf("khoi tao thanh cong");
    free(queue);
    return 0;
}