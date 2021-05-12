




///PROBLEM DESCRIPTION:


#include<bits/stdc++.h>

#define speed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);



#define ll long long
#define cy  cout<<"YES"<<endl
#define cn   cout<<"NO"<<endl


using namespace std;




const int mod = 1000000007;


const int mx =1005;///1e6
char a[mx],b[mx];
ll dp[mx][mx];
ll n,m;

ll solve(ll i,ll j)
{
    if(i>=n or j>=m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    ll ans=-1;
    if(a[i]==b[j]) ans=max(ans,1+solve(i+1,j+1));
    else
    {
        ans=max(ans,solve(i+1,j));
        ans=max(ans,solve(i,j+1));
    }

    return dp[i][j]=ans;
}


int main()
{



    while(1)
    {
        memset(dp,-1,sizeof(dp));

        scanf("%s",a);

       // printf("%s\n",a);

        if(a[0]=='#') break;


        scanf("%s",b);

       //printf("%s\n",b);

        n=strlen(a);
        m=strlen(b);

        ll lcs=solve(0,0);

        ll xn=(n-lcs)*15;
        ll xm=(m-lcs)*30;

        ll ans=xn+xm;

        printf("%lld\n",ans);




    }

    return 0;

}





