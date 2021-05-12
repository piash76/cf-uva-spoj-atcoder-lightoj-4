#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,m,i,j,s,k,x,y;
    cin>>n>>m;
    long long a[n],b[n],c[m];
    s=0;

    for(i=0;i<n;i++)
    {
        cin>>a[i];
        s+=a[i];
        b[i]=s;
    }

    for(i=0;i<m;i++)
    {
        cin>>c[i];
    }

    for(i=0;i<m;i++)
    {
        cout<<lower_bound(b,b+n,c[i])-b+1<<" ";
        k=lower_bound(b,b+n,c[i])-b;

        if(k==0)
        {
            cout<<c[i]<<endl;
        }
        else
        {
            cout<<c[i]-b[k-1]<<endl;
        }

    }




}
