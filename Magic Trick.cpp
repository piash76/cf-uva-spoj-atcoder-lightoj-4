

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
const int M=200005;

ll a[M];


int main()
{


    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t,i,j;



    ll n;cin>>n;
    vector< pair<string,ll> >v(n+5);

    for(i=1;i<=n;i++)
    {
        string s;ll x;cin>>s>>x;
        v.push_back({s,x});
    }

    ll sum=0;

    for(i=1;i<=100;i++)
    {
        ll num=i;
        bool f=true;
        for(auto x:v)
        {
            string st=x.ff;
            ll no=x.ss;
            if(st=="ADD") num+=no;
            else if(st=="SUBTRACT") num-=no;
            else if(st=="MULTIPLY") num*=no;
            else if(st=="DIVIDE")
            {
                if(num%no==0)
                {
                    num/=no;
                }
                else { f=false;break; }
            }

            if(num<0) {f=false;break;}

        }
        if(f) sum++;
    }

    cout<<100-sum<<endl;

    return 0;

}


/*

1
SUBTRACT 5

2
ADD 5
DIVIDE 5

*/




