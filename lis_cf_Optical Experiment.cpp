




///PROBLEM DESCRIPTION:maximum intersecting groups of rays which intersect all of them in that group(LIS reverse)


#include<bits/stdc++.h>

#define speed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);



#define ll long long
#define cy  cout<<"YES"<<endl
#define cn   cout<<"NO"<<endl


using namespace std;




const int mod = 1000000007;


const int mx =1000009;///1e6
ll c[mx],b[mx],in[mx],pos1[mx],pos2[mx];


int main()
{

    ll t,i,j,cas=0;
    ll n;scanf("%lld",&n);

    for(i=1;i<=n;i++)
    {
        ll x;scanf("%lld",&x);
        in[i]=x;
        pos1[in[i]]=i;
    }

    for(i=1;i<=n;i++)
    {
        ll x;scanf("%lld",&x);
        pos2[x]=i;
    }

    for(i=1;i<=n;i++)
    {
        c[pos1[in[i]]]=pos2[in[i]];
    }


    //for(i=1;i<=n;i++) cout<<c[i]<<" ";
   // cout<<endl;

   ll lislen=0,idx;

    for(i=n;i>=1;i--)
    {
        idx=upper_bound(b,b+lislen,c[i])-b;

        lislen=max(lislen,idx+1);

        b[idx]=c[i];
    }

    printf("%lld\n",lislen);


    return 0;

}





