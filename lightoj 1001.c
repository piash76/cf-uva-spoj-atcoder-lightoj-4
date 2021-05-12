
#include<stdio.h>
int main()
{
    int t,a,i,c1,c2;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
       scanf("%d",&a);
       if(a>10)
       {
           c1=10;
           c2=a-10;
       }
       else
       {
           if(a%2==0)
           {
               c1=a/2;
               c2=a/2;
           }
           else
           {
               c1=0;
               c2=a;
           }
       }
       printf("%d %d\n",c1,c2);
    }
}
