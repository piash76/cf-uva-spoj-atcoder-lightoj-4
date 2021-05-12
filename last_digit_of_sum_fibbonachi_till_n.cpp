


///Given two integers 𝑛 and 𝑚, output 𝐹𝑛 mod 𝑚 (that is, the remainder of 𝐹𝑛 when divided by 𝑚).
///1 ≤ 𝑛 ≤ 1014, 2 ≤ 𝑚 ≤ 103


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
const int M=10000005;

ll a[M];


int main()
{


    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n,m;cin>>n;

    a[0]=0,a[1]=1;
    ll prev=1,cnt=2;

    for(ll i=2;;i++)
    {
        a[i]=(a[i-1]%10+a[i-2]%10)%10;

        cnt++;

        if(a[i]==1 and prev==0) {break;}

        prev=a[i];


    }

    cnt-=2;

    //cout<<cnt<<endl;

   ll idxr=(n+1)%cnt;
   ll idxl=n%cnt;

  // for(ll i=1;i<=cnt;i++) a[i]+=(a[i-1]%10)%10;


  // for(ll i=0;i<=cnt;i++) cout<<a[i]<<endl;

  ll s=((a[idxr]%10)*(a[idxl]%10))%10;

  cout<<s;






    return 0;

}



