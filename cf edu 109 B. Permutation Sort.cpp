
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
const int mod2=2147483647; ///2^31-1
const int M=500005;

ll a[M];


int main()
{


    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    ll t,i,j;
    cin>>t;
    while(t--)
    {
        ll n;cin>>n;

        for(i=1;i<=n;i++) cin>>a[i];

        if(is_sorted(a+1,a+n+1)) cout<<0<<endl;
        else if(a[1]==1 or a[n]==n) cout<<1<<endl;
        else if(a[1]==n and a[n]==1) cout<<3<<endl;
        else cout<<2<<endl;



    }

    return 0;

}




