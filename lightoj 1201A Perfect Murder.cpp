

///maximum independent set =total vertices - max flow
///V * E^2


///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define ll long long
#define pll  pair<ll,ll>

#define ff    first
#define ss    second


using namespace std;

const ll inf=1e18;
const int mod=1e9+7;
const int mod2=2147483647; ///2^31-1

const int M=1009;

ll par[M],capacity[M][M],vis[M];
vector<ll> g[M],gp[M];
ll s,t;



ll bfs()
{
    memset(par,-1,sizeof(par));

    queue<pair<ll,ll> > q;
    q.push({s,inf});
    par[s]=-2;

    while(!q.empty())
    {
        ll node=q.front().first;
        ll prev_flow=q.front().second;
        q.pop();

       /// cout<<"NODE "<<node<<" PREV "<<prev_flow<<endl;

        for(auto child:g[node])
        {
            if(par[child]==-1 and capacity[node][child])
            {
                par[child]=node;

                ll new_flow=min(prev_flow,capacity[node][child]);

               /// cout<<"CHILD "<<child<<" FLOW "<<new_flow<<endl;

                if(child==t)
                {

                    ///cout<<"HERE  CHILD "<<child<<" TN "<<tn<<endl;

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
    ll flow = 0;

    ll new_flow;

    while (1)
    {
        new_flow = bfs();
        if(new_flow==0) break;


        flow += new_flow;
       // cout<<"NEW FLOW "<<new_flow<<endl;

        ll cur = t;


        while (cur != s)
        {
            ll prev = par[cur];

            //cout<<"PREV "<<prev<<endl;

            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;  ///reversed edge capacity==flow
            cur = prev;
        }
    }

    return flow;
}



void dfs(ll u,ll c)
{
    vis[u]=c;

    for(auto v:gp[u])
    {
        if(vis[v]==-1)
        {
            dfs(v,c^1);
        }
        ///else it is bipartite so no need to check
    }
}




int main()
{


    ll ts,i,j,cas=0;

    scanf("%lld",&ts);

    while(ts--)
    {
        getchar();

        memset(vis,-1,sizeof(vis));
        memset(capacity,0,sizeof(capacity));
        for(i=0;i<M;i++) {g[i].clear(); gp[i].clear();}

        ll v,e;scanf("%lld %lld",&v,&e);
        for(i=1;i<=e;i++)
        {
            ll u,v;scanf("%lld %lld",&u,&v);
            gp[u].push_back(v);
            gp[v].push_back(u);
        }


        for(i=1;i<=v;i++)
        {
            if(vis[i]==-1) dfs(i,1);
        }


        s=0,t=1002;

        ///vis[i]=1 -> a
        for(i=1;i<=v;i++)
        {
            if(vis[i]==1)
            {
                for(auto j:gp[i])
                {
                    g[s].push_back(i);
                    capacity[s][i]=1;

                    g[i].push_back(j);
                    g[j].push_back(i);
                    capacity[i][j]=1;

                    g[j].push_back(t);
                    capacity[j][t]=1;
                }

            }

        }


         ll ans=v-maxflow();

        printf("Case %lld: %lld\n",++cas,ans);









    }

    return 0;

}




