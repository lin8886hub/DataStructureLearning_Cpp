#include<iostream>
#include<string>
#include<list>
using namespace std;

/*
error：
1。 在StudentRecord类中，重载输入运算符>>时，写少了return in;
2.在输出stack和queue时，没有注意到
                        - stack要按照list的逆序输出
                        - queue要按照list的正序输出

warning：
1.main函数中if语句没有使用else if，可能导致逻辑错误
2.在pop操作中，直接使用了record.stuName.empty()来判断栈是否为空，这可能会导致未定义行为

conclusion：
1.用链表实现stack时：
                     - Push操作在链表尾部插入元素       
                     - Pop操作从链表尾部删除元素
                     - print操作按照逆序输出
2.用链表实现queue时：
                     - EnQueue操作在链表尾部插入元素
                     - DeQueue操作从链表头部删除元素
                     - print操作按照正序输出
3.学习了<list>的函数：
                     - push_back(): 在链表尾部插入元素
                     - push_front(): 在链表头部插入元素
                     - front(): 获取链表头部元素
                     - back(): 获取链表尾部元素
                    - pop_back(): 从链表尾部删除元素
                     - pop_front(): 从链表头部删除元素
*/


class StudentRecord
{
public:
    StudentRecord():stuNo(-1){}
    string stuName;
    int stuNo;
    friend istream& operator>>(istream& in,StudentRecord &s)
    {

        string st;
        int stu;
        in >>  st;
        in >>stu;
        s.stuName=st;
        s.stuNo=stu;    //   error：写少了return in;  
    }
    void Print()
    {

        cout << stuName<<" "<<stuNo<<endl;
    }
};

class LinkedList
{
public:
    list<StudentRecord> lst;

    void Print()
    {
        for(auto p=lst.begin();p!=lst.end();p++)
        p->Print();
    }
};

class LinkedStack :public LinkedList
{
public:
    void Push(const StudentRecord& record){
        lst.push_back(record);
    }
    bool Pop(StudentRecord &record)
    {
        if(!lst.empty()){
        record =  lst.back();
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
    void EnQueue(const StudentRecord &record)
    {
        lst.push_back(record);
    }
    bool DeQueue(StudentRecord &record)
    {
        if(!lst.empty())
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
        cin>>s;
        if(s=="Push")
        {
            StudentRecord r;
            cin >>r;
            stack.Push(r);
        }
        if(s=="EnQueue")         //此处应该使用else if
        {
              StudentRecord r;
            cin >> r;
            queue.EnQueue(r);

        }
        if(s=="Pop")
        {
              StudentRecord r;
              stack.Pop(r);
              if(r.stuName.empty())   //此处应该使用stack。Pop的返回值判断是否为空
              cout <<"Stack is empty!"<<endl;
              else
              r.Print();
        }
        if(s=="DeQueue")
        {
            StudentRecord r;
            queue.DeQueue(r);
             if(r.stuName.empty())   //同上
              cout <<"Queue is empty!"<<endl;
              else
              r.Print();
        }
        if(s=="Exit")
        {
            stack.Print();     //错误的使用了链表的顺序输出
            queue.Print();
            break;
        }
        else{
            cout <<"Input error!"<<endl;
        }
    }
    return 0;
 }