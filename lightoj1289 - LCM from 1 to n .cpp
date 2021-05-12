
///http://sajibtalukder2k16.blogspot.com/2020/07/lightoj-1289-lcm-from-1-to-n-solution.html

#include<bits/stdc++.h>
using namespace std;

const int N = 100000005;
//const int SZ = 5761455 + 3;
const int SZ=6000000;
//const int SZ=1e6;
//bool isprime[N+5];
int prime[SZ+5],tot;
bitset<N+5> isprime;
unsigned cum[SZ+5];



void sieve()
{

    int sq=sqrt(N);
    isprime[2]=0; //as 0 indicates prime
    for(int i=4;i<=N;i+=2) isprime[i]=1; ///o(n)
    for(int i=3;i<=sq;i+=2) ///O(nlog(log(n)));
    {
        if(isprime[i]==0)
        {
            for(int j=i*i;j<=N;j+=i)isprime[j]=1;
        }
    }

   // int j=0;
    for(int i=2;i<=N;i++)
    {
        if(isprime[i]==0)
        {
            prime[tot]=i;
            tot++;
        }
    }

}

unsigned extra(unsigned n)
{
    unsigned sum=1;

    for(int i=0;prime[i]*prime[i]<=n;i++)   ///calculating the power of prime^x<=n
    {
        unsigned s=1;
        int tmp=n,x=tmp/prime[i];

        while(x>=prime[i])
        {
            s*=prime[i];
            x/=prime[i];
        }



        sum*=s;

    }

    return sum;
}










int main()
{
    sieve();

    cum[0]=2;
    for(int i=1;i<=tot;i++)
    {
        cum[i]=cum[i-1]*unsigned(prime[i]);
    }



    int t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        unsigned n;
        scanf("%u",&n);

        int idx=lower_bound(prime,prime+tot,n+1)-prime;
        idx--;

        unsigned ans=cum[idx];
        ans*=extra(n);




        printf("Case %d: ",++cas);
        printf("%u\n",ans);
    }
}
