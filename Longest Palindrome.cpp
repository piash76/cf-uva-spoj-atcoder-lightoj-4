#include<bits/stdc++.h>
#define flash() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define sc1(a) scanf("%lld",&a)
#define sc2(a,b) scanf("%lld %lld",&a,&b)
#define   sc3(a,b,c)       scanf("%lld %lld %lld",&a, &b, &c)
#define    pf1(a)           printf("%lld\n",(a))
#define    pf2(a,b)        printf("%lld %lld\n",(a), (b))
#define    pf3(a,b,c)      printf("%lld %lld %lld\n",(a), (b), (c))

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

#define  pt            printf("Case %d: ",++caseno)

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

using namespace std;

//from a loser

int main()
{
    flash()
   vector<string>s;
	string st;
	int n, m, i;
	cin >> n >> m;
	f1(i,0,n)
	{
		cin >> st;
		s.push_back(st);
	}

    string mid;
    vector<string> a;
    vector<string> b;
    f1(i,0,n)
    {
        string p=s[i];
        string q=s[i];reverse(q.begin(),q.end());
        //cout<<p<<endl;
        vector<string>::iterator it,it1;
        it1=find(s.begin(),s.end(),p);
        it=find(s.begin(),s.end(),q);

        if(it!=s.end())
        {
            cout<<"YES"<<endl;
            a.pb(p);b.pb(q);
            s.erase(it1);
            s.erase(it);
        }
    }

      /* for(string x:a)
        {
            cout<<x;
        }
        reverse(b.begin(),b.end());
        for(string x:b)
        {
            cout<<x;
        }*/

    /*ll sz=a.size()+mid.size()+b.size();
    if(sz==0)
    {
        c(sz);cout<<" "<<endl;
    }
    else
    {
        c(sz);
        for(string x:a)
        {
            cout<<x;
        }
        cout<<mid;
        for(string x:b)
        {
            cout<<x;
        }

    }*/

    see_you;
}
