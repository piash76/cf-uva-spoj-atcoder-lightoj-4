
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

const int M=210;

ll a[M],b[M],par[M],capacity[M][M];

vector<ll> g[M];

ll sr,tn;

ll bfs()
{
    memset(par,-1,sizeof(par));

    queue<pair<ll,ll> > q;
    q.push({sr,inf});
    par[sr]=-2;

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

                if(child==tn)
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

        ll cur = tn;


        while (cur != sr)
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





int main()
{


    ll t,i,j,cas=0;
    scanf("%lld",&t);
    while(t--)
    {
        memset(capacity,0,sizeof(capacity));
        for(i=0;i<M;i++) g[i].clear();

        ll n,m;

        scanf("%lld",&n);
        for(i=1;i<=n;i++) scanf("%lld",&a[i]);

        scanf("%lld",&m);
        for(i=1;i<=m;i++) scanf("%lld",&b[i]);

        sr=0,tn=n+m+2;

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(b[j]%a[i]==0)
                {

                    //cout<<"I "<<a[i]<<" J "<<b[j]<<endl;

                    ///a[i]=2 a[j]=6
                    g[sr].push_back(i);
                    capacity[sr][i]=1;

                    g[i].push_back(j+n);
                    g[j+n].push_back(i);
                    capacity[i][j+n]=1;

                    g[j+n].push_back(tn);
                    capacity[j+n][tn]=1;



                }
            }
        }

        ll ans=maxflow();
        printf("Case %lld: %lld\n",++cas,ans);






    }

    return 0;

}




