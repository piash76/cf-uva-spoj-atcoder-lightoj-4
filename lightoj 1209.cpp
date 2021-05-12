///https://blog.csdn.net/neko01/article/details/19649255?fbclid=IwAR2yEA_3ll2e_8KuJF6qiVkJ4JR-ZgM-JWv1R9OEqDk_-8vXiGuCTXylw88

///Total voter - maximum no of unsatisfied voter
///which can be found by doing bpm
///by constructing graph where each edge is constructed by contradiction (unsatisfied) of choice

///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define ll long long
#define pll  pair<ll,ll>
#define ff    first
#define ss    second

using namespace std;

const int M=505;

ll Match[M],vis[M];
ll n,m;

struct info
{
    string like,dislike;
};

info MALE[M],FEMALE[M];  ///choices of male and female voter

vector<ll> g[M];



bool kuhn(ll u) ///u= left side candidate
{
    for(auto v:g[u])
    {
        if(vis[v]==0)
        {
            vis[v]=1;

            if(Match[v]==-1 or kuhn(Match[v]))
            {
                Match[v]=u;
                return true;
            }
        }
    }

    return false;

}


ll bpm()
{
    memset(Match,-1,sizeof(Match));

    ll match=0;
    for(ll i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        if(kuhn(i)) match++;
    }

    return match;
}

int main()
{



    ll t,i,j,cas=0;
    scanf("%lld",&t);
    while(t--)
    {
        for(i=0;i<M;i++) g[i].clear();

        n=m=0;

        ll male_candidate,female_candidate,tot;scanf("%lld %lld %lld",&male_candidate,&female_candidate,&tot);


       string a,b;

        for(i=1;i<=tot;i++)
        {

           cin>>a>>b;

            if(a[0]=='M')   ///male voter
            {
                n++;
                MALE[n].like=a;
                MALE[n].dislike=b;



            }
            else  ///female voter
            {
                m++;
                FEMALE[m].like=a;
                FEMALE[m].dislike=b;


            }

        }

        /*cout<<"MALE "<<endl;
        for(i=1;i<=n;i++) cout<<MALE[i].like<<" "<<MALE[i].dislike<<endl;

        cout<<"FEMALE "<<endl;
        for(i=1;i<=m;i++) cout<<FEMALE[i].like<<" "<<FEMALE[i].dislike<<endl;*/

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(MALE[i].like==FEMALE[j].dislike or MALE[i].dislike==FEMALE[j].like)
                {
                    g[i].push_back(j);
                }
            }

        }

        ll ans=tot-bpm();

        printf("Case %lld: %lld\n",++cas,ans);





    }

    return 0;

}



