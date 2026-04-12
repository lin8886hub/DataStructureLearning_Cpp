#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

// (1) StudentRecord 类
class StudentRecord {
public:
    string stuName;
    int stuNo;
    StudentRecord() : stuNo(-1) {}
    void Print() const {
        cout << stuName << " " << stuNo << endl;
    }
};

istream& operator>>(istream& in, StudentRecord& s) {
    in >> s.stuName >> s.stuNo;
    return in;
}

// (2) LinkedList 类 - 严格遵守私有成员要求
class LinkedList {
private:
    list<StudentRecord> lst; // 必须是私有

public:
    void InsertHead(const StudentRecord& record) { lst.push_front(record); }
    void RemoveHead() { if (!lst.empty()) lst.pop_front(); }
    void InsertTail(const StudentRecord& record) { lst.push_back(record); }
    void RemoveTail() { if (!lst.empty()) lst.pop_back(); }

    // 题目要求的 Pop/DeQueue 需要返回对象，所以我们稍微包装一下
    bool getFront(StudentRecord& record) {
        if (lst.empty()) return false;
        record = lst.front();
        return true;
    }
    bool getBack(StudentRecord& record) {
        if (lst.empty()) return false;
        record = lst.back();
        return true;
    }

    void PrintAll() const {
        for (const auto& item : lst) item.Print();
    }
    bool IsEmpty() const { return lst.empty(); }
};

// (3) LinkedStack 类 - 组合实现
class LinkedStack {
private:
    LinkedList myL;
public:
    // 为了让 PrintAll() 直接输出就是栈顶到栈底，我们必须用 InsertHead
    void Push(const StudentRecord& record) {
        myL.InsertHead(record);
    }
    bool Pop(StudentRecord& record) {
        if (myL.getFront(record)) {
            myL.RemoveHead();
            return true;
        }
        return false;
    }
    void Print() const { myL.PrintAll(); }
};

// (4) LinkedQueue 类 - 组合实现
class LinkedQueue {
private:
    LinkedList myL;
public:
    void EnQueue(const StudentRecord& record) {
        myL.InsertTail(record);
    }
    bool DeQueue(StudentRecord& record) {
        if (myL.getFront(record)) {
            myL.RemoveHead();
            return true;
        }
        return false;
    }
    void Print() const { myL.PrintAll(); }
};

int main() {
    LinkedStack stack;
    LinkedQueue queue;
    string op;

    while (cin >> op) {
        if (op == "Exit") {
            stack.Print();
            queue.Print();
            break;
        }
        else if (op == "Push") {
            StudentRecord r; cin >> r;
            stack.Push(r);
        }
        else if (op == "EnQueue") {
            StudentRecord r; cin >> r;
            queue.EnQueue(r);
        }
        else if (op == "Pop") {
            StudentRecord r;
            if (stack.Pop(r)) r.Print();
            else cout << "Stack is empty!" << endl;
        }
        else if (op == "DeQueue") {
            StudentRecord r;
            if (queue.DeQueue(r)) r.Print();
            else cout << "Queue is empty!" << endl;
        }
        else {
            cout << "Input error!" << endl;
        }
    }
    return 0;
}