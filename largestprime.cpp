#include<bits/stdc++.h>
#define ll long long
#define n 10000100
using namespace std;

bool isprime[n];
ll prime[n],j;

int sieve()
{

    ll sq=sqrt(n);
    isprime[2]=0; //as 0 indicates prime
    for(ll i=4;i<=n;i+=2) isprime[i]=1;
    for(ll i=3;i<=n;i+=2)
    {
        if(isprime[i]==0)
        {
            for(ll j=i*i;j<=n;j+=i)isprime[j]=1;
        }
    }

    ll j=0;
    for(ll i=2;i<=n;i++)
    {
        if(isprime[i]==0)
        {
            prime[j]=i;
            j++;
        }
    }

    /*for(ll i=0;i<j;i++)
    {
        cout<<prime[i]<<endl;
    }*/


}

ll lar(ll x)
{

       ll d[100]={0},s,k;

       k=0;

      s=sqrt(x);
       for(ll i=0;prime[i]<=s;i++)
        {
        if(x%prime[i]==0)
          {
            while(x%prime[i]==0)
            {
              d[k]=prime[i];
              k++;
              x/=prime[i];

            }

          }
         }



      if(x>1)
      {
         d[k]=x;
         k++;
      }
      sort(d,d+k);

      /*for(ll i=0;i<k;i++)
      {
          cout<<d[k]<<" "<<endl;
      }*/
      if(k==1) return -1;
      else
      {

       return d[k-1];


      }
}

int main()
{
   sieve();
   ll k,x,s;

   while(cin >> x)
   {
        if(x==0) return 0;
        printf("%lld\n",lar(abs(x)));
   }


}
