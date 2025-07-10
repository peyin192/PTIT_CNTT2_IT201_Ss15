#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* array;
    int front;
    int rear;
    int maxSize;
} Queue;

Queue* createQueue(int size) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->maxSize = size;
    q->front = 0;
    q->rear = -1;
    q->array = (int*)malloc(size * sizeof(int));
    return q;
}

bool isEmpty(Queue* q) {
    return q->rear < q->front;
}
void enQueue(Queue* q, int value) {
    if (q->rear >= q->maxSize - 1) {
        printf("khong the them");
        return;
    }
    q->rear++;
    q->array[q->rear] = value;

}

void printfQueue(Queue* q) {
    printf("queue = {\n");
    printf(" array = [");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d", q->array[i]);
        if (i < q->rear)
            printf(", ");
    }
    printf("];\n");
    printf("front = %d,\n",q->front);
    printf("rear = %d,\n",q->rear);
    printf("maxSize = %d\n",q->maxSize);
    printf("}\n");
}

int main() {
    Queue* q1 = createQueue(5);
    printfQueue(q1);
    if (isEmpty(q1)) {
        printf("true");
    }else {
        printf("false");
    }

    free(q1->array);
    free(q1);
    return 0;

}