/*

양방향 연결리스트를 통해서
스택과 큐 기능을 동시에 구현한다.
이를 위해서는 덱(Dequeue)를 이용한다.
Dequeue이란? 앞부분에 대한 삽입과 추출 뒤 부분에 대한 삽입과 추출이 모두 가능한 자료구조이다.

tail에 대한 삭제가 매우 용의하다.
*/
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _node
{
    int data;
    struct _node *left;
    struct _node *right;

} Node;

typedef struct _LinkedList
{
    Node *head;
    Node *tail;
    int NumOfData; // 데이터 삽입시에 해당 값 증가 시키기

} List;

void ListInit(List *list);
void AddFirst(List *list, int data);
int DeleteFirst(List *list);
void AddLast(List *list, int data);
int DeleteLast(List *list);
int IsEmpty(List *list);
int Count(List *list);

int main()
{

    return 0;
}

void ListInit(List *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->NumOfData = 0;
}
void AddFirst(List *list, int data)
{

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if (IsEmpty(list))
    {

        list->head = newNode;
        list->tail = newNode;
    }
    else
    {

        list->head->left = newNode;
        list->head = newNode;
    }
    list->NumOfData++;
}
int DeleteFirst(List *list)
{

    if (IsEmpty(list))
        exit(1);
    int delNode = list->head;
    int data = list->head->data;

    list->head = list->head->right;
    free(delNode);
    delNode = NULL;
    list->NumOfData--;
    return data;
}
void AddLast(List *list, int data)
{

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if (IsEmpty(list))
    {

        list->head = newNode;
        list->tail = newNode;
    }
    else
    {

        list->tail->right = newNode;
        list->tail = newNode;
    }
    list->NumOfData++;
}
int DeleteLast(List *list)
{

    if (IsEmpty(list))
        exit(1);
    Node *delNode = list->tail;
    int data = list->tail->data;

    list->tail = list->tail->left;
    free(delNode);
    delNode = NULL;
    return data;
}
int IsEmpty(List *list)
{

    if (list->head == NULL)
        return TRUE;
    else
        return FALSE;
}
int Count(List *list)
{
    return list->NumOfData;
}