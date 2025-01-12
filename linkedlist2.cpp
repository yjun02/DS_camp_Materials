#include <iostream>
using namespace std;

// 노드 구조체 정의
struct Node
{
    int data;   // 데이터 저장
    Node *next; // 다음 노드를 가리키는 포인터
};

// 연결 리스트 클래스
class LinkedList
{
private:
    Node *head; // 리스트의 첫 번째 노드를 가리키는 포인터

public:
    LinkedList() : head(nullptr) {} // 생성자: 초기에는 비어 있음

    // 노드 삽입 (리스트의 끝에 추가)
    void append(int value)
    {
        Node *newNode = new Node{value, nullptr};
        if (head == nullptr)
        {
            head = newNode; // 리스트가 비어 있으면 새로운 노드를 head로 설정
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next; // 마지막 노드까지 이동
            }
            temp->next = newNode; // 마지막 노드에 새 노드 연결
        }
        cout << value << " appended to the list.\n";
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

    // 소멸자: 동적 메모리 해제
    ~LinkedList()
    {
        Node *temp;
        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    LinkedList list;

    // 데이터 삽입
    list.append(10);
    list.append(20);
    list.append(30);

    // 리스트 출력
    cout << "Linked List: ";
    list.display();

    return 0;
}
