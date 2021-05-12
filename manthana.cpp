#include<bits/stdc++.h>
using namespace std;

long long xon(long long a,long long b,long long n)
{
    if(n==0)
    {
        return a;

    }
    else if(n==1)
    {
        return b;

    }
    else
    {
        return xon(a,b,n-1)^xon(a,b,n-2);
    }
}

int main()
{
    long long a,b,n,t,s;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>n;
        s=xon(a,b,n);
        cout<<s<<endl;

    }
}
