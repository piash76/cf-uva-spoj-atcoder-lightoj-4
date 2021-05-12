#include<bits/stdc++.h>
#define N 1000000
using namespace std;

vector<int> prime;
vector<bool> isprime(N+1,true);
void sieve()
{


   for(int i = 2; i * i <= N; i++)
   {
      if(isprime[i])
      {
         for(int j = i * 2; j <= N; j += i)
         {
            isprime[j] = false;
         }
      }
   }

   for(int i = 2; i<= N; ++i)
   {
      if(isprime[i])
      {
         prime.push_back(i);
      }
   }
}

int main()
{
   sieve();

   long long x,s,j;


   while(cin >> x)
   {
       vector<long long > p;

      if(x==0)return 0;
       if(x<0)
       {
           x=x*(-1);
       }


    long long int k = prime.size();
    for(long long int i=0;i<k; i++)
    {
        if(x%prime[i]==0)
        {

            while(x%prime[i]==0)
            {

                x= x/prime[i];

                p.push_back(prime[i]);


            }
        }
    }
    if(x>1)
    {
       p.push_back(x);
    }

     if(p.size()>1)
     {
         printf("%lld\n",p[p.size()-1]);
     }

       else
       {
           printf("-1\n");
       }

       p.clear();

   }



}
