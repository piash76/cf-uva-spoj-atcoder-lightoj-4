#include<bits/stdc++.h>
#define ll long long
#define bye return 0
#define mx 100000
#define godspeed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    godspeed()
    int i,j,k,t,l,r,n,x,y,z,maxa=0,mini=0;
    int a[mx];
    cin>>n>>l>>r;
    j=1;
    mini=j;
    for(i=1;i<=l-1;i++)
    {

      j*=2;
      mini+=j;
    }
    mini+=(n-l);
     k=1;
     maxa=k;

    for(i=1;i<=r-1;i++)
    {

      k*=2;
      maxa+=k;
    }
    maxa+=pow(2,r-1)*(n-r);

     cout<<mini<<" "<<maxa<<endl;
     bye;

}
