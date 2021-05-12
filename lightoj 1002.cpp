
#include<bits/stdc++.h>
#define flash() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define sc1(a) scanf("%lld",&a)
#define sc2(a,b) scanf("%lld %lld",&a,&b)
#define   sc3(a,b,c)       scanf("%lld %lld %lld",&a, &b, &c)
#define    p1(a)           printf("%lld\n",(a))
#define    p2(a,b)        printf("%lld %lld\n",(a), (b))
#define    p3(a,b,c)      printf("%lld %lld %lld\n",(a), (b), (c))
#define    el             cout<<endl
#define c(x)       cout<<x<<endl
#define cy  cout<<"YES"<<endl
#define cn   cout<<"NO"<<endl
#define f1(i,a,b)  for(ll i=a;i<b;i++)
#define f2(i,a,b) 	for(ll i=a;i<=b;i++)
#define fr(i,a,b)   for(ll i=a;i>=b;i--)
#define LCM(a,b)                (a / __gcd(a,b) ) *b
#define GCD(a,b)                __gcd(a,b)
#define dist(x1,y1,x2,y2)       sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define distl(x1,y1,x2,y2)      sqrtl((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define getar(a,n)           for(int i=0;i<n;i++) cin>>a[i]
#define getar1(a,n)           for(int i=1;i<=n;i++) cin>>a[i]
#define putar(a,n)           for(int i=0;i<n;i++) cout<<a[i]<<" "
#define putar1(a,n)           for(int i=1;i<=n;i++) cout<<a[i]<<" "
#define all(a)                  a.begin(),a.end()
#define lla(A)                  A.rbegin(), A.rend()
#define unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define pb                      push_back
#define mk                      make_pair
#define ff                      first
#define ss                      second
#define greatersrt(v)  sort(v.begin(),v.end(),greater<ll>())
#define min3(a,b,c)             min(a,min(b,c))
#define min4(a,b,c,d)           min(a,min(b,min(c,d)))
#define max3(a,b,c)             max(a,max(b,c))
#define max4(a,b,c,d)           max(a,max(b,max(c,d)))
#define max5(a,b,c,d,e)         max(max3(a,b,c),max(d,e))
#define min5(a,b,c,d,e)         min(min3(a,b,c),min(d,e))
#define mem(a,x)                memset(a,x,sizeof(a))
#define see_you                     return 0
#define sorta(a,n)                   sort(a,a+n)
#define SORT(v)                 sort(v.begin(),v.end())
#define REV(v)                  reverse(v.begin(),v.end())
int caseno=0;

#define  printcase             printf("Case %d: ",++caseno)
#define Debug                   cout<<endl<<"AND I AM IRONMAN"<<endl;
#define binleastsigonebit(x)    __builtin_ffs(x)
#define binleadingzeroes(x)     __builtin_clz(x)
#define bintrailingzeroes(x)    __builtin_ctz(x)
#define bintotalones(x)         __builtin_popcount(x)

//Datatypes
#define ll                      long long
#define ULL                     unsigned long long
#define LD                      long double
#define UI                      unsigned int
#define US                      unsigned short

//Constants
const int MOD = 1000000007; // 998244353
const ll INF = 1e18;
const ll inf = 0xFFFFFFFFFFFFFFFL;
#define PI                      acos(-1.0)
#define EulerGamma              0.57721566490153286060651209
#define inf                     1e18
using namespace std;

//from a loser


vector<ll> g[100005],cost1[100005];
map< pair<ll,ll>,ll >cost;
ll dis[100005],path[100005];

void printpath(ll i)
{
    if(i!=1)
    {
       printpath(path[i]);
    }

    cout<<i<<" ";
}


void Dijkstra(int mt)
{
    priority_queue<ll> q;
    q.push(mt);
    dis[mt]=0;
    while(!q.empty())
    {
        ll u=q.top();
        q.pop();
        for(int i=0;i<g[u].size();i++)
        {
            ll v=g[u][i];
            ll cst=cost1[u][i];
            ll k=max(dis[u],cst);
            if(k<dis[v])
            {
                dis[v]=k;
                path[v]=u;
                q.push(v);
            }
        }
    }

}

int main()
{
    ll n,m,i,j,x,y,c,mt,t,cs=1;
    sc1(t);
    while(t--)
    {

    sc2(n,m);
    for (i=0;i<=n ;i++)
    {
        dis[i]=inf;
        g[i].clear();
        cost1[i].clear();

    }




   while(m--)
   {
       cin>>x>>y>>c;
       g[x].push_back(y);
       g[y].push_back(x);
       cost1[x].push_back(c);
       cost1[y].push_back(c);
       //cost[{x,y}]=c;
       //cost[{y,x}]=c;
   }
   sc1(mt);
   Dijkstra(mt);

  // printcase;
   //printf("\n");
    cout<<"Case "<<cs++<<":"<<endl;

   for(i=0;i<n;i++)
   {

   if(dis[i]==inf)
   {
       cout<<"Impossible"<<endl;
   }
   else
   {
      cout<<dis[i]<<endl;
   }
   }

    }
   see_you;
}
