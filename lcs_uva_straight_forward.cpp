




///PROBLEM DESCRIPTION:


#include<bits/stdc++.h>

#define speed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);



#define ll long long
#define cy  cout<<"YES"<<endl
#define cn   cout<<"NO"<<endl


using namespace std;




const int mod = 1000000007;


const int maxn =1005;///1e6
char a[maxn],b[maxn];

int dp[maxn][maxn];
int n,m;

int solve(int i,int j)
{
    if(i>=n or j>=m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int ans=INT_MIN;

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

    ll t,i,j,cas=0;

    while(gets(a))
    {
        gets(b);

        n=strlen(a);
        m=strlen(b);

        memset(dp,-1,sizeof(dp));

        int ans=solve(0,0);

        printf("%d\n",ans);



    }

    return 0;

}





