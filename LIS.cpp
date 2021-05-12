

///https://algorithmsandme.com/longest-increasing-subsequence-in-onlogn/


///PROBLEM DESCRIPTION:LIS


#include<bits/stdc++.h>

#define speed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);



#define ll long long
#define cy  cout<<"YES"<<endl
#define cn   cout<<"NO"<<endl


using namespace std;




const int mod = 1000000007;


const int mx =1000005;///1e6
ll a[mx],b[mx],f[mx],lis[mx];

///a for input,b for saving new temporary increasing sub sequence,
///f for saving length of increasing sub sequence

int main()
{


    speed()

    ll t,i,j,cas=0;


    ll n;cin>>n;
    for(i=0;i<n;i++) cin>>a[i];

    ll l=0;

    for(i=0;i<n;i++)
    {
        ll idx=upper_bound(b,b+l,a[i])-b;

       // for(j=0;j<l;j++) cout<<b[j]<<" ";
       // cout<<endl;



       // ll idx=lower_bound(b,b+l,a[i])-b;

        ///lower bound for strictly increasing

        f[i]=idx+1;

        l=max(l,idx+1);

        b[idx]=a[i];
    }

    ll lislen=l;

    cout<<"LIS "<<lislen<<endl;


    ll idx=l-1;

    for(i=n-1;i>=0;i--)
    {
        if(f[i]==l)
        {
            lis[idx--]=a[i];
            l--;
        }
    }

    for(i=0;i<lislen;i++) cout<<lis[i]<<" ";
    cout<<endl;





}

/*

8
4 5 6 6 2 3 4 6

8
0 8 4 12 2 3 4 5

*/




