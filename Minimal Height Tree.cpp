
#include<bits/stdc++.h>
using namespace std;

#define speed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


const int mxn =  2111111;
#define ll long long


ll a[mxn],level[mxn];


int main()
{
    speed()

  ll t,i,j;
    cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            level[i]=0;

        }

        ll src=1,child=-1;
        queue<ll> q;
        q.push(1);
        level[1]=0;

        ll prev=-1,idx=2;
        while(!q.empty())
        {
            ll node=q.front();
            q.pop();
            prev=-1;
           while(a[idx]>=prev and idx<=n)
           {
               prev=a[idx];
               level[a[idx]]=level[node]+1;
               q.push(a[idx]);
               idx++;
           }

        }





        ll mx=-1;
        for(i=1;i<=n;i++) mx=max(mx,level[i]);
        cout<<mx<<endl;

    }

}


