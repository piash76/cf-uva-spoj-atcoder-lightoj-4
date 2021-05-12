///Bismillahir Rahmanir Rahim
///ALLAHU AKBAR
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
#define f1(i,a,b)  for(ll i=a;i<b;i++)
#define f2(i,a,b) 	for(ll i=a;i<=b;i++)
#define fr(i,a,b)   for(ll i=a;i>=b;i--)
#define LCM(a,b)                (a / __gcd(a,b) ) *b
#define GCD(a,b)                __gcd(a,b)
#define dist(x1,y1,x2,y2)       sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define distl(x1,y1,x2,y2)      sqrtl((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define getar(a,n)           for(int i=0;i<n;i++) scanf("%lld",&a[i])
#define getar1(a,n)           for(int i=1;i<=n;i++) scanf("%lld",&a[i])
#define putar(a,n)           for(int i=0;i<n;i++) printf("%lld ",a[i])
#define putar1(a,n)           for(int i=1;i<=n;i++) printf("%lld ",a[i])
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
#define gp ' '
#define nl                        printf("\n")
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
const int maxn = 211111;
const int N = 1111111;
#define PI                      acos(-1.0)
#define EulerGamma              0.57721566490153286060651209


//ll powmod(ll base, ll power) { if (power == 0) return 1; else {ll cur = powmod(base, power / 2); cur = cur * cur; cur = cur % MOD;if (power % 2 == 1) cur = cur * base; cur = cur % MOD; return cur;}


/*------------------------------Graph Moves----------------------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/



using namespace std;

//from a loser
//ll a[maxn],b[maxn];
char s[maxn];
ll a[maxn];
ll tree[4*maxn],lazy[4*maxn];

void build(ll node,ll b,ll e)
{
    if(b==e)
    {
        tree[node]=a[b];
        return;
    }
    ll left=2*node;
    ll right=(2*node)+1;
    ll mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);

    tree[node]=tree[left]+tree[right];
}

void update(ll node,ll b,ll e,ll i,ll j, ll val)
{
    tree[node]+=lazy[node];

    if(lazy[node]!=0 and b!=e)
    {
        lazy[2*node]+=lazy[node];
        lazy[2*node+1]+=lazy[node];
    }

    lazy[node]=0;


    /// no overlap
    if (i > e || j < b)  return;

    ///total overlap

    if (b >= i && e <= j)
    {
        tree[node]+=val;
        lazy[2*node]+=val;  ///propagating
        lazy[2*node+1]+=val;
        return;
    }

    ///partial overlap

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;
    update(left, b, mid, i, j, val);
    update(right, mid + 1, e, i, j, val);

    tree[node]=tree[left]+tree[right];
}



ll query(ll node,ll b,ll e,ll i,ll j)
{

    tree[node]+=lazy[node];

    if(lazy[node]!=0 and b!=e)
    {
        lazy[2*node]+=lazy[node];
        lazy[2*node+1]+=lazy[node];
    }

    lazy[node]=0;


    /// no overlap
    if (i > e || j < b)  return 0;

    ///total overlap

    if (b >= i && e <= j)
    {

        return tree[node];
    }

    ///partial overlap

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    ll x = query(left, b, mid, i, j);
    ll y = query(right, mid + 1, e, i, j);

    return x+y;
}







int main()
{
    //flash()
    ll i,j,t,cas=0;
    sc1(t);
   getchar();
    while(t--)
    {
        mem(tree,0);mem(lazy,0);

        scanf("%s",s);

        ll n=strlen(s);

        for(i=0;i<n;i++) a[i+1]=s[i]-'0';
        //printf("%s\n",s);

        build(1,1,n);
        printf("Case %lld:\n",++cas);
        ll m;
        scanf("%lld",&m);
        getchar();

        while(m--)
        {

            char ch;
            scanf("%c",&ch);
            getchar();
            if(ch=='I')
            {
                ll l,r;
                sc2(l,r);
                update(1,1,n,l,r,1);

                getchar();
            }
            else
            {
                ll idx;
                scanf("%lld",&idx);

                ll ans=query(1,1,n,idx,idx);
                getchar();
                printf("%lld\n",ans%2);


            }

        }




    //cout<<"Case "<<++cas<<": "<<ans<<endl;
    // printf("Case %lld: %lld\n",++cas,ans);
    }


    see_you;
}
/*

2
0011001100
6
I 1 10
I 2 7
Q 2
Q 1
Q 7
Q 5
1011110111
6
I 1 10
I 2 7
Q 2
Q 1
Q 7
Q 5

*/



