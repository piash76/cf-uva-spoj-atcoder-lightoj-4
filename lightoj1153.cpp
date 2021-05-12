

///https://cp-algorithms.com/graph/edmonds_karp.html#toc-tgt-3

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

const ll inf=1e7;
const int mod=1e9+7;
const int mod2=2147483647; ///2^31-1

const int M=105;

ll n,m,s,t;
ll capacity[M][M],parent[M];
vector<ll>g[M];

ll bfs()
{

    ///cout<<"STRT "<<endl;

    for(ll i=0;i<=M;i++) parent[i]=-1;

    parent[s] = -2;
    queue<pair<ll, ll>> q;
    q.push({s,inf});

    while (!q.empty())
    {
        ll node = q.front().first;
        ll prev_flow = q.front().second;
        q.pop();

       // cout<<"CUR "<<node<<" FLOW "<<flow<<endl;

        for (ll next : g[node])
        {


            if (parent[next] == -1 && capacity[node][next])
            {

                parent[next] = node;



                ll new_flow = min(prev_flow, capacity[node][next]);
                //cout<<"POSSIBLEE "<<new_flow<<endl;

                if (next == t)
                {
                    return new_flow;
                }

                q.push({next, new_flow});
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


        while (cur != s) {

            ll prev = parent[cur];

            //cout<<"PREV "<<prev<<endl;

            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}




int main()
{


    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    ll tst,cas=0;cin>>tst;
    while(tst--)
    {

        for(ll i=0;i<=M;i++) g[i].clear();
        memset(capacity,0,sizeof(capacity));


    ll i,j;


    cin>>n>>s>>t>>m;

    for(i=1;i<=m;i++)
    {
        ll u,v,cap;cin>>u>>v>>cap;

         g[u].push_back(v);
         g[v].push_back(u);



        capacity[u][v]+=cap;
        capacity[v][u]+=cap;
    }



     cout <<"Case " <<++cas<<": "<<maxflow()<<"\n";

    }


    return 0;

}

/*

2
4
1 4 5
1 2 20
1 3 10
2 3 5
2 4 10
3 4 20
4
1 4 2
1 4 20
1 4 20


*/


