

#include<bits/stdc++.h>
#define flash() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define sc1(a) scanf("%lld",&a)
#define sc2(a,b) scanf("%lld %lld",&a,&b)
#define   sc3(a,b,c)       scanf("%lld %lld %lld",&a, &b, &c)
#define    p1(a)           printf("%lld\n",(a))
#define    p2(a,b)        printf("%lld %lld\n",(a), (b))
#define    p3(a,b,c)      printf("%lld %lld %lld\n",(a), (b), (c))

#define c(x)       cout<<x<<endl
#define cy  cout<<"YES"<<endl
#define cn   cout<<"NO"<<endl
#define f1(i,a,b)  for(int i=a;i<b;i++)
#define f2(i,a,b) 	for(int i=a;i<=b;i++)
#define LCM(a,b)                (a / __gcd(a,b) ) *b
#define GCD(a,b)                __gcd(a,b)
#define dist(x1,y1,x2,y2)       sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define distl(x1,y1,x2,y2)      sqrtl((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define getar(a,n)           for(int i=0;i<n;i++) cin>>a[i]
#define putar(a,n)           for(int i=0;i<n;i++) cout<<a[i]<<endl;
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
#define sorta(a)                   sort(a,a+n)
#define SORT(v)                 sort(v.begin(),v.end())
#define REV(v)                  reverse(v.begin(),v.end())
int caseno=0;

#define  prntcas()             printf("Case %d: ",++caseno)
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

#define mex 20001
#define Vampires 1
#define Lykans 2
using namespace std;

//from a loser 🙂

vector<ll>gp[mex];
ll visited[mex];



int bfs(int source)
{
    int No_V = 0,No_L = 0;
    queue<int>q;
    q.push(source);
    visited[source] = Vampires;
    No_V++;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i = 0; i < gp[u].size(); i++)
        {
            int v = gp[u][i];
            if(visited[v]==0)
            {
                if(visited[u]==Vampires)
                {
                    visited[v] = Lykans;
                    No_L++;
                }
                else
                {
                    visited[v] = Vampires;
                    No_V++;
                }
                q.push(v);
            }
        }
    }

    return max(No_L,No_V);
}

int main()
{
    //flash()
    ll d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,x,y,a,b;
    sc1(t);
    while(t--)
    {
        mem(visited,0);
        f1(i,1,mex) gp[i].clear();

        sc1(n);
        while(n--)
        {
            sc2(a,b);
            gp[a].pb(b);gp[b].pb(a);

        }
        ll c=0;
        f2(i,1,20000)
        {
            if(!gp[i].empty() && visited[i]==0)
            {
                c+=bfs(i);
            }
        }

        prntcas();p1(c);


    }
    see_you;
}



