#include<bits/stdc++.h>
#define ll long long
using namespace std;

void merging(ll ar[],ll l,ll m,ll h)
{
    ll i, j, k,x,y;
     x = m - l + 1;
     y =  h - m;


    ll ar1[x+5], ar2[y+5];


    for (i = 0; i <x; i++)
        ar1[i] = ar[l + i];
    for (j = 0; j < y; j++)
        ar2[j] = ar[m + 1+ j];


    i=j=0;
    k = l;
    while (i < x && j < y)
    {
        if (ar1[i] <= ar2[j])
        {
            ar[k] = ar1[i];
            i++;
        }
        else
        {
            ar[k] = ar2[j];
            j++;
        }
        k++;
    }

    while (i < x)
    {
        ar[k] = ar1[i];
        i++;
        k++;
    }

    while (j < y)
    {
        ar[k] = ar2[j];
        j++;
        k++;
    }
}



void mergesort(ll ar[],ll l,ll h)
{
    if (l < h)
    {
        ll m =(l+h)/2;
        mergesort(ar, l, m);
        mergesort(ar, m+1, h);


        merging(ar, l, m, h);
    }
}


int main()
{
    ll n,s,i;
    cin>>n;
    ll a[n+5];
    for(i=0;i<n;i++) cin>>a[i];

    mergesort(a,0,n-1);
    for(i=0;i<n;i++) cout<<a[i]<<" ";


}

