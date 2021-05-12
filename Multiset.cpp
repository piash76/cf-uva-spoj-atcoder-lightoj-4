///Bismillahir Rahmanir Rahim
///ALLAHU AKBAR
#include<bits/stdc++.h>
#define flash() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define sc1i(a) scanf("%d",&a)
#define sc2i(a,b) scanf("%d %d",&a,&b)
#define   sc3i(a,b,c)       scanf("%d %d %d",&a, &b, &c)
#define    p1i(a)           printf("%d\n",(a))
#define    p2i(a,b)        printf("%d %d\n",(a), (b))
#define    p3i(a,b,c)      printf("%d %d %d\n",(a), (b), (c))


#define sc1l(a) scanf("%lld",&a)
#define sc2l(a,b) scanf("%lld %lld",&a,&b)
#define   sc3l(a,b,c)       scanf("%lld %lld %lld",&a, &b, &c)
#define    p1l(a)           printf("%lld\n",(a))
#define    p2l(a,b)        printf("%lld %lld\n",(a), (b))
#define    p3l(a,b,c)      printf("%lld %lld %lld\n",(a), (b), (c))


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
#define pii             pair<int,int>
#define pll             pair<ll,ll>


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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

//from a loser
//ll a[maxn],b[maxn];

struct FenwickTree
{
	ll N;
	vector<ll> tree;

	void init(ll n)
	{
		N = n;
		tree.assign(n + 1, 0);
	}

	void update(ll idx, ll val)
	{
		while (idx <= N)
		{
			tree[idx] += val;
			idx += idx & -idx;
		}
	}

	void updateMax(ll idx, ll val)
	{
		while (idx <= N)
		{
			tree[idx] = max(tree[idx], val);
			idx += idx & -idx;
		}
	}

	ll pref(ll idx)
	{
		ll ans = 0;
		while (idx > 0)
		{
			ans += tree[idx];
			idx -= idx & -idx;
		}
		return ans;
	}

	ll rsum(ll l, ll r)
	{
		return pref(r) - pref(l - 1);
	}

	ll prefMax(ll idx)
	{
		ll ans = -2e9;
		while (idx > 0)
		{
			ans = max(ans, tree[idx]);
			idx -= idx & -idx;
		}
		return ans;
	}
};

int main()
{
    flash()
    ll i,j,t,cas=0;

    ll n,q;
    sc2l(n,q);
    FenwickTree bit;
    bit.init(n);

    for(i=1;i<=n;i++)
    {
        ll x;
        sc1l(x);
        bit.update(x,1);
    }
    //ll ans=bit.pref(5);
    //cout<<ans<<endl;
    while(q--)
    {
        ll y;sc1l(y);

        if(y>=1) bit.update(y,1);
        else
        {
            y=abs(y);

            ll lo=1,hi=n,ans;
            while(lo<=hi)
            {
                ll mid=(lo+hi)/2;
                if(bit.pref(mid)>=y) {ans=mid;hi=mid-1; }
                else lo=mid+1;
            }
            bit.update(ans,-1);
        }
    }

    if(bit.pref(n)==0) printf("0\n");
    else
    {
        for(i=1;i<=n;i++)
        {
            if(bit.pref(i))
            {
                printf("%lld\n",i);break;
            }
        }
    }




    see_you;
}


