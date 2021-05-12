
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,s,t,j;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        s=0;
        cin>>n;
        int a[n];
        for(j=0;j<n;j++)
        {
            cin>>a[j];
            if(a[j]>=0) s+=a[j];
        }

        printf("Case %d: %d\n",i,s);

    }
}
