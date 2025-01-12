/*
�ش� ��ũ�帮��Ʈ�� �⺻���� ��ɰ� ���Ҿ�, ������������ �����͸� �����ϴ� ��ɰ� Ư�� ��带 �����ϴ� ����� �߰��Ѵ�.
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
    Node *prev;
    int NumOfData; // ������ ���Խÿ� �ش� �� ���� ��Ű��

} List;

void ListInit(List *list);
void ListInsert(List *list, int data);
void ListInsertAscending(List *list, int data); // �����߰��� �Լ�1 : �����͸� ������������ �����Ѵ�.
void LinearSearch(List *list);
int Count(List *list);
int Delete(List *list, int data); // ���� �߰��� �Լ�3: Ư����带 �����Ѵ�.
void DeleteAll(List *list);

int main()
{

    List list;
    ListInit(&list);
    IsEmpty(&list);

    printf("�������� ������ ���� ...\n\n");
    ListInsertAscending(&list, 10);
    ListInsertAscending(&list, 2);
    ListInsertAscending(&list, 8);
    ListInsertAscending(&list, 3);
    ListInsertAscending(&list, 20);
    ListInsertAscending(&list, 14);

    printf("������ ��� : ");
    LinearSearch(&list);
    printf("\n\n");

    printf("������ ������ ���� ����\n\n");
    printf("%d��(��) �����Ǿ����ϴ�!\n", Delete(&list, 3));
    printf("\n������ ������ ��� : ");
    LinearSearch(&list);

    return 0;
}

void ListInit(List *list)
{
}

void ListInsert(List *list, int data)
{
}

void ListInsertAscending(List *list, int data)
{
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

int Delete(List *list, int data)
{
}

void DeleteAll(List *list)
{
}