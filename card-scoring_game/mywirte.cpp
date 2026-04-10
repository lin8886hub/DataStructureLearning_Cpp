#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
/*
error: 
1. cardboard类里面不能用char储存值（因为10占了两个字符，应该用string）
2. read函数的实现有误
            - 在读取W8这种有字母和数字时，使用string来存储，
              然后用scanf读取string里面的内容比较容易实现
3.读取内容时，建议重载输入运算符，让main函数更简洁

*/
struct cardboard
{
    char color;
    char value;   //应该使用string
};
 int getScore(cardboard p){
    if(p.value=='J'||p.value=='Q'||p.value=='K')
    return 10;
    else if(p.value=='A')
    return 11;
    else
    return p.value-'0';
    }
class Card
{
    public:
    vector<cardboard> cards;
    int number=52;

    void read(istream& cin)
    {
        for(int i=0;i<number;i++)
        {
            char temp[3];
            cin.read(temp,3);
            if(temp[2]!=' '&&temp[2]!='\n')break;
            cards.push_back({temp[0],temp[1]});

        }
    }
    cardboard& pick(int num)
    {
        return cards[num];
    }

};

int main()
{
    Card mycards;
    mycards.read(cin);
    vector<cardboard> player1,player2;
    int idx;
    for(int i=0;i<5;i++)
    {
        cin >>idx;
        cardboard tmp=mycards.pick(idx);
        player1.push_back(tmp);
    }
     for(int i=0;i<5;i++)
    {
        cin >>idx;
        cardboard tmp= mycards.pick(idx);
        player2.push_back(tmp);
    }


    cout << "Player 1 got: ";
    for(int i=0;i<5;i++)
    {
        cout << player1[i].color << player1[i].value;
        i==4 ? cout <<'\n':cout <<' ';
    }
    int sum1=0;
    for(int i=0;i<5;i++)
    {
        sum1 += getScore(player1[i]);
    }
    cout << "Player 1 points: " <<sum1 <<endl;



    cout << "Player 2 got: ";
    for(int i=0;i<5;i++)
    {
        cout << player2[i].color << player2[i].value;
        i==4 ? cout <<'\n':cout <<' ';
    }
    int sum2=0;
    for(int i=0;i<5;i++)
    {
        sum2 += getScore(player2[i]);
    }
    cout << "Player 2 points: " <<sum2 <<endl;


    if(sum1>sum2)
    cout << "Player 1 wins!"<<endl;
    else if (sum1<sum2)
    cout << "Player 2 wins!"<<endl;
    else
    cout <<"Draw!"<<endl;
        return 0;
}