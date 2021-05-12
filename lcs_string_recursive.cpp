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


///https://www.youtube.com/watch?v=sSno9rV8Rhg&t=1212s
///https://www.youtube.com/watch?v=sSno9rV8Rhg

using namespace std;


string a,b;
ll dp[3005][3005];
ll n,m;

ll lcs(ll i,ll j)
{
    if(i>=n or j>=m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    ll ans=-1;
    if(a[i]==b[j]) ans=max(ans,1+lcs(i+1,j+1));
    else
    {
        ans=max(ans,lcs(i,j+1));
        ans=max(ans,lcs(i+1,j));
    }
    return dp[i][j]=ans;


}
string ans="";
void printlcs(int i,int j)
{
    if(i>=n or j>=m) return;

    if(a[i]==b[j])
    {
        ans+=a[i];
        printlcs(i+1,j+1);
    }
    else
    {
        ll x=lcs(i,j+1);
        ll y=lcs(i+1,j);
        if(x>=y)
        {
            printlcs(i,j+1);
        }
        else
        {
            printlcs(i+1,j);
        }

    }

}

int main()
{
    flash()
    ll i,j,t,cas=0;

        mem(dp,-1);
        cin>>a;
        cin>>b;
        n=a.size();
        m=b.size();

        ll s=lcs(0,0);
        //cout<<s<<endl;
        printlcs(0,0);
        cout<<ans<<endl;




    see_you;
}

/*

abcdefghijklmnzyxwvutsrqpo
opqrstuvwxyzabcdefghijklmn
abcdefghijklmnopqrstuvwxyz
a0b0c0d0e0f0g0h0i0j0k0l0m0n0o0p0q0r0s0t0u0v0w0x0y0z0
*/


