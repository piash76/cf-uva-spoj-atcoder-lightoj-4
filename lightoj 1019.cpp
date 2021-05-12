
#include<bits/stdc++.h>
#define ll long long
#define inf 1e8
using namespace std;

int g[205][205],n;

void setval()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
            {
                g[i][j]=0;
            }
            else
            {
                g[i][j]=inf;
            }
        }
    }
}
void floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
}

int main()
{
    int t,i,j,cas=0,a,b,c,m;
    cin>>t;
    while(t--)
    {


        cin>>n>>m;
        setval();



        while(m--)
        {
            cin>>a>>b>>c;
            g[a][b]=min(g[a][b],c);
            g[b][a]=min(g[b][a],c);
        }
        floyd();
        printf("Case %d: ",++cas);
        if(g[1][n]==inf) cout<<"Impossible"<<endl;
        else cout<<g[1][n]<<endl;
    }
}

