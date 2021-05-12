
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

const int M=105;

ll n,m,s,t;
ll par[M],capacity[M][M];
vector<ll> g[M];

ll bfs()
{
    memset(par,-1,sizeof(par));

    queue<pll>q;
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

   map<string,ll> mp;
   mp["XXL"]=1;
   mp["XL"]=2;
   mp["L"]=3;
   mp["M"]=4;
   mp["S"]=5;
   mp["XS"]=6;


    ll ts,i,j,cas=0;
    scanf("%lld",&ts);

    while(ts--)
    {
        memset(capacity,0,sizeof(capacity));

        scanf("%lld %lld",&n,&m);

        s=0,t=6+m+2;

        for(i=1;i<=m;i++) ///adding source to contestent
        {
            g[s].push_back(6+i);
            capacity[s][6+i]=1;
        }

        for(i=1;i<=6;i++) ///adding size of t shirt to sink
        {
            g[i].push_back(t);
            capacity[i][t]=n;
        }


        for(i=1;i<=m;i++)
        {
            string x,y;cin>>x>>y;

            ll c1=mp[x];

            g[6+i].push_back(c1);
            g[c1].push_back(6+i);
            capacity[6+i][c1]=1;

            ll c2=mp[y];

            g[6+i].push_back(c2);
            g[c2].push_back(6+i);
            capacity[6+i][c2]=1;
        }


        ll ans=maxflow();

        //cout<<ans<<endl;

        printf("Case %lld: ",++cas);

        if(ans>=m) printf("YES\n");
        else printf("NO\n");




    }

    return 0;

}




