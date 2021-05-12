

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

ll a[M];


int main()
{


    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    ll t,i,j;
    ll n;cin>>n;

    vector<ll> s;

    if(n==1) s.push_back(1);
    else if(n==2) s.push_back(2);
    else
    {
        ll id=1,sm=0;
        while(1)
        {

            if(n-sm-id>=id+1)
            {
                s.push_back(id);
                sm+=id;
                id++;
            }
            else
            {
                s.push_back(n-sm);
                break;
            }

        }


    }

     cout<<s.size()<<endl;
        for(auto x:s) cout<<x<<" ";


    return 0;

}



