#include <iostream>
using namespace std;

// Node 구조체 정의
struct Node
{
    int data;   // 데이터를 저장
    Node *next; // 다음 노드를 가리키는 포인터
};

// 연결 리스트 관리 구조체
struct LinkedList
{
    Node *head; // 첫 번째 노드를 가리키는 포인터

    // 생성자: 리스트 초기화
    LinkedList() : head(nullptr) {}

    // 노드 추가 (끝에 추가)
    void append(int value)
    {
        Node *newNode = new Node{value, nullptr}; // 새로운 노드 생성
        if (head == nullptr)
        { // 리스트가 비어있는 경우
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next; // 마지막 노드로 이동
            }
            temp->next = newNode; // 새로운 노드를 연결
        }
        cout << value << " appended to the list.\n";
    }

    // 노드 삭제 (특정 값 삭제)
    void remove(int value)
    {
        if (head == nullptr)
        {
            cout << "List is empty. Nothing to remove.\n";
            return;
        }

        // 첫 번째 노드가 삭제 대상인 경우
        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << value << " removed from the list.\n";
            return;
        }

        // 삭제 대상이 리스트 중간 또는 끝에 있는 경우
        Node *temp = head;
        while (temp->next != nullptr && temp->next->data != value)
        {
            temp = temp->next;
        }

        if (temp->next == nullptr)
        {
            cout << value << " not found in the list.\n";
        }
        else
        {
            Node *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            cout << value << " removed from the list.\n";
        }
    }

    // 리스트 출력
    void display() const
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        Node *temp = head;
        cout << "List elements: ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // 소멸자: 메모리 해제
    ~LinkedList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        cout << "List destroyed.\n";
    }
};

int main()
{
    LinkedList list;

    // 노드 추가
    list.append(10);
    list.append(20);
    list.append(30);

    // 리스트 출력
    list.display();

    // 노드 삭제
    list.remove(20);
    list.display();

    // 없는 노드 삭제 시도
    list.remove(40);

    return 0;
}
