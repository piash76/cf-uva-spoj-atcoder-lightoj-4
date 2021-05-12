


///Bismillahir Rahmanir Rahim
///ALLAHU AKBAR
#include<bits/stdc++.h>

using namespace std;

const int maxn = 10005;

#define ll long long


int n,m;
vector<int> g[maxn];
int vis[maxn],in[maxn],low[maxn],par[maxn];
int timer,bridgecnt;
bool found;
map<pair<int,int>,int>mp;

void clean(int n)
{
    mp.clear();
    for(int i=0;i<=n;i++)
    {
        g[i].clear();
        vis[i]=0;
        in[i]=0;
        low[i]=0;
        par[i]=0;
    }

}
void dfs(int node)
{
    vis[node]=1;
    in[node]=low[node]=timer;
    timer++;



    for(auto child: g[node])
    {
        if(child==par[node]) continue;
        if(vis[child])
        {
            low[node]=min(low[node],in[child]); ///connecting the child with grand parent

        }
        else
        {
            par[child]=node;

           dfs(child);

            if(low[child]>in[node])
            {
                bridgecnt++;
                mp[{min(child,node),max(child,node)}]=1;
                ///found=true;///bridge found
            }

           low[node]=min(low[node],low[child]); ///connecting the parent with grand parent
        }
    }
}



int main()
{

    int i,j,t,cas=0,k;
    scanf("%d",&t);
    while(t--)
    {
        //getchar();

        scanf("%d",&n);

        timer=0;
        bridgecnt=0;
       clean(n);




       // cout<<n<<endl;
       for(i=0;i<n;i++)
        {
            int u,m;
            scanf("%d (%d)",&u,&m);
           // cout<<u<<" "<<m<<endl;

            for(j=0;j<m;j++)
            {
                int v;
                scanf("%d",&v);
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }


        for(i=0;i<n;i++)
        {
            if(!vis[i]) dfs(i);
        }

        printf("Case %d:\n",++cas);
        printf("%d critical links\n",bridgecnt);

        for(auto it:mp)
        {
           printf("%d - %d\n",it.first.first,it.first.second);
        }






    }




}

/*



3

8
0 (1) 1
1 (3) 2 0 3
2 (2) 1 3
3 (3) 1 2 4
4 (1) 3
7 (1) 6
6 (1) 7
5 (0)



    0



    2

    0 (1) 1

    1 (1) 0


*/


