///https://cses.fi/problemset/task/1695/
///https://usaco.guide/problems/cses-1695-police-chase/solution
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
const int M=505;

ll n,m,s,t;
vector<ll> g[M];
ll par[M],capacity[M][M],vis[M];



ll bfs()
{

    memset(par,-1,sizeof(par));
    memset(vis,0,sizeof(vis));

    queue<pll> q;
    q.push({s,inf});
    par[s]=-2;
    vis[s]=1;

    while(!q.empty())
    {
        ll node=q.front().first;
        ll prev_flow=q.front().second;
        q.pop();


        for(auto child:g[node])
        {

            if(par[child]==-1 and capacity[node][child])
            {

                par[child]=node;
                vis[child]=1;

                ll new_flow=min(prev_flow,capacity[node][child]);

                if(child==t)
                {
                    return new_flow;
                }

                q.push({child,new_flow});
            }
        }
    }

    return 0;

}


ll maxflow()
{
    ll flow=0;

    while(1)
    {
        ll f=bfs();
        if(f==0)
        {

            break;
        }

        flow+=f;

        ll cur=t;
        while(cur!=s)
        {
            ll prev=par[cur];

            capacity[prev][cur]-=f;
            capacity[cur][prev]+=f;

            cur=prev;
        }
    }

    return flow;
}

int main()
{


    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    ll i,j;

    cin>>n>>m;
    s=1,t=n;

    for(i=1;i<=m;i++)
    {
        ll u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);

        capacity[u][v]+=1;
        capacity[v][u]+=1;

    }

    ll s=maxflow();

    //cout<<"S "<<s<<endl;



    vector<pll> ans;
    for(i=1;i<=n;i++)
    {
        for(auto j:g[i])
        {
            if(vis[i]==1 and vis[j]==0)
            {
                ans.push_back({i,j});
            }
        }
    }




    cout<<ans.size()<<endl;
    for(auto x:ans) cout<<x.ff<<" "<<x.ss<<endl;



    return 0;

}




