#include<bits/stdc++.h>
using namespace std;

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
            r=binary_search(a,a+n,x);

            (r==1)? cout<<""<<x<<" found at "<<(upper_bound(a,a+n,x)-a)+1<<endl : cout<<""<<x<<" not found"<<endl ;
        }
    }
}
