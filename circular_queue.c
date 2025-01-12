#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

int isFull() {
    return (rear + 1) % MAX == front;
}

int isEmpty() {
    return front == -1;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow\n");
    } else {
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }
        queue[rear] = value;
        printf("Enqueued %d\n", value);
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        int value = queue[front];
        if (front == rear) {
            front = rear = -1;  // Reset queue if last element is removed
        } else {
            front = (front + 1) % MAX;
        }
        return value;
    }
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    printf("Dequeued: %d\n", dequeue());
    display();
    enqueue(40);
    enqueue(50);
    enqueue(60); // This will cause overflow
    display();
    printf("Dequeued: %d\n", dequeue());
    enqueue(70); // Adding element after circular movement
    display();
    return 0;
}
