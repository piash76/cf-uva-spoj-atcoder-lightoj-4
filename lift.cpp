#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,n,i,t;
    cin>>t;
    for(i=1;i<=t;i++)
    {
       cin>>a>>b;
       if(a<=b)n=b*4+19;
       else if(a>b) n=(2*a-b)*4+19;

       printf("Case %d: %d",i,n);

    }
}
