
///kuhn algorithm for maximum bpm
///N*E
///MINIMUM path cover in DAG =total vertices-bpm

///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define ll long long

using namespace std;

const ll inf=1e18;
const int mod=1e9+7;
const int mod2=2147483647; ///2^31-1

const int M=1005;

ll vis[M],Match[M];
vector<ll> g[M];
ll n,m;


bool kuhn(ll u)
{
    for(auto v:g[u])
    {
        if(vis[v]==0)
        {
            vis[v]=1;

            if(Match[v]==-1 or kuhn(Match[v]) )
            {
                Match[v]=u;
                return true;
            }
        }
    }

    return false;
}


ll bpm()
{
    memset(Match,-1,sizeof(Match));
    ll match=0;

    for(ll i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        if(kuhn(i)) match++;
    }

    return match;
}

int main()
{


    ll t,i,j,cas=0;
   scanf("%lld",&t);
    while(t--)
    {
        getchar();

        for(i=0;i<M;i++) g[i].clear();

        scanf("%lld %lld",&n,&m);

        for(i=1;i<=m;i++)
        {
            ll u,v;scanf("%lld %lld",&u,&v);
            g[u].push_back(v);
        }


        ll ans=n-bpm();

        printf("Case %lld: %lld\n",++cas,ans);



    }

    return 0;

}




