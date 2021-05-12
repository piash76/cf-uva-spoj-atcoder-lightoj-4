#include<bits/stdc++.h>
#define ll long long

using namespace std;
int vis[1000];
int main()
{
    int i,j,k,l,n,t,a,b,c,f;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
        }

        memset(vis,0,sizeof(vis));

        while(1)
        {
         f=0;
        for(i=n-1;i>=1;i--)
        {
            if(a[i]>a[i+1] && vis[i]==0)
            {
                swap(a[i],a[i+1]);
                vis[i]=1;
                f=1;
            }


        }
        if(f==0)
        {
            break;
        }


        }

        for(i=1;i<=n;i++)
        {
            cout<<a[i]<<" ";
        }

       cout<<endl;
    }

  return 0;
}
