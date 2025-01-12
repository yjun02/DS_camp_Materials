#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

int isFull() {
    return top == MAX - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int value) {
    if (isFull()) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = value;
        printf("Pushed %d\n", value);
    }
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

void peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}

int main() {
    push(10);
    push(20);
    peek();
    printf("Popped: %d\n", pop());
    peek();
    return 0;
}
