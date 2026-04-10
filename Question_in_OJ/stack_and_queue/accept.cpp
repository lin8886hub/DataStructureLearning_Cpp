#include<iostream>
#include<string>
#include<list>
using namespace std;

class StudentRecord
{
public:
    StudentRecord() :stuNo(-1) {}
    string stuName;
    int stuNo;
    friend istream& operator>>(istream& in, StudentRecord& s)
    {
        string st;
        int stu;
        in >> st;
        in >> stu;
        s.stuName = st;
        s.stuNo = stu;
        return in;
    }
    void Print()
    {
        cout << stuName << " " << stuNo << endl;
    }
};

class LinkedList
{
public:
    list<StudentRecord> lst;

    void Print()
    {
        for (auto p = lst.begin(); p != lst.end(); p++)
            p->Print();
    }
};

class LinkedStack :public LinkedList
{
public:
    void Push(const StudentRecord& record) {
        lst.push_back(record);
    }
    bool Pop(StudentRecord& record)
    {
        if (!lst.empty()) {
            record = lst.back();
            lst.pop_back();
            return true;
        }
        else
            return false;
    }
};

class LinkedQueue : public LinkedList
{
public:
    void EnQueue(const StudentRecord& record)
    {
        lst.push_back(record);
    }
    bool DeQueue(StudentRecord& record)
    {
        if (!lst.empty())
        {
            record = lst.front();
            lst.pop_front();
            return true;
        }
        else
            return false;
    }
};


int main()
{
    LinkedQueue queue;
    LinkedStack stack;
    string s;

    while (1)
    {
        cin >> s;
        if (s == "Push")
        {
            StudentRecord r;
            cin >> r;
            stack.Push(r);
        }
        else if (s == "EnQueue")
        {
            StudentRecord r;
            cin >> r;
            queue.EnQueue(r);

        }
        else if (s == "Pop")
        {
            StudentRecord r;
            bool flag = stack.Pop(r);
            if (!flag)
                cout << "Stack is empty!" << endl;
            else
                r.Print();
        }
        else if (s == "DeQueue")        
        {
            StudentRecord r;
            bool flag = queue.DeQueue(r);
            if (!flag)
                cout << "Queue is empty!" << endl;
            else
                r.Print();
        }
        else if (s == "Exit")
        {
            stack.Print();
            queue.Print();
            break;
        }
        else {                       
            cout << "Input error!" << endl;
        }
    }
    return 0;
}