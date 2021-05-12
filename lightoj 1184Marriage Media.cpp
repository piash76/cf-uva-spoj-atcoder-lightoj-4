///kuhn algorithm for maximum bpm
///N*E

///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define ll long long


using namespace std;

const ll inf=1e18;
const int mod=1e9+7;

const int M=55;

struct info
{
    ll h,a,d;
};

info men[M],women[M];

ll vis[M],jamai[M],bow[M];
ll n,m;

bool ok(ll jamai_id,ll bow_id)
{
  return (abs(men[jamai_id].h-women[bow_id].h)<=12 and  abs(men[jamai_id].a-women[bow_id].a)<=5 and men[jamai_id].d==women[bow_id].d) ;
}


bool kuhn(ll u)  ///u jamai
{

    for(ll v=1;v<=m;v++)  ///searching for bow
    {
        if(ok(u,v))
        {
            if(vis[v]==0)
            {
                vis[v]=1;

                if(bow[v]==-1 or kuhn(bow[v]))
                {
                    bow[v]=u;
                    jamai[u]=v;
                    return true;
                }
            }
        }
    }

    return false;

}


ll bpm()
{
    memset(jamai,-1,sizeof(jamai));
    memset(bow,-1,sizeof(bow));

    ll match=0;
    for(ll i=1;i<=n;i++)   ///search bow for every jamai
    {
        memset(vis,0,sizeof(vis));   ///every time we need to visit the visited node so that we can compromise
         if(kuhn(i)) match++;
    }

    return match;


}


int main()
{

    ll t,i,j,cas=0;
    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld %lld",&n,&m);
        for(i=1;i<=n;i++)
        {
            scanf("%lld %lld %lld",&men[i].h,&men[i].a,&men[i].d);
        }

        for(i=1;i<=m;i++)
        {
            scanf("%lld %lld %lld",&women[i].h,&women[i].a,&women[i].d);
        }

        ll ans=bpm();
        printf("Case %lld: %lld\n",++cas,ans);


    }

    return 0;

}




