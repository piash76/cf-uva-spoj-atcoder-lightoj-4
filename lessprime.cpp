#include<bits/stdc++.h>
#define n 1000000
using namespace std;

bool isprime[1000000];
long long prime[1000000],j=0;

void sieve()
{

    long long sq=sqrt(n);
    isprime[2]=0; //0 indicates prime or true
    for(long long i=4;i<=n;i+=2) isprime[i]=1;
    for(long long i=3;i<=sq;i+=2)
    {
        if(isprime[i]==0)
        {
            for(j=i*i;j<=n;j+=i)isprime[j]=1;
        }
    }




}

int main()
{
    sieve();
    int a,i,t;

    cin>>t;
    while(t--)
    {
    cin>>a;

    for(i=(a/2+1);i<=a;i++)
    {
        if(isprime[i]==0)
        {
            cout<<i<<endl;
            break;
        }

    }

    }
}

