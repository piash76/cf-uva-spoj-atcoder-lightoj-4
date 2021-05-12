#include<bits/stdc++.h>
#define pi acos(-1)
using namespace std;

int main()
{
    int i;
    double r,R,n,t,theta;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>R>>n;
        theta=(pi/n);
        r=(R*sin(theta))/(1+sin(theta));
        printf("Case %d: %.6lf\n",i,r);

    }
}

