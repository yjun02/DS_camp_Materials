#include <stdio.h>
#include <stdlib.h>
#define MAX 5

// Stack 구조체 정의
typedef struct {
    int data[MAX];
    int top;
} Stack;

// Push 함수
void push(Stack *stack, int value) {
    if (stack->top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack->data[++stack->top] = value;
        printf("%d pushed to stack\n", value);
    }
}

// Pop 함수
void pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d popped from stack\n", stack->data[stack->top--]);
    }
}

// Display 함수
void display(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = stack->top; i >= 0; i--) {
            printf("%d ", stack->data[i]);
        }
        printf("\n");
    }
}

int main() {
    Stack stack = {.top = -1}; // Stack 초기화

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    display(&stack);
    pop(&stack);
    display(&stack);

    return 0;
}
