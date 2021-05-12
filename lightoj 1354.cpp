
#include<bits/stdc++.h>
#define godspeed() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
using namespace std;

int dectobin(int n)
{
        int r=0,x=1;
        while(n>0)
        {

        r+=n%2*x;
        x*=10;
        n/=2;

        }
        return r;


}
int main()
{
    godspeed()
        int t,i,a,b,c,d,w,x,y,z;
        scanf("%d",&t);

        for(i =1; i<=t;i++)
        {
                scanf("%d.%d.%d.%d",&a,&b,&c,&d);
                scanf("%d.%d.%d.%d",&w,&x,&y,&z);

                if(dectobin(a)==w && dectobin(b)==x && dectobin(c)==y && dectobin(d)==z)
                printf("Case %d: Yes\n",i);
                else
                printf("Case %d: No\n",i);

        }
        return 0;


}
