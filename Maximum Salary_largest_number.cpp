

///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define ll long long
#define pll  pair<ll,ll>

#define ff    first
#define ss    second

#define  mp  make_pair
#define  pb  push_back

#define cy  cout<<"YES"<<endl
#define cn   cout<<"NO"<<endl


using namespace std;

const ll inf=1e18;
const int mod=1e9+7;
const int M=500005;


bool cmp(string &a,string &b)
{
    return a+b>b+a;  ///eta true hyle swap hbe na , naile swap hbe

}

bool fun(string &a,string &b)
{
    return a+b<b+a;
}

int main()
{




    ll t,i,j;
    ll n;cin>>n;
    vector<string> v;
    for(i=0;i<n;i++)
    {
        string st;cin>>st;
       v.push_back(st);
    }
    sort(v.begin(),v.end(),cmp);
  /* 	for ( i = 1; i < n; i++) {
		for ( j = 0; j < n - i; j++) {
			if (fun(v[j], v[j + 1])) {
				swap(v[j], v[j + 1]);
			}
		}
	}*/


    for(auto x:v) cout<<x;



    return 0;

}
/*

3
23 39 92

100
2 8 2 3 6 4 1 1 10 6 3 3 6 1 3 8 4 6 1 10 8 4 10 4 1 3 2 3 2 6 1 5 2 9 8 5 10 8 7 9 6 4 2 6 3 8 8 9 8 2 9 10 3 10 7 5 7 1 7 5 1 4 7 6 1 10 5 4 8 4 2 7 8 1 1 7 4 1 1 9 8 6 5 9 9 3 7 6 3 10 8 10 7 2 5 1 1 9 9 5

*/


