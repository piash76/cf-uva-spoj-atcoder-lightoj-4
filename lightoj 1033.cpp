






///PROBLEM DESCRIPTION:minimum no of char add to make string palindrome


#include<bits/stdc++.h>

#define speed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);



#define ll long long
#define cy  cout<<"YES"<<endl
#define cn   cout<<"NO"<<endl


using namespace std;




const int mod = 1000000007;


const int mx =109;///1e6
char a[mx];
ll dp[mx][mx];

ll solve(ll i,ll j)
{
    if(i>=j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    ll ans=LLONG_MAX;

    if(a[i]==a[j]) ans=min(ans,solve(i+1,j-1)); ///if matches then incre or decre both ->-<-
    else
    {
        ans=min(ans,1+solve(i+1,j));
        ans=min(ans,1+solve(i,j-1));
    }

    return dp[i][j]=ans;
}

int main()
{




    ll t,i,j,cas=0;
    scanf("%lld",&t);

    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%s",a);
        ll n=strlen(a);

        ll ans=solve(0,n-1);

        printf("Case %lld: ",++cas);
        printf("%lld\n",ans);


    }

    return 0;

}




