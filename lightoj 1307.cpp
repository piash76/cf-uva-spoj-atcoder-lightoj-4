
#include<bits/stdc++.h>
#define ll long long
#define see_you return 0
#define godspeed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main()
{
    //godspeed()
    ll i,j,n,k,m,l,t,s,cas=0,x;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<ll> a;
        for(i=0;i<n;i++) scanf("%lld",&x),a.push_back(x);
        sort(a.begin(),a.end());
        ll c=0;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                s=lower_bound(a.begin(),a.end(),a[i]+a[j])-a.begin();
                //cout<<s<<endl;
               c+=(s-j-1);



            }
        }
        printf("Case %lld: %lld\n",++cas,c);

    }
    see_you;
}
