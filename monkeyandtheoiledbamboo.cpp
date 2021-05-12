#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,i,d,n,j,ans;
    cin>>t;
    for(j=1;j<=t;j++)
    {
        d=-1;
        cin>>n;
        int a[n];
        a[0]=0;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
        }


        for(i=1;i<=n;i++)
        {
           if(a[i]-a[i-1]>d)
           {
               d=a[i]-a[i-1];
           }

        }
        ans=d;
        for(i=1;i<=n;i++)
        {
            if(a[i]-a[i-1]==d)
            {
                d--;
            }
            else if(a[i]-a[i-1]>d)
            {
                ans++;
                break;
            }
        }




        cout<<"Case "<<j<<": "<<ans<<endl;
    }
}
