
///https://www.youtube.com/watch?v=GhjwOiJ4SqU&t=567s


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

const ll inf=1e9;
const int mod=1e9+7;
const int mod2=2147483647; ///2^31-1

///V*(E^2)

const int M=1100;

ll par[M],capacity[M][M];
vector<ll> g[M];

ll s,t;

ll bfs()
{
    memset(par,-1,sizeof(par));


    par[s]=-2;


    queue<pair<ll,ll> > q;
    q.push({s,inf});

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

            ll prev = par[cur];

            //cout<<"PREV "<<prev<<endl;

            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;  ///reversed edge capacity==flow
            cur = prev;
        }
    }

    return flow;
}



int main()
{


    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);



    ll i,j;

    ll n,m,k;cin>>n>>m>>k;

    s=0;
    t=1080;

    while(k--)
    {
        ll u,v;cin>>u>>v;

        capacity[u][v+n]=1;
        g[u].push_back(v+n);
        g[v+n].push_back(u);

        capacity[s][u]=1;
        g[s].push_back(u);

        capacity[v+n][t]=1;
        g[v+n].push_back(t);


    }

    ll ans=maxflow();
    cout<<ans<<"\n";

    set<pll> p;  ///same pair multiple times

    for(i=1;i<=n;i++)
    {
        for(auto j:g[i])
        {
            if(capacity[i][j]==0)
            {
                p.insert({i,j-n});
            }
        }
    }



    for(auto x:p) cout<<x.ff<<" "<<x.ss<<endl;


    return 0;

}

/*

4 3 12
4 3
1 3
2 2
3 1
4 1
1 2
2 3
3 1
4 1
1 3
2 2
3 2


*/




