#include<bits/stdc++.h>
using namespace std;

int binary(int a[],int n,int x)
{

    int l=0,h=n-1,m,p;
    while(l<=h)
    {
        m=(l+h)/2;
        if(a[m]==x)
        {
            p=m;
            break;
        }
        if(x<a[m])
        {
            h=m-1;
        }
        else
        {
            l=m+1;
        }
    }
    if(l>h)
    {
        return -1;
    }
    else
    {
        return p+1;
    }
}

int main()
{
    int n,q,r,i,j,x,t=0;
    while(1)
    {
        cin>>n>>q;
        if(n==0 && q==0)
        {
            break;
        }
        int a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        cout<<"CASE# "<<++t<<":"<<endl;
        for(i=1;i<=q;i++)
        {
            cin>>x;
            r=binary(a,n,x);
            (r==-1)? cout<<""<<x<<" not found"<<endl : cout<<""<<x<<" found at "<<r<<endl;
        }
    }
}
