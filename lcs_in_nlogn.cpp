

///https://stackoverflow.com/questions/30768610/finding-longest-common-subsequence-in-onlogn-time
///





///PROBLEM DESCRIPTION:lcs in nlogn
///c[i]=a[b[i]]
///if a and b are permutations then lcs of them is lis of C (strictly)

#include<bits/stdc++.h>

#define speed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);



#define ll long long
#define cy  cout<<"YES"<<endl
#define cn   cout<<"NO"<<endl


using namespace std;




const int mod = 1000000007;


const int mx =200009;///1e6
ll a[mx+10],c[mx+10],B[mx+10];


int main()
{


    ll t,i,j,cas=0;
    scanf("%lld",&t);
    while(t--)
    {
        memset(a,-1,sizeof(a));
        memset(B,0,sizeof(B));

        ll n;scanf("%lld",&n);

        for(i=1;i<=n;i++) ///first permutation
        {
            ll x;scanf("%lld",&x);
            a[x]=i;
        }

        ll idx=0;
        for(i=1;i<=n;i++)  ///second permutation
        {
            ll x;scanf("%lld",&x);
            if(a[x]!=-1)
            {
                c[idx++]=a[x];
            }
        }

        ll lislen=0,indx=0;

        for(i=0;i<idx;i++)
        {
            indx=upper_bound(B,B+lislen,c[i])-B;

            lislen=max(lislen,indx+1);

            B[indx]=c[i];
        }

        ll ans=n-lislen+n-lislen;

        printf("Case %lld: ",++cas);
        printf("%lld\n",ans);


    }


    return 0;

}


/*

2
5
1 3 5 4 2
1 5 4 3 2
4
1 2 4 3
3 4 2 1

*/




