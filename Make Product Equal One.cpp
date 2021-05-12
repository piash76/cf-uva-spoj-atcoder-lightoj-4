#include<bits/stdc++.h>
#define ll long long
#define bye return 0
#define godspeed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define inf 1e9
using namespace std;

int main()
{
    godspeed()
    ll n,i,j,m,k,p=0,ne=0,ans=0,x,z=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        if(x>0)
        {
            ans+=abs(1-x);

        }
        else if(x<0)
        {
            x*=-1;
            ans+=abs(1-x);
            ne++;
        }
        else
        {
            z++;
        }

    }
    if(ne%2==1 && z==0)
    {
        ans+=2;
    }
    ans+=z;
    cout<<ans<<endl;
     bye;
}
