
///minimum edge cover in undirected bipartite graph =n-bpm


///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define ll long long
#define pll  pair<ll,ll>

using namespace std;
const int M=505;

ll vis[M],vis2[M],Match[M],a[M];
vector<ll>gp[M];

char grid[25][25];
ll dx[4] = {0,0,1,-1};
ll dy[4] = {1,-1,0,0};
ll n;


bool kuhn(ll u) ///u= left side candidate
{
    for(auto v:gp[u])
    {
        if(vis[v]==0)
        {
            vis[v]=1;

            if(Match[v]==-1 or kuhn(Match[v]))
            {
                Match[v]=u;
                return true;
            }
        }
    }

    return false;

}



ll bpm()
{
    memset(Match,-1,sizeof(Match));

    ll match=0;
    for(ll i=1;i<=n;i++)  ///candidates of one side here left
    {
        memset(vis,0,sizeof(vis));  ///every time we may visit the visited node so that we can compromise

        if(kuhn(a[i])) match++;

    }


    return match;
}




void dfs(ll u,ll c)
{
    vis2[u]=c;
    for(auto v:gp[u])
    {
        if(vis2[v]==-1)
        {
            dfs(v,c^1);
        }
    }
}


int main()
{


    ll t,i,j,k,cas=0;
    scanf("%lld",&t);
    while(t--)
    {

        memset(vis2,-1,sizeof(vis2));
        for(i=0;i<M;i++)  { gp[i].clear(); }

        ll x,y;scanf("%lld %lld",&x,&y);

        ll tot=0;
        map<pll,ll> mp;

        for(i=0;i<x;i++)
        {
            for(j=0;j<y;j++)
            {
                cin>>grid[i][j];
                if(grid[i][j]=='*')
                {
                    tot++;
                    mp[{i,j}]=tot;

                }
            }

        }


        for(i=0;i<x;i++)
        {
            for(j=0;j<y;j++)
            {
                if(grid[i][j]=='*')
                {
                    for(k=0;k<4;k++)
                    {
                        ll i2=i+dx[k];
                        ll j2=j+dy[k];

                        if(i2>=0 and i2<x and j2>=0 and j2<y and grid[i2][j2]=='*')
                        {
                            ll u=mp[{i,j}];
                            ll v=mp[{i2,j2}];
                            gp[u].push_back(v);

                        }
                    }

                }
            }
        }


       // cout<<"TOT "<<tot<<endl;
       for(i=1;i<=tot;i++)
       {
           if(vis2[i]==-1)
           {
               dfs(i,1);
           }
       }

       n=0;
       for(i=1;i<=tot;i++)
       {
           if(vis2[i]==1)
           {
             n++;
             a[n]=i;
           }
       }

       //cout<<"N "<<n<<endl;

       ll ans=tot-bpm();
      // cout<<ans<<endl;

      printf("Case %lld: %lld\n",++cas,ans);



    }

    return 0;

}

/*


4
2 3
o*o
**o

*/




