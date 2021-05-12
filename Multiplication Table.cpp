#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{

    ll n,i,j,s,k,r;
    cin>>n;
    ll a[n],m[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>m[i][j];
        }
    }
    r=sqrt(m[0][1]*m[0][2]/m[1][2]);

    a[0]=r;

    for(i=1;i<n;i++)
    {
        a[i]=m[0][i]/r;

    }
    for(i=0;i<n;i++)
    {
       cout<<a[i]<<" ";


    }
}
