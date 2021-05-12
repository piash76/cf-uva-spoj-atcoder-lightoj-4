#include<bits/stdc++.h>
#define ll long long
using namespace std;

double ar[1000000];

int main()
{
    ll t,n,b,i,j;
     double ans;
    for(i=1;i<=1000000;i++)
    {
        ar[i]=ar[i-1]+log(i);
    }
    cin>>t;
    for(j=1;j<=t;j++)
    {
        cin>>n>>b;
        ans=ar[n];
        ans/=log(b);
        ans+=1.0;
        ans=floor(ans);
        printf("Case %lld: %.0lf\n",j,ans);

    }
}

