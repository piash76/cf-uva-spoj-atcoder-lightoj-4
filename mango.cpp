#include<bits/stdc++.h>
#define ll long long
#define see_you return 0
#define godspeed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

class fruit
{
protected:
    static int t;
    public:
    void showtotalfruit()
    {
        cout<<"TOTAL FRUIT: "<<t<<endl;
    }
};

class apple:public fruit
{
public:
    int a;
    void countapple()
    {
        cout<<"NO OF APPLES:"<<endl;
        cin>>a;
        t+=a;

    }
};

class mango:public fruit
{
public:
    int m;
    void countmango()
    {
        cout<<"NO OF MANGOES:"<<endl;
        cin>>m;
        t+=m;
    }
};
int fruit::t;
int main()
{
    godspeed()
    apple a;
    mango b;
    a.countapple();
    b.countmango();
    a.showtotalfruit();
    see_you;
}
