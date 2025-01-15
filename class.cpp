#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Student 클래스 정의
class Student
{
private:
    string name;        // 학생 이름
    int id;             // 학생 ID
    vector<int> scores; // 점수 리스트

public:
    // 생성자: 이름과 ID 초기화
    Student(string studentName, int studentId)
    {
        name = studentName;
        id = studentId;
    }

    // 점수 추가 함수
    void addScore(int score)
    {
        if (score >= 0 && score <= 100)
        {
            scores.push_back(score);
        }
        else
        {
            cout << "Invalid score! Please enter a value between 0 and 100." << endl;
        }
    }

    // 평균 점수 계산 함수
    double calculateAverage()
    {
        if (scores.empty())
            return 0.0;

        int total = 0;
        for (int score : scores)
        {
            total += score;
        }
        return static_cast<double>(total) / scores.size();
    }

    // 학생 정보 출력 함수
    void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Scores: ";
        for (int score : scores)
        {
            cout << score << " ";
        }
        cout << endl;
        cout << "Average Score: " << calculateAverage() << endl;
    }
};

int main()
{
    // Student 객체 생성
    Student student1("Alice", 101);
    Student student2("Bob", 102);

    // 점수 추가
    student1.addScore(85);
    student1.addScore(90);
    student1.addScore(78);

    student2.addScore(88);
    student2.addScore(92);
    student2.addScore(76);

    // 학생 정보 출력
    cout << "Student 1 Info:" << endl;
    student1.displayInfo();
    cout << endl;

    cout << "Student 2 Info:" << endl;
    student2.displayInfo();

    return 0;
}
