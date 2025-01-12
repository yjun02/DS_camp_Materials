#include <stdio.h>
#include <stdlib.h>
#define MAX 5

// Queue 구조체 정의
typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

// Enqueue 함수
void enqueue(Queue *queue, int value) {
    if (queue->rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (queue->front == -1) queue->front = 0; // 첫 삽입 시 초기화
        queue->data[++queue->rear] = value;
        printf("%d enqueued to queue\n", value);
    }
}

// Dequeue 함수
void dequeue(Queue *queue) {
    if (queue->front == -1 || queue->front > queue->rear) {
        printf("Queue Underflow\n");
    } else {
        printf("%d dequeued from queue\n", queue->data[queue->front++]);
    }
}

// Display 함수
void display(Queue *queue) {
    if (queue->front == -1 || queue->front > queue->rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->data[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue queue = {.front = -1, .rear = -1}; // Queue 초기화

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    display(&queue);
    dequeue(&queue);
    display(&queue);

    return 0;
}
