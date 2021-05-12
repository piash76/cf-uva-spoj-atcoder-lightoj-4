





///PROBLEM DESCRIPTION:for all substrings pairs of  a,b find the maximum lcs


#include<bits/stdc++.h>

#define speed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);



#define ll long long
#define cy  cout<<"YES"<<endl
#define cn   cout<<"NO"<<endl


using namespace std;




const int mod = 1000000007;


const int mx =5005;///1e6
ll n,m;
string a,b;

ll dp[mx+5][mx+5];


ll solve(ll i,ll j)
{
    if(i==-1 or j==-1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    ll ans=0;
    if(a[i]==b[j]) ans=max(ans,2+solve(i-1,j-1));
    else
    {
        ans=max(ans,solve(i-1,j)-1);
        ans=max(ans,solve(i,j-1)-1);
    }

    return dp[i][j]=ans;
}

int main()
{


    speed()

    ll t,i,j,cas=0;


    memset(dp,-1,sizeof(dp));

    cin>>n>>m;
    cin>>a>>b;

    ll ans=0;

    for(i=0;i<n;i++)  ///ending at i for first string
    {
        for(j=0;j<m;j++)  ///ending at j for second string
        {
            ans=max(ans,solve(i,j));  ///for substring ending at i for first and j for second string
           // cout<<"SOLVE "<<" i "<<i<<" j "<<j<<" "<<solve(i,j)<<endl;
        }

    }


    cout<<ans<<endl;





    return 0;

}




