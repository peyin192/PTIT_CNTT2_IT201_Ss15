#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
}Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}
int isFull(Queue* q){
    return q->rear == MAX - 1;
}
void enqueue(Queue* q,int value) {
    if (isFull(q)) {
        printf("Queue day");
        return;
    }
    q->rear++;
    q->data[q->rear] = value;
}
int isEmpty(Queue* q){
    return q->front > q->rear;
}
int frontQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue khong co phan tu");
        return -1;
    }
    return q->data[q->front];
}
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue khong co phan tu");
        return -1;
    }
    int value = q->data[q->front];
    q->front++;
    return value;
}
int main() {
    Queue queueOld;
    Queue queueNormal;
    initQueue(&queueNormal);
    initQueue(&queueOld);
    int n;
    printf("Moi nhap so luong benh nhan : ");
    scanf("%d",&n);
    for (int i = 0; i < n;i++) {
        int value;
        printf("nhap tuoi cua benh nhan so %d : ", i+1);
        scanf("%d",&value);
        printf("\n");
        if (value >= 60) {
            enqueue(&queueOld,value);
        }else if (value <= 60) {
            enqueue(&queueNormal,value);
        }
    }
    printf("Thu tu phuc vu : \n");
    int i=0;
    while (!isEmpty(&queueOld) || !isEmpty(&queueNormal)) {
        i++;
        if (!isEmpty(&queueOld)) {
            int ageOld = dequeue(&queueOld);
            printf("Benh nhan so %d : %d \n",i,ageOld);
        }else if (!isEmpty(&queueNormal)) {
            int ageNormal = dequeue(&queueNormal);
            printf("Benh nhan so %d : %d \n",i,ageNormal);
        }
    }

}