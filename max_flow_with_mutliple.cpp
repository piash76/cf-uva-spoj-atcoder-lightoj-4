///https://lightoj.com/problem/power-transmission

///maxflow with multiple source and sink and node capacity

///http://www.shafaetsplanet.com/?p=2231

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

const int M=210;
vector<ll> g[M];

ll par[M],capacity[M][M];
ll n,m,s,t;


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

        for(auto child:g[node])
        {
            if(par[child]==-1 and capacity[node][child])
            {
                par[child]=node;

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
        ll newflow=bfs();
        if(newflow==0) break;

        flow+=newflow;

        ll cur=t;

        while(cur!=s)
        {
            ll prev=par[cur];

            capacity[prev][cur]-=newflow;
            capacity[cur][prev]+=newflow;

            cur=prev;

        }


    }


    return flow;
}





int main()
{


    ll ts,i,j,cas=0;
    scanf("%lld",&ts);
    while(ts--)
    {
        for(i=0;i<=M;i++) g[i].clear();
        memset(capacity,0,sizeof(capacity));

        scanf("%lld",&n);

        s=0,t=(2*n)+1;

        for(i=1;i<=n;i++)
        {
            ll x;scanf("%lld",&x);
            capacity[i][i+n]+=x;

            g[i].push_back(i+n);
            g[i+n].push_back(i);
        }

        scanf("%lld",&m);

        while(m--)
        {
            ll u,v,cst;scanf("%lld %lld %lld",&u,&v,&cst);

            capacity[u+n][v]+=cst;

            g[u+n].push_back(v);
            g[v].push_back(u+n);

        }

        ll b,d;scanf("%lld %lld",&b,&d);

        for(i=1;i<=b;i++)
        {
            ll u;scanf("%lld",&u);

           // cout<<"B "<<u<<endl;

            g[s].push_back(u);

            capacity[s][u]+=inf;
        }

        for(i=1;i<=d;i++)
        {
            ll u;scanf("%lld",&u);

            //cout<<"D "<<u<<endl;

            g[u+n].push_back(t);

            capacity[u+n][t]+=inf;
        }


        ll ans=maxflow();

       // cout<<"ANS "<<ans<<endl;
        printf("Case %lld: %lld\n",++cas,ans);




    }

    return 0;

}





