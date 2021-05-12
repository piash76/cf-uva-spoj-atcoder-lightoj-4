#include<bits/stdc++.h>
using namespace std;

char grid[25][25];
int vis[25][25];
int r,c,cnt;
int X[4]= {-1,0,0,1};
int Y[4]= {0,-1,1,0};

void dfs(int i,int j)
{
    int k,vx,vy;
    vis[i][j]=1;
    for(k=0;k<4;k++)
    {
        vx=i+X[k];
        vy=j+Y[k];
        if(vx>=0 && vx<r && vy>=0 && vy<c)
        {
            if(vis[vx][vy]==0 && grid[vx][vy]=='.')
            {
                cnt++;
                dfs(vx,vy);
            }
        }
    }

}

void dfs(int i,int j)
{
    if(i<0 || i>=r || j<0 || j>=c) return;
    else if(grid[i][j]=='.')
    {
        cnt++;
        grid[i][j]='#';
    }
    else if(grid[i][j]=='#') return;
    dfs(i, j+1);
    dfs(i+1, j);
    dfs(i, j-1);
    dfs(i-1, j);

}

int main()
{
    int t,i,j,cs=0;
    cin>>t;
    while(t--)
    {
        cnt=1;
        cin>>c>>r;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                cin>>grid[i][j];
            }
        }
        memset(vis,0,sizeof(vis));
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(grid[i][j]=='@')
                {
                    dfs(i,j);

                }
            }
        }
        printf("Case %d: %d\n", ++cs,cnt);

    }
}

