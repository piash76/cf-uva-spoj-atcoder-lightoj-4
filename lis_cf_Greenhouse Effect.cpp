




///PROBLEM DESCRIPTION:


#include<bits/stdc++.h>

#define speed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);



#define ll long long
#define cy  cout<<"YES"<<endl
#define cn   cout<<"NO"<<endl


using namespace std;




const int mod = 1000000007;


const int mx =5005;///1e6
ll a[mx],I[mx];
double b[mx];
ll dp[mx];

int main()
{


    speed()

    ll t,i,j,cas=0;
    ll n,m;cin>>n>>m;
    for(i=0;i<n;i++) cin>>a[i]>>b[i];

    ll lis=0;


    dp[0]=1;
    for(i=1;i<n;i++)
    {
       dp[i]=1;
       for(j=0;j<i;j++)
       {
           if(a[j]<=a[i])
           {
               dp[i]=max(dp[i],dp[j]+1);
           }
       }
    }

    for(i=0;i<n;i++) lis=max(lis,dp[i]);

    cout<<lis<<endl;

    cout<<n-lis<<endl;




    return 0;

}






