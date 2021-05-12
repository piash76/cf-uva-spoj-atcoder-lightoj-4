
///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define ll long long
#define pll  pair<ll,ll>
#define ff    first
#define ss    second

using namespace std;

const ll inf=1e10;
const int mod=1e9+7;

const int M=55;

ll dis[M][M],Match[M],vis[M];
char grid[M][M];
ll n,g,h;

ll dx[4] = {0,0,1,-1};
ll dy[4] = {1,-1,0,0};

vector<ll> gp[1005];



bool kuhn(ll u)
{
    for(auto v:gp[u])
    {
        if(vis[v]==0)
        {
            vis[v]=0;

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
    for(ll i=1;i<=g;i++)
    {
        memset(vis,0,sizeof(vis));

        if(kuhn(i)) match++;
    }

    return match;
}


void bfs(ll sx,ll sy)
{
    queue<pll> q;
    q.push({sx,sy});


}

int main()
{

    ll t,i,j,cas=0,k,l;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);



        for(i=0;i<n;i++)
        {
           scanf("%s",grid[i]);
        }

        g=0,h=0;


        map<pll,ll>m1,m2;

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(grid[i][j]=='G')
                {
                    g++;
                    m1[{i,j}]=g;
                }
                else if(grid[i][j]=='H')
                {
                    h++;
                    m2[{i,j}]=h;
                }
            }
        }


        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(grid[i][j]=='G')
                {
                    bfs(i,j);
                }
            }
        }





       ll low=0,hi=20,ans=-1;

        while(low<=hi)
        {
            ll mid=(low+hi)/2;   ///possible time
            cout<<"MID "<<mid<<endl;


            for(i=0;i<55;i++) gp[i].clear();


            ///constructing graph

            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(grid[i][j]=='G')
                    {
                        for(k=0;k<n;k++)
                        {
                            for(l=0;l<n;l++)
                            {
                                if(grid[k][l]=='H' and dis[i][j][k][l] <= mid)
                                {
                                    cout<<"I "<<i<<" J "<<j<<" K "<<k<<" L "<<l<<endl;

                                     ll u = m1[{i,j}];
                                    ll v = m2[{k,l}];

                                    cout<<"U "<<u<<" V "<<v<<endl;

                                    gp[u].push_back(v);

                                    cout<<"I "<<i<<" J "<<j<<" K "<<k<<" L "<<l<<endl;


                                }
                            }
                        }
                    }
                }
            }

             ll milse=bpm();

             cout<<"BPM "<<milse<<" H "<<h<<endl;

             if(milse==h)
             {
                // cout<<"YEs"<<endl;
                 ans=(mid);  ///for back going 2*mid

                 hi=mid-1;
             }
             else low=mid+1;



        }




        if(ans==-1)
        {
           printf("Case %lld: Vuter Dol Kupokat\n",++cas);
        }
        else
        {
           printf("Case %lld: %lld\n",++cas,(2*ans)+2);
        }

       /// */



    }

    return 0;

}




