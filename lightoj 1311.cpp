
#include<bits/stdc++.h>
#define godspeed() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
using namespace std;

int main()
{
    godspeed()
    double v1,v2,v3,a1,a2,t1,t2,tb,b,s;
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {

        scanf("%lf %lf %lf %lf %lf",&v1,&v2,&v3,&a1,&a2);
        t1=v1/a1;
        t2=v2/a2;
        tb=max(t1,t2);
        b=v3*tb;
        s=(v1*t1+0.5*(-a1)*t1*t1)+(v2*t2+0.5*(-a2)*t2*t2);
        printf("Case %d: %.9lf %.9lf\n",i,s,b);
    }

    return 0;


}
