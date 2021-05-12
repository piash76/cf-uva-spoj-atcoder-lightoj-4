




///PROBLEM DESCRIPTION:given the x co-ordinates of north and south ends of bridges maximum non overlapping bridge no


#include<bits/stdc++.h>

#define speed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);



#define ll long long
#define cy  cout<<"YES"<<endl
#define cn   cout<<"NO"<<endl


using namespace std;




const int mod = 1000000007;


const int mx =1000005;///1e6
ll b[mx],f[mx];
pair<ll,ll> a[mx];

int main()
{


    speed()

    ll t,i,j,cas=0;
    cin>>t;
    while(t--)
    {
        memset(f,0,sizeof(f));
        memset(b,0,sizeof(f));

        ll n;cin>>n;
        for(i=0;i<n;i++) cin>>a[i].first;
        for(i=0;i<n;i++) cin>>a[i].second;

        sort(a,a+n);

        ll lislen=0,idx;

        for(i=0;i<n;i++)
        {
            idx=upper_bound(b,b+lislen,a[i].second)-b;

            f[i]=idx+1;

            lislen=max(lislen,idx+1);

            b[idx]=a[i].second;


        }

        cout<<lislen<<endl;





    }

    return 0;

}





