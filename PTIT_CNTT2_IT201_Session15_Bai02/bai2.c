#include <stdio.h>
#include <stdlib.h>

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
    Queue* q = createQueue(5);
    printfQueue(q);

    for (int i = 1; i <= 5; i++) {
        int val;
        printf("nhap gia tri thu %d", i+1);
        scanf("%d", &val);
        enQueue(q, val);
        printfQueue(q);
    }
    enQueue(q, 100);
    free(q->array);
    free(q);
    return 0;

}