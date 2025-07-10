#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100
#define NAME_MAX 30

typedef struct {
    char name[MAX][NAME_MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q -> front = 0;
    q -> rear = -1;
}

bool isEmpty(Queue* q) {
    return q -> rear < q -> front;
}

bool isFull(Queue* q) {
    return q->rear >= MAX - 1;
}

void enQueue(Queue* q, char* name) {
    if (isFull(q)) {
        printf("khong the them");
        return;
    }
    q->rear++;
    strncpy(q->name[q->rear], name, NAME_MAX - 1);
    q->name[q->rear][NAME_MAX - 1] = '\0';//ket thuoc chuoi
    printf("da them %s thanh cong vao hang doi\n",name);
}

void deQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("khong the them");
        return;
    }
    printf("phuc vu khach: %s\n",q->name[q->front]);
    q->front++;
}

void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("khong the them");
        return;
    }
    printf("Danh sach khach dang cho\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%s ", q->name[i]);
    }
}

int main () {
    Queue q;
    initQueue(&q);
    int choice;
    char name[NAME_MAX];

    do {
        printf("\n---MENU---\n");
        printf("1. them khach hang\n");
        printf("2. phuc vu khach khach\n");
        printf("3. hien thi danh sach khach khach\n");
        printf("4. thoat\n");
        printf("moi ban chon");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                if (isFull(&q)) {
                    printf("khong the them");
                }else {
                    printf("nhap ten khach hàng");
                    fgets(name, sizeof(name), stdin);
                    name[strcspn(name, "\n")] = '\0';
                    enQueue(&q, name);
                }
                break;
                case 2:
                deQueue(&q);
                break;
                case 3:
                displayQueue(&q);
                break;
            case 4:
                printf("thoat chuong trinh");
                break;
                default:
                printf("lua chon khong hop le");
        }
    }while (choice != 4);
    return 0;
}