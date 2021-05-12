

///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define ll long long
#define pll  pair<ll,ll>

#define ff    first
#define ss    second

#define  mp  make_pair
#define  pb  push_back

#define cy  cout<<"YES"<<endl
#define cn   cout<<"NO"<<endl


using namespace std;

const ll inf=1e18;
const int mod=1e9+7;
const int M=500005;

ll a[M],b[M],c[M],dp[M];


int main()
{


    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    ll t,i,j;
    cin>>t;
    while(t--)
    {
        ll n;cin>>n;

        for(i=0;i<n;i++) cin>>c[i];

        for(i=0;i<n;i++) cin>>a[i];
        for(i=0;i<n;i++) cin>>b[i];


        for(i=0;i<=n+5;i++) dp[i]=0;


        dp[0]=0; ///meaning the longest chain till ith

        for(i=1;i<n;i++)
        {
            if(abs(a[i]-b[i])==0)
            {
                dp[i]=max(dp[i],abs(a[i]-b[i])+1+c[i]);

            }
            else
            {
               dp[i]=max(dp[i],abs(a[i]-b[i])+1+c[i]);

               ll dif=abs(a[i]-b[i])-1;

               dp[i]=max(dp[i],dp[i-1]-dif+c[i]);
            }
        }

        ll ans=-1;
        for(i=0;i<n;i++) ans=max(ans,dp[i]);

        cout<<ans<<"\n";


    }

    return 0;

}





