///minimum path cover in DAG = n-bpm


///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
#define ll long long
#define pll  pair<ll,ll>


using namespace std;

const int N=505;

int vis[N],Match[N],start[N],finish[N],a[N],b[N],c[N],d[N];


vector<int> g[N];

int n;

bool kuhn(ll u)
{
    for(auto v:g[u])
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


int bpm()
{
    memset(Match,-1,sizeof(Match));

    int match=0;
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        if(kuhn(i)) match++;
    }

    return match;
}



int main()
{
    int t,i,j,cas=0;
    scanf("%lld",&t);
    while(t--)
    {

        for(i=0;i<N;i++) g[i].clear();

        scanf("%d",&n);

        for(i=1;i<=n;i++)
        {
            int h,m;
            scanf("%d:%d %d %d %d %d",&h,&m,&a[i],&b[i],&c[i],&d[i]);

            start[i]=(h*60)+m;
            finish[i]=start[i]+abs(a[i]-c[i])+abs(b[i]-d[i]);

        }


        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)  ///times are in ascending order
            {
                ///if no i taxi can cover no j taxi
                ///abs(c[i]-a[j])+abs(d[i]-b[j]) time to go to j from i

                if(finish[i]+abs(c[i]-a[j])+abs(d[i]-b[j])<start[j])
                {
                    g[i].push_back(j); ///DAG
                }


            }
        }


        int ans=n-bpm();

        printf("Case %d: %d\n",++cas,ans);




    }

    return 0;

}

/*



*/



