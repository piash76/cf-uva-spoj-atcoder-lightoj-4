
#include<stdio.h>
#include<math.h>
#define pi  2 * acos (0.0)
int main()
{
    int t,i;
    double r,a,c,b,x;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lf",&r);
    c=pi*r*r;
    a=2*r;
    b=a*a;
    x=b-c;
    printf("Case %d: %.2lf\n",i,x);


}
}
