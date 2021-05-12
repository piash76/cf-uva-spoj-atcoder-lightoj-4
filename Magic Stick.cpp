#include<bits/stdc++.h>
#define ll long long
#define return 0 bye
#define godspeed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    godspeed()
    ll x,y,b,a,i,j,t,k,l;

    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        if(x==y || x>y)
        {
            cout<<"YES"<<endl;

        }
        else if(x==2 && y<=3)
        {
            cout<<"YES"<<endl;
        }
        else if(x==3 && y<3)
        {
            cout<<"YES"<<endl;
        }
        else if(x>=4)
        {
             cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }


    }
}
