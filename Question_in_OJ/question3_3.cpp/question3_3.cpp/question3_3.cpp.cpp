#include<iostream>
#include<string>
#include<list>
#include<fstream>
using namespace std;
/*
error:
	   1.使用链表尾部作为栈顶时，输出时需要从尾部开始输出，不能直接使用迭代器从头到尾输出。
	    2.在写print函数时，不能用直接输入，要判断是否为空链表，否则会错误。（69行处）

inclusion：
		学习了反向迭代器的使用，可以直接从尾部开始输出，不需要判断是否为空链表了。
        for (auto it = list.lst.rbegin(); it != list.lst.rend(); ++it) {
            it->Print();
		}

        ***注意此处为++it；***

*/


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
    void Print() const
    {
        cout << stuName << " " << stuNo << endl;
    }
};

class LinkedList
{
public:
    list<StudentRecord> lst;

    void Print() const
    {
        for (auto p = lst.begin(); p != lst.end(); p++) {
            p->Print();

        }
           
    }
};

class LinkedStack 
{
public:
    LinkedList list;
    void Push(const StudentRecord& record) {
        list.lst.push_back(record);
    }
    bool Pop(StudentRecord& record)
    {
        if (!list.lst.empty()) {
            record = list.lst.back();
            list.lst.pop_back();
            return true;
        }
        else
            return false;
    }
    void Print() const
    {
	/*	
	如果没有此处的判断，后面的迭代器访问就会出错，因为迭代器不能访问空列表的元素。

    if (list.lst.empty())
            return;
     
	 或者直接使用反向迭代器来输出，这样就不需要判断是否为空了。
     for (auto it = list.lst.rbegin(); it != list.lst.rend(); ++it) {
            it->Print();
     */ 
        auto p = list.lst.end();
        p--;
        for (; p != list.lst.begin(); p--) {
            p->Print();
       
        }
          
        p->Print();
 
    }
};

class LinkedQueue
{
public:
    LinkedStack stack;
    void EnQueue(const StudentRecord& record)
    {
        stack.Push(record);
    }
    bool DeQueue(StudentRecord& record)
    {
        if (!stack.list.lst.empty())
        {
            record = stack.list.lst.front();
            stack.list.lst.pop_front();
            return true;
        }
        else
            return false;
    }
    void Print() const
    {
        stack.list.Print();
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