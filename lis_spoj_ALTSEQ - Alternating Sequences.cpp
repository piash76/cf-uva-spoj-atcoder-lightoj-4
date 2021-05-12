




///PROBLEM DESCRIPTION:longest alternating increasing subsequence


#include<bits/stdc++.h>

#define speed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);



#define ll long long
#define cy  cout<<"YES"<<endl
#define cn   cout<<"NO"<<endl


using namespace std;




const int mod = 1000000007;


const int mx =5009;///1e6
ll a[mx],dp[mx];


int main()
{


    ll t,i,j,cas=0;
    ll n;cin>>n;
    for(i=0;i<n;i++) cin>>a[i];

    dp[0]=1;

    for(i=1;i<n;i++)
    {
        dp[i]=1;
        for(j=0;j<i;j++)
        {
            if(abs(a[j])<abs(a[i]))
            {
                if( (a[j]<0 and a[i]>0) or (a[j]>0 and a[i]<0) )
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }

            }
        }
    }

    ll lis=0;

    for(i=0;i<n;i++)
    {
        //cout<<dp[i]<<" ";
        lis=max(lis,dp[i]);
    }

    //cout<<endl;

    cout<<lis<<endl;


    return 0;

}





