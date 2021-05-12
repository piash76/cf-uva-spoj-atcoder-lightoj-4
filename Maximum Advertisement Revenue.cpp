

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

ll a[M],c[M];


int main()
{


    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    ll t,i,j;
    ll n;cin>>n;

    for(i=0;i<n;i++) cin>>a[i];
    for(i=0;i<n;i++) cin>>c[i];

    ll s=0;
    sort(a,a+n);sort(c,c+n);

    for(i=0;i<n;i++) s+=a[i]*c[i];

    cout<<s<<endl;



    return 0;

}




