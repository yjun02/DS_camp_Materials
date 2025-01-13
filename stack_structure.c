#include<stdio.h>

#define MAX_SIZE 100 // 스택의 최대 크기

typedef struct {
    int data[MAX_SIZE]; // 데이터를 저장할 배열
    int top;            // 스택의 맨 위를 가리키는 변수
} Stack;

// 스택 초기화
void initStack(Stack* stack) {
    stack->top = -1; // 초기화 시 top을 -1로 설정
}

// 스택 연산 함수
void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow: Unable to push %d\n", item);
    } else {
        stack->data[++(stack->top)] = item; // top 증가 후 값 추가
        printf("Pushed %d\n", item);
    }
}

void pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow: Unable to pop\n");
    } else {
        int popped = stack->data[(stack->top)--]; // top 값 감소 후 반환
        printf("Popped %d\n", popped);
    }
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty: Nothing to peek\n");
        return -1; // 스택이 비어있을 경우 -1 반환
    } else {
        return stack->data[stack->top]; // top에 해당하는 값 반환
    }
}

int getSize(Stack* stack) {
    return stack->top + 1; // 스택의 크기는 top + 1
}

int isEmpty(Stack* stack) {
    return stack->top == -1; // top이 -1이면 스택이 비어있음
}

int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1; // top이 MAX_SIZE - 1이면 스택이 가득 참
}

int main() {
    Stack stack;
    initStack(&stack); // 스택 초기화

    push(&stack, 10);  // 10 추가
    push(&stack, 20);  // 20 추가
    push(&stack, 30);  // 30 추가

    printf("Top element: %d\n", peek(&stack)); // 스택의 맨 위 확인
    printf("Stack size: %d\n", getSize(&stack)); // 스택 크기 확인

    pop(&stack); // 맨 위 요소 제거
    printf("Top element after pop: %d\n", peek(&stack));
    printf("Stack size after pop: %d\n", getSize(&stack));

    return 0;
}
