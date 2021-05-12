include<bits/stdc++.h>
using namespace std;

char gp[30][30];
int vis[30][30];
int n,r,c;

void dfs()
{


}

int main()
{
    int t,i,j,k;
    cin>>t;
    while(t--)
    {
        cin>>r>>c;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                cin>>gp[i][j];
            }
        }
        if(r==1 && c==1)
        {
            cout<<"invalid"<<endl;
            continue;
        }

    }
}
