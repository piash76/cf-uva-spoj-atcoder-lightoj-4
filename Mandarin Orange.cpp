

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

ll a[M],dp[M];


int main()
{


    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    ll t,i,j;
    ll n;cin>>n;
    for(i=0;i<n;i++) cin>>a[i];

    dp[0]=a[0];

    for(i=1;i<n;i++)
    {
        ll val=a[i];
        ll cnt=1;
        ll idx=i-1;
        while(val<=a[idx] and idx>=0)
        {
            idx--;
            cnt++;
        }

        idx=i+1;
        while(val<=a[idx] and idx<n)
        {
            idx++;
            cnt++;
        }

        dp[i]=val*cnt;
    }

    ll s=-1;
    for(i=0;i<n;i++) s=max(s,dp[i]);

    cout<<s<<endl;


    return 0;

}





