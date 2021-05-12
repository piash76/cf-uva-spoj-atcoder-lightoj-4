#include<bits/stdc++.h>
#define ll long long
using namespace std;

int prime(int n)
{
    int i;
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
}


int main()
{

   ll n;
   cin>>n;
   if(prime(n)==1)
   {
       cout<<1<<endl;

   }
   else if(n%2==0)
   {
       cout<<2<<endl;
   }
   else if(prime(n-2)==1)
   {
       cout<<2<<endl;
   }
   else
   {
       cout<<3<<endl;
   }
}


