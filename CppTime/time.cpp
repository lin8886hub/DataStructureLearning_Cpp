#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class CTime
{

public:
    CTime(int h,int m,int s)
    :hour(h),minute(m),second(s)
    {};
    CTime(): CTime(0, 0, 0)
    {
    }
    ~CTime()=default;
    friend istream& operator>>(istream& in,CTime& t)
    {
        /*
        //清空输入缓冲区，防止之前输入的内容干扰到当前输入

        in.ignore();

		不能这样，ignore会把输入流中的第一个字符丢掉，如果用户输入的时间格式是正确的，那么第一个字符就是数字，丢掉了就无法正确解析了
        */
        int ch;
        if((ch=getchar())!='\n')
			ungetc(ch, stdin); //不存在从std::istream到FILE*的转换函数，所以只能使用stdin,无法使用in;
        string str;

		//读取整行输入，允许用户输入包含空格的时间格式 !!!getline在string里面定义
        getline(in,str);
		//因为后面sscanf需要用到空格分隔，所以把非数字的字符都替换成空格，亲测
        for (char& ch : str) {
            if (!isdigit(ch)) {
                ch = ' ';
            }
        }
        int h,m,s;
        int Isright=1;
        if(sscanf(str.c_str(),"%d %d %d",&h,&m,&s)!=3)
        {
            fprintf(stderr,"输入错误:%s",str.c_str());
            Isright=0;
            
        };
        if (Isright)
        {
            h >= 24 || h < 0 ? (fprintf(stderr, "小时输入错误 %d\n", h),Isright=0 ): Isright==1; //? : 优先级比逗号 , 高,加括号
            m >= 60 || m < 0 ? (fprintf(stderr, "分钟输入错误 %d\n", m), Isright = 0) : Isright==1;
            s >= 60 || s < 0 ? (fprintf(stderr, "秒输入错误 %d\n", s), Isright = 0 ): Isright==1;
        }

        if(Isright)
        {
            t.hour=h;
            t.minute=m;
            t.second=s;
        }
        return in;
    }
    friend ostream& operator<< (ostream& out , CTime& t)
    {
        out << t.hour<<":"<<t.minute<<":"<<t.second<<endl;
        return out;
    }
private:
    int  hour, minute, second;

};
int main()
{
    CTime a;
    CTime b(1,2,3);
    cout <<"a: "<<a<<"b: "<<b;
    cin >>a;
    cout <<"转换后a: "<<a;
    return 0;
}