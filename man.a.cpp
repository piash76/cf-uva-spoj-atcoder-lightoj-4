#include<bits/stdc++.h>
using namespace std;

long long fib(long long a,long long b,long long n)
{
  long long  c, i;
  if( n == 0)
    return a;
   if(n==1)
   {
       return b;
   }
  for (i = 2; i <= n; i++)
  {
     c = a^b;
     a = b;
     b = c;
  }
  return b;
}

int main()
{
    long long a,b,n,t,s;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>n;
        s=fib(a,b,n);
        cout<<s<<endl;
    }
}
