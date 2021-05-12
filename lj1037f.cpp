#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,t,i,j,s,k;
    cin>>t;
    for(k=1;k<=t;k++)
    {
        int c=0;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {

                s=upper_bound(a,a+n,a[i]+a[j])-a;
                c=c+(n-s);
            }
        }

        cout<<c<<endl;
    }
}
