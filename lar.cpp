#include<bits/stdc++.h>
using namespace std;
#define N 10000100
#define ll long long int
bool isPrime[N];
ll prime[N],l;
void Prime(){
    prime[l++] = 2 ;
    long long i,j ;
    for(j=4;j<N;j+=2) isPrime[j] = true ;
    for(i=3;i<N;i+=2)
    {
        if(isPrime[i]==false)
        {
            prime[l++] = i ;
            for(j=i*i;j<N;j+=i) isPrime[j] = true ;
        }
    }
}
ll getFactor(ll n){
    if(n<6) return -1;
    ll t = sqrt(n),j=0, p[100];
    memset(p,0,sizeof(p));
    for(ll i=0;prime[i]<=t;i++){
        if(n%prime[i]==0){
            while(n%prime[i]==0) n/=prime[i];
            p[j++] = prime[i];
            t=sqrt(n);
        }
    }
    if(n>1) p[j++] = n;
    if(j==1) return -1;
    sort(p,p+j);
    return p[j-1];
}
int main()
{
    ll n; Prime();
    while(scanf("%lld",&n) && n){
        printf("%lld\n", getFactor(llabs(n)));
    }
}
