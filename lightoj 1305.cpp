
#include<bits/stdc++.h>
#define godspeed() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
using namespace std;

int main()
{
    godspeed()
    int t,i,j,ax,bx,cx,dx,ay,by,cy,dy,s,a;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>ax>>ay>>bx>>by>>cx>>cy;
        dx=ax+cx-bx;
        dy=ay+cy-by;
        s=((ax*by)+(bx*cy)+(cx*dy)+(dx*ay))-((ay*bx)+(by*cx)+(cy*dx)+(dy*ax));
        if(s<0)
        {
          s*=-1;
        }

        a=0.5*s;
        printf("Case %d: %d %d %d\n",i,dx,dy,a);
    }









}
