




///PROBLEM DESCRIPTION:


#include<bits/stdc++.h>

#define speed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);



#define ll long long
#define cy  cout<<"YES"<<endl
#define cn   cout<<"NO"<<endl


using namespace std;




const int mod = 1000000007;


const int mx =1000009;///1e6
ll a[mx],b[mx],f[mx];


int main()
{


    speed()

    ll t,i,j,cas=0;
    cin>>t;
    while(t--)
    {
        memset(b,0,sizeof(b));
        memset(f,0,sizeof(f));

        ll n;cin>>n;
        for(i=0;i<n;i++) cin>>a[i];
        ll l;cin>>l;

        ll lislen=0,ans=LLONG_MAX;

        for(i=0;i<n;i++)
        {
            ll idx=lower_bound(b,b+lislen,a[i])-b;

            lislen=max(lislen,idx+1);

            f[i]=idx+1;

            b[idx]=a[i];
        }

        for(i=0;i<n;i++)
        {
            if(f[i]>=l) ans=min(ans,a[i]);
        }

        if(ans==LLONG_MAX) ans=-1;

        cout<<ans<<endl;




    }

    return 0;

}





