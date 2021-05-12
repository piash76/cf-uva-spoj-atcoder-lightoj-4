

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
const int mod2=2147483647; ///2^31-1

const int M=20001;

ll vis[M];
vector<ll> g[M];
ll b,w;
bool f;

void dfs(ll u,ll c)
{
    vis[u]=c;
    if(c==1) b++;
    else w++;

    for(auto v:g[u])
    {
        if(vis[v]==-1) dfs(v,c^1);
        else
        {
            if(vis[u]==vis[v]) f=false;
        }
    }

}


int main()
{


    ll t,i,j,cas=0;
    scanf("%lld",&t);
    while(t--)
    {
        for(i=0;i<M;i++) g[i].clear();
        memset(vis,-1,sizeof(vis));

        ll m;scanf("%lld",&m);
        for(i=1;i<=m;i++)
        {
            ll u,v;scanf("%lld %lld",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }


        f=true;
        ll cnt=0;
        for(i=1;i<M;i++)
        {
            if(vis[i]==-1 and !g[i].empty())
            {
             w=b=0ll;

             dfs(i,1);

             cnt+=max(w,b);

            }

        }

        printf("Case %lld: %lld\n",++cas,cnt);


    }

    return 0;

}
/*

2
2
1 2
2 3
3
1 2
2 3
4 2

*/



