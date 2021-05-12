

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


const int mx =250*250;///1e6
ll a[mx+10],c[mx+10],B[mx+10];


int main()
{


    ll t,i,j,cas=0;
    scanf("%lld",&t);
    while(t--)
    {
        memset(a,-1,sizeof(a));
        memset(B,0,sizeof(B));

        ll n,p,q;scanf("%lld %lld %lld",&n,&p,&q);

        for(i=1;i<=p+1;i++) ///first permutation
        {
            ll x;scanf("%lld",&x);
            a[x]=i;
        }

        ll idx=0;
        for(i=1;i<=q+1;i++)  ///second permutation
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
            indx=lower_bound(B,B+lislen,c[i])-B;

            lislen=max(lislen,indx+1);

            B[indx]=c[i];
        }


        printf("Case %lld: ",++cas);
        printf("%lld\n",lislen);


    }


    return 0;

}


/*

1
3 6 7
1 7 5 4 8 3 9
1 4 3 5 6 2 8 9

*/




