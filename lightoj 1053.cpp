
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,i,j,x,y,z;
    cin>>t;
    int a[3];
    for(i=1;i<=t;i++)
    {
        for(j=0;j<3;j++)
        {
            cin>>a[j];
        }
        sort(a,a+3);
        x=a[0];
        y=a[1];
        z=a[2];

        if((x*x+y*y)==z*z)printf("Case %d: yes\n",i);
        else printf("Case %d: no\n",i);
    }
}
