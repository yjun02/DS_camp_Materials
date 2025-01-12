/*
해당 링크드리스트는 기본적인 데이터의 삽입,탐색,카운팅, 전체삭제 하는 기능만을 부여한다.
*/
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _node
{
    int data;
    struct _node *next;

} Node;

typedef struct _LinkedList
{
    Node *head;
    Node *tail;
    Node *curr;
    int numOfData;

} List;

void ListInit(List *list);
void ListInsert(List *list, int data); // tail에 데이터를 추가하는 방식
void LinearSearch(List *list);
int IsEmpty(List *list);
int Count(List *list);
void DeleteAll(List *list); // 생성된 데이터(노드)를 모두 삭제, 삭제는 head에서 부터

int main()
{

    List list;
    ListInit(&list);
    IsEmpty(&list);

    printf("Insert Data ...\n\n");
    ListInsert(&list, 10);
    ListInsert(&list, 42);
    ListInsert(&list, 54);
    ListInsert(&list, 66);
    ListInsert(&list, 89);

    printf("Elements : ");
    LinearSearch(&list);
    printf("\n\n");

    printf("Delete Data...\n");
    RemoveAll(&list);
    IsEmpty(&list);
    return 0;
}

void ListInit(List *list)
{
}

void ListInsert(List *list, int data)
{
    // Node* newNode = (Node*)malloc(sizeof(Node));
    // newNode->data = data;
    // newNode->next = NULL;
}

int IsEmpty(List *list)
{
}

int Count(List *list)
{
}

void LinearSearch(List *list)
{
}

void DeleteAll(List *list)
{
}