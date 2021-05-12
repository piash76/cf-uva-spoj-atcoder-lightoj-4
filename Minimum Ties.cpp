

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
const int M=30000005;

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
        if(n==2) cout<<0<<endl;
        else
        {


            ll s=n*(n-1)/2;
            ll d=s/n;

            for(i=1;i<=s;i++) a[i]=0;

            ll shuru=0,sesh=n,cnt=1,y=0,p=0;

            while(1)
            {





                ll c1=d,c2=d-p;
                p++;

               // cout<<"C1 "<<c1<<" C2 "<<c2<<endl;

                ll idxst=shuru+1;  ///1
                ll idxend=y+(sesh-cnt);  ///n-1
                cnt++;

                if(idxst==s) { a[idxst]=1;break; }

                //cout<<"IDXS "<<idxst<<" IDXE "<<idxend<<endl;

                ll idxend2=idxend;

                while(c1>0) { a[idxst++]=1; c1--; }

                while(c2>0) {a[idxend--]=-1; c2--; }

                shuru=idxend2;   ///(n-1)
                y=idxend2;    ///(n-1)



            }

            for(i=1;i<=s;i++) cout<<a[i]<<" ";
            cout<<endl;
        }


    }

    return 0;

}



