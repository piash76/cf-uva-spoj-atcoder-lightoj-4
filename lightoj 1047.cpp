#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[1000][1000],dp[1000][1000];
ll n;
ll mincost(ll i,ll j)
{
    if(i==n) return a[i][j];
    if(dp[i][j]!=-1) return dp[i][j];

    ll j1,j2,x,y;
    if(j==1)
    {
        j1=2;
        j2=3;
    }
    else if(j==2)
    {
        j1=1;
        j2=3;
    }
    else
    {
        j1=1;
        j2=2;
    }
    x=a[i][j]+mincost(i+1,j1);
    y=a[i][j]+mincost(i+1,j2);
    dp[i][j]=min(x,y);
    return dp[i][j];

}


int main()
{
    ll i,j,t,ts;
    scanf("%lld",&t);
    getchar();
    for(ts=1;ts<=t;ts++)
    {
        scanf("%lld",&n);
        memset(dp,-1,sizeof(dp));

        for(i=1;i<=n;i++)
        {
           for(j=1;j<=3;j++)
           {
              scanf("%lld",&a[i][j]);
           }
        }

        ll w=mincost(1,1);
        ll x=mincost(1,2);
        ll y=mincost(1,3);

        ll ans = min(w,min(x,y));

        printf("Case %lld: %lld\n",ts,ans);


    }

}

