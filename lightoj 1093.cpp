
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
#define    nl             cout<<"\n"
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
const int maxn = 200000;
#define PI                      acos(-1.0)
#define EulerGamma              0.57721566490153286060651209





using namespace std;

//from a loser
ll a[maxn];
ll max_tree[3*maxn],min_tree[3*maxn];

void build(ll node,ll b,ll e)
{
    if(b==e)
    {
        max_tree[node]=a[b];
        min_tree[node]=a[b];
        return;
    }
    ll left=2*node;
    ll right=(2*node)+1;
    ll mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);

    min_tree[node]=min(min_tree[left],min_tree[right]);
    max_tree[node]=max(max_tree[left],max_tree[right]);
}

ll max_query(ll node,ll b,ll e,ll i,ll j)
{
    if(i>e || j<b) return -INF;

    if (b >= i && e <= j) return max_tree[node];
    ll left=2*node;
    ll right=(2*node)+1;
    ll mid=(b+e)/2;
    ll x=max_query(left,b,mid,i,j);
    ll y=max_query(right,mid+1,e,i,j);

    return max(x,y);

}

ll min_query(ll node,ll b,ll e,ll i,ll j)
{
    if(i>e || j<b) return INF;

    if (b >= i && e <= j) return min_tree[node];
    ll left=2*node;
    ll right=(2*node)+1;
    ll mid=(b+e)/2;
    ll x=min_query(left,b,mid,i,j);
    ll y=min_query(right,mid+1,e,i,j);

    return min(x,y);

}


int main()
{
    //flash()
    ll t,i,cas=0;
    sc1(t);
    while(t--)
    {
        mem(max_tree,0);
        mem(min_tree,0);

        ll n,k;
        sc2(n,k);

        for(i=1;i<=n;i++) sc1(a[i]);

        build(1,1,n);

        ll ans=-INF;

        for(i=1;i+k-1<=n;i++)
        {
            ll x=min_query(1,1,n,i,i+k-1);
            ll y=max_query(1,1,n,i,i+k-1);
            //cout<<y-x<<endl;
            ans=max(ans,y-x);
        }

        printf("Case %lld: %lld\n",++cas,ans);

    }



    see_you;
}

/*
3
6 2
6 0 8 8 8 4
8 3
19 8 4 13 12 1 0 13
2 2
1 1

*/



