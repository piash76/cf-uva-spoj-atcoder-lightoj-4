//hierarchical inheritence

#include<bits/stdc++.h>
#define ll long long
#define see_you return 0
#define godspeed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;


class marks
{
public:

    int mrk,id;
    string name;
    void getinfo()
    {
        cout<<"ENTER STUDENT NAME: "<<endl;
        cin>>name;
        cout<<"ENTER ID: "<<endl;
        cin>>id;
    }
    void showinfo()
    {
        cout<<"NAME :"<<name<<endl;
        cout<<"ID :"<<id<<endl;
        cout<<"TOTAL MARKS: "<<mrk<<" AVERAGE MARKS: "<<mrk/3<<endl;
    }
};

class physics:public marks
{
public:
    int p;
    void getphy()
    {
        cout<<"ENTER PHYSICS NO: "<<endl;
        cin>>p;
    }
};

class chemistry:public marks
{
public:
    int c;
    void getchem()
    {
        cout<<"ENTER CHEMISTRY NO: "<<endl;
        cin>>c;
    }
};

class math:public marks
{
public:
    int m;
    void getmath()
    {
        cout<<"ENTER MATH NO: "<<endl;
        cin>>m;
    }
};


int main()
{
    int n,i;
    cout<<"ENTER NUMBER OF STUDENTS: "<<endl;
    marks mk[n];
    physics ph[n];
    chemistry ch[n];
    math mt[n];
    for(i=0;i<n;i++)
    {
        mk[i].getinfo();
        ph[i].getphy();
        ch[i].getchem();
        mt[i].getmath();
        mk[i].mrk=ph[i].p+ch[i].c+mt[i].m;
    }
    for(i=0;i<n;i++)
    {
         mk[i].showinfo();
    }
    see_you;
}

