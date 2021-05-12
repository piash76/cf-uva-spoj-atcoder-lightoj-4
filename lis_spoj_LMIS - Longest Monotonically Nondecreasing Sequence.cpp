




///PROBLEM DESCRIPTION:


#include<bits/stdc++.h>

#define speed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);



#define ll long long
#define cy  cout<<"YES"<<endl
#define cn   cout<<"NO"<<endl


using namespace std;




const int mod = 1000000007;


const int mx =1001000;///1e6
ll a[mx],b[mx],f[mx],lis[mx];

///a for input,b for saving new temporary increasing sub sequence,
///f for saving length of increasing sub sequence

int main()
{


    //speed()

    ll t,i,j,cas=0;


    ll n=0;
    ll x;
    while(scanf("%lld",&x)>0)
    {
        a[n++]=x;

    }

    //cout<<n<<endl;


    ll l=0;

    for(i=0;i<n;i++)
    {
        ll idx=upper_bound(b,b+l,a[i])-b;

       // ll idx=lower_bound(b,b+l,a[i])-b;

        ///lower bound for strictly increasing

        f[i]=idx+1;

        l=max(l,idx+1);

        b[idx]=a[i];
    }

    ll lislen=l;

   printf("%lld\n",n-lislen);







}





