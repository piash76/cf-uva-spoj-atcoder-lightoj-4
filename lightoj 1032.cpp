


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

ll ar[35],br[35];
ll n;
ll dp[35][35][3][2]; ///pos sum prev flag

void bin(ll num)
{

    ll idx=1;
    while(num)
    {
       br[idx++]=(num%2);
        num/=2;
    }
    n=idx-1;

    ll idx2=n;
    for(ll i=1;i<=n;i++)
    {
        ar[i]=br[idx2--];
    }
}



ll solve(ll pos,ll sum,ll last,bool flag)
{
    if(pos>n) return sum;

    if(dp[pos][sum][last][flag]!=-1) return dp[pos][sum][last][flag];

    ll lim=1;
    if(!flag) lim=ar[pos];

    ll s=0;

    for(ll i=0;i<=lim;i++)
    {
        if(flag or i<lim)
        {
            if(i==1 and last==1)
            {
                s+=solve(pos+1,sum+1,i,true);
            }
            else
            {
                s+=solve(pos+1,sum,i,true);
            }
        }
        else
        {
            if(i==1 and last==1)
            {
                s+=solve(pos+1,sum+1,i,false);
            }
            else
            {
                s+=solve(pos+1,sum,i,false);
            }
        }
    }


    return dp[pos][sum][last][flag]=s;

}

int main()
{



    ll t,i,j,cas=0;
    scanf("%lld",&t);

    while(t--)
    {
        ll num;scanf("%lld",&num);

        bin(num);




        memset(dp,-1,sizeof(dp));
        ll ans=solve(0,0,0,false);


        printf("Case %lld: ",++cas);
        printf("%lld\n",ans);






    }

    return 0;

}





