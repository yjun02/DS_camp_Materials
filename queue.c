#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

int isFull() {
    return rear == MAX - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) front = 0;
        queue[++rear] = value;
        printf("Enqueued %d\n", value);
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        return queue[front++];
    }
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    peek();
    printf("Dequeued: %d\n", dequeue());
    peek();
    return 0;
}
