
///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define ll long long
#define pll  pair<ll,ll>

#define ff    first
#define ss    second

using namespace std;

const ll inf=100000000;
const int mod=1e9+7;
const int mod2=2147483647; ///2^31-1
const int M=305;

ll n,m,s,t;

vector<ll> g[M];
ll capacity[M][M],par[M];

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

                if(child==t) return new_flow;

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
        ll new_flow=bfs();
        if(new_flow==0) break;

        flow+=new_flow;

        ll cur=t;
        while(cur!=s)
        {
            ll prev=par[cur];


            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;  ///reversed edge capacity==flow
            cur = prev;
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
        for(i=0;i<M;i++) g[i].clear();
        memset(capacity,0,sizeof(capacity));


        scanf("%lld %lld",&n,&m);

        s=1,t=(n);

        for(i=2;i<=n-1;i++)
        {
            ll x;scanf("%lld",&x);

            ///in
            capacity[i][i+n]+=x;
            capacity[i+n][i]+=x;

            g[i].push_back(i+n);
            g[i+n].push_back(i);

            ///out
            capacity[i][i+n+n]+=x;
            capacity[i+n+n][i]+=x;

            g[i].push_back(i+n+n);
            g[i+n+n].push_back(i);

        }




        for(i=1;i<=m;i++)
        {
            ll u,v,c;scanf("%lld %lld %lld",&u,&v,&c);
            ll mn=LLONG_MAX;
            ll mx=LLONG_MIN;
            ///source and destinition can be edge: tst case 1
            mn=min(u,v);
            mx=max(u,v);

            if(mn==1 and mx==n)
            {
                g[u].push_back(v);
                g[v].push_back(u);
                capacity[u][v]+=c;
                capacity[v][u]+=c;
            }
            else if(mn==1 and mx!=n)
            {
                g[mn].push_back(mx+n);
                g[mx+n].push_back(mn);
                capacity[mn][mx+n]+=c;
                capacity[mx+n][mn]+=c;
            }
            else if(mn!=1 and mx==n)
            {
                g[mn+n+n].push_back(mx);
                g[mx].push_back(mn+n+n);
                capacity[mn+n+n][mx]+=c;
                capacity[mx][mn+n+n]+=c;

            }
            else if(mn!=1 and mx!=n)
            {
                g[mn+n+n].push_back(mx+n);
                g[mx+n].push_back(mn+n+n);
                capacity[mn+n+n][mx+n]+=c;
                capacity[mx+n][mn+n+n]+=c;

            }



        }

        ll ans=maxflow();

        printf("Case %lld: %lld\n",++cas,ans);


    }

    return 0;

}

/*

4
8 4
394 859 531 536 727 276
7 8 297
5 2 251
2 4 331
8 1 938
6 9
918 121 685 805
1 6 24
3 6 703
4 1 483
5 3 251
4 6 515
3 4 559
2 1 675
5 4 106
3 2 128
9 5
46 307 78 140 789 892 364
2 7 394
2 3 337
1 3 673
6 8 840
2 9 497
8 11
212 900 400 438 999 47
5 7 614
6 4 332
8 4 705
5 1 771
5 6 454
2 7 546
1 4 110
2 1 641
8 3 268
2 3 583
4 2 506

Case 1: 938
Case 2: 628
Case 3: 46
Case 4: 612



*/




