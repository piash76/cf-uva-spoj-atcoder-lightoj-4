

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

ll c[M];


int main()
{


    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t,i,j;
    cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        for(i=1;i<=n;i++) cin>>c[i];

        ll presumodd=c[1],presumevn=c[2],mnodd=c[1],mnevn=c[2],oddcnt=1,evncnt=1;
        ll ans=n*(c[1]+c[2]);

        for(i=3;i<=n;i++)
        {
            if(i%2)
            {
                oddcnt++;
                presumodd+=c[i];
                mnodd=min(mnodd,c[i]);
            }
            else
            {
                 evncnt++;
                presumevn+=c[i];
                mnevn=min(mnevn,c[i]);
            }

            ll x=presumodd-mnodd + ((n-oddcnt+1)*mnodd);

            ll y=presumevn-mnevn + ((n-evncnt+1)*mnevn);

            ans=min(ans,x+y);


        }

        cout<<ans<<endl;


    }

    return 0;

}



