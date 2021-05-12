




///PROBLEM DESCRIPTION:


#include<bits/stdc++.h>

#define speed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);



#define ll long long
#define cy  cout<<"YES"<<endl
#define cn   cout<<"NO"<<endl


using namespace std;




const int mod = 1000000007;


const int maxn =1000005;///1e6
ll a[maxn];


int main()
{


    speed()



    ll t,i,j,cas=0;
    cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        map<ll,ll> m;

        for(i=0;i<n;i++) { cin>>a[i];m[a[i]]++; }
        sort(a,a+n);

        //for(i=0;i<n;i++) cout<<a[i]<<" ";
        //cout<<endl;

        ll c=0;
        for(i=n-1;i>=0;i--)
        {
            if(m[a[i]])
            {
                ll x=a[i];
                ll cnt=0;
                while(1)
                {
                   // cout<<"X "<<x<<endl;
                    if(x%2) break;

                    x/=2;
                    if(m[x]) m.erase(x);
                    cnt++;
                }

                //cout<<"CNT "<<cnt<<endl;


                m.erase(a[i]);
                c+=cnt;

               // cout<<endl;
            }
        }

        cout<<c<<endl;




    ///printf("Case %lld: ",++cas);
    /// cout<<"Case "<<++cas<<": "<<s<<endl;
    }

}




