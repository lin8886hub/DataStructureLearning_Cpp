#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;

struct cardboard
{
    char color;
    string value;
};

int getScore(cardboard p){
    if(p.value=="J"||p.value=="Q"||p.value=="K")
        return 10;
    else if(p.value=="A")
        return 11;
    else if(p.value=="10")
        return 10;
    else
        return stoi(p.value);
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
            string s;
            cin >> s;
            if(s.length()==2)
            {
                cards.push_back({s[0],string(1,s[1])});
            }
            else if(s.length()==3)
                cards.push_back({s[0],s.substr(1)});
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
        cin >> idx;
        cardboard tmp=mycards.pick(idx);
        player1.push_back(tmp);
    }
    for(int i=0;i<5;i++)
    {
        cin >> idx;
        cardboard tmp= mycards.pick(idx);
        player2.push_back(tmp);
    }

    cout << "Player 1 got: ";
    for(int i=0;i<5;i++)
    {
        cout << player1[i].color << player1[i].value;
        i==4 ? cout << '\n':cout << ' ';
    }
    int sum1=0;
    for(int i=0;i<5;i++)
    {
        sum1 += getScore(player1[i]);
    }
    cout << "Player 1 points: " << sum1 << endl;

    cout << "Player 2 got: ";
    for(int i=0;i<5;i++)
    {
        cout << player2[i].color << player2[i].value;
        i==4 ? cout << '\n':cout << ' ';
    }
    int sum2=0;
    for(int i=0;i<5;i++)
    {
        sum2 += getScore(player2[i]);
    }
    cout << "Player 2 points: " << sum2 << endl;

    if(sum1>sum2)
        cout << "Player 1 wins!" << endl;
    else if(sum1<sum2)
        cout << "Player 2 wins!" << endl;
    else
        cout << "Draw!" << endl;
    return 0;
}