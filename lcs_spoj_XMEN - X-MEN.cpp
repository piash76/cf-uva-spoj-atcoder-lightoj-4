





///PROBLEM DESCRIPTION:


#include<bits/stdc++.h>

#define speed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);



#define ll long long
#define cy  cout<<"YES"<<endl
#define cn   cout<<"NO"<<endl


using namespace std;




const int mod = 1000000007;


const int mx =1000009;///1e6
ll a[mx],b[mx],c[mx];


int main()
{


    speed()

    ll t,i,j,cas=0;
    cin>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(a));

        memset(c,0,sizeof(a));


        ll n;cin>>n;
        for(i=0;i<n;i++)
        {
            ll x;cin>>x;
            a[x]=i;
        }

        for(i=0;i<n;i++)
        {
            ll x;cin>>x;
            if(a[x])
            {
                c[i]=a[x];
            }
        }

        ll lislen=0,idx;

        for(i=0;i<n;i++)
        {
            idx=lower_bound(b,b+lislen,c[i])-b;

            lislen=max(lislen,idx+1);


            b[idx]=c[i];
        }

        cout<<lislen<<endl;





    }

    return 0;

}




