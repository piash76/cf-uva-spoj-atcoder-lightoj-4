
///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define ll long long
#define pll  pair<ll,ll>

#define ff    first
#define ss    second

#define  mp  make_pair
#define  pb  push_back




using namespace std;

const ll inf=1e18;
const int mod=1e9+7;
const int M=500005;

ll a[M];


int main()
{


    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t,i,j;
    ll n,k;cin>>n>>k;

    for(i=0;i<n;i++)
    {
        ll x;cin>>x;a[x]++;
    }

    ll ans=0;

    for(i=0;i<k;i++)
    {
        ll idx=0;
        while(a[idx])
        {
            a[idx]--;
            idx++;
        }

        ans+=idx;

    }

    cout<<ans<<endl;




    return 0;

}





