
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




const int M=205;

const double eps=1e-9;  ///meaning we count 8 place after point

bool Equal(double x,double y)  ///x==y
{
    return fabs(x-y)<eps;
}

double Lesser(double x,double y)  ///x<y
{
    return y-x>eps;
}


ll capacity[M][M],par[M],tmpcapacity[M][M];
vector<ll> g[M];
ll n;

struct info
{
    ll x,y,p,c; ///p ashce source theke ,c jabe node theke
};


ll bfs(ll s,ll t)
{

    ///cout<<"STRT "<<endl;

   memset(par,-1,sizeof(par));

    par[s] = -2;
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

            if (par[next] == -1 && tmpcapacity[node][next])
            {

                par[next] = node;

                ll new_flow = min(prev_flow,tmpcapacity[node][next]);
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




ll maxflow(ll s,ll t)
{
    ll flow=0;

    for(ll i=0;i<M;i++)
    {
        for(ll j=0;j<M;j++)
        {
            tmpcapacity[i][j]=capacity[i][j];
        }
    }

    while(1)
    {
        ll new_flow=bfs(s,t);
        if(new_flow==0) break;

        flow+=new_flow;

        ll cur=t;
        while(cur!=s)
        {
            ll prev=par[cur];

            tmpcapacity[prev][cur]-=new_flow;
           tmpcapacity[cur][prev]+=new_flow;

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

        memset(capacity,0,sizeof(capacity));
        for(ll i=0;i<=M;i++) g[i].clear();

        double d;
        scanf("%lld %lf",&n,&d);

        ll tot=0,s=0;

        info a[n+5];

        for(i=1;i<=n;i++)
        {
           scanf("%lld %lld %lld %lld",&a[i].x,&a[i].y,&a[i].p,&a[i].c);
            tot+=a[i].p;

        }

        for(i=1;i<=n;i++)
        {
            capacity[s][i]+=a[i].p;
            g[s].push_back(i);

            //capacity[i][i+n]+=a[i].c;
           // g[i].push_back(i+n);
           // g[i+n].push_back(i);
        }


        for(i=1;i<=n;i++) ///i to j
        {
            for(j=1;j<=n;j++)
            {
                if(i==j) continue;

                double xx=a[i].x-a[j].x;
                double yy=a[i].y-a[j].y;

                double dist=xx*xx+yy*yy;

                double mdist=d*d;

                if(Lesser(dist,mdist) or Equal(dist,mdist))
                {
                  capacity[i][j]+=a[i].c;

                  g[i].push_back(j);
                  g[j].push_back(i);
                }






            }
        }

        //ll ans1=maxflow(s,5);
        //cout<<"ANS "<<ans1<<endl;

        vector<ll> ans;
        for(i=1;i<=n;i++)
        {
            ll ans1=maxflow(s,i);
            //cout<<"ANS "<<ans1<<endl;
            if(ans1==tot)
            {
                ans.push_back(i-1);
            }
        }



        printf("Case %lld:",++cas);

        if(ans.size())
        {
             for(auto x:ans)
              {
                printf(" %lld",x);
              }
        }
        else printf(" -1");


        printf("\n");








    }

    return 0;

}




