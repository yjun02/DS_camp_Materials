#include <stdio.h>
#define MAX_SIZE 100 // 큐의 최대 크기

typedef struct {
    int data[MAX_SIZE]; // 데이터를 저장할 배열
    int front;          // 큐의 앞부분을 가리키는 인덱스
    int rear;           // 큐의 뒷부분을 가리키는 인덱스
} Queue;

void initQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

void enqueue(Queue* queue, int item) {
    if (queue->rear == MAX_SIZE - 1) {
        printf("Queue Overflow: Unable to enqueue %d\n", item);
    } else {
        if (queue->front == -1) queue->front = 0;
        queue->data[++(queue->rear)] = item;
        printf("Enqueued %d\n", item);
    }
}

void dequeue(Queue* queue) {
    if (queue->front == -1 || queue->front > queue->rear) {
        printf("Queue Underflow: Unable to dequeue\n");
    } else {
        printf("Dequeued %d\n", queue->data[queue->front++]);
        if (queue->front > queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        }
    }
}

int peek(Queue* queue) {
    if (queue->front == -1 || queue->front > queue->rear) {
        printf("Queue is empty: Nothing to peek\n");
        return -1;
    }
    return queue->data[queue->front];
}

int getSize(Queue* queue) {
    if (queue->front == -1 || queue->front > queue->rear) return 0;
    return queue->rear - queue->front + 1;
}

int isEmpty(Queue* queue) {
    return queue->front == -1 || queue->front > queue->rear;
}

int isFull(Queue* queue) {
    return queue->rear == MAX_SIZE - 1;
}

int main() {
    Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Front element: %d\n", peek(&queue));
    printf("Queue size: %d\n", getSize(&queue));

    dequeue(&queue);
    printf("Front element after dequeue: %d\n", peek(&queue));
    printf("Queue size after dequeue: %d\n", getSize(&queue));

    return 0;
}
