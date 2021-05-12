#include<bits/stdc++.h>
#define n 10000
#define ll long long
using namespace std;


bool isprime[n+5];
int prime[n+5],j;
void sieve()
{

    int sq=sqrt(n);
    isprime[2]=0; //as 0 indicates prime
    for(int i=4;i<=n;i+=2) isprime[i]=1;
    for(int i=3;i<=sq;i+=2)
    {
        if(isprime[i]==0)
        {
            for(int j=i*i;j<=n;j+=i)isprime[j]=1;
        }
    }

    int j=0;
    for(int i=2;i<=n;i++)
    {
        if(isprime[i]==0)
        {
            prime[j]=i;
            j++;
        }
    }

    /*for(long long i=0;i<j;i++)
    {
        cout<<prime[i]<<endl;
    }*/

}

//finding highest power of primes less or equal to number
int gen(int p,int na)
{
   int c=0;
   int x=p;
   while(x<=na)
   {
       c+=(na/x);
       x*=p;
   }
   return c;
}


int main()
{
    sieve();
    int x,i,j,k,l,t,nt,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&nt);
        bool flag=true;
        printf("Case %d: %d = ",++cas,nt);
        for(i=0;prime[i]<=nt;i++)
        {
          if(flag) printf("%d (%d)",prime[i],gen(prime[i],nt)),flag=false;
          else printf(" * %d (%d)",prime[i],gen(prime[i],nt));

        }


        printf("\n");
    }

}




