
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




int main()
{


    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t,i,j;

    cin>>t;
    while(t--)
    {
        ll k;cin>>k;


        if(k==100) cout<<1<<endl;
        else if((100-k)%k==0) cout<<((100-k)/k )+1<<endl;
        else
        {
            ll x=k,y=100-k;

            while(1)
            {
                if(__gcd(x,y)==1) break;
                ll g=__gcd(x,y);

                x/=g;
                y/=g;
            }
            cout<<x+y<<endl;

        }







    }

    return 0;

}




