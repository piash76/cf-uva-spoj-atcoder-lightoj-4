///Bismillahir Rahmanir Rahim
///ALLAHU AKBAR
#include<bits/stdc++.h>

//Datatypes
#define ll                      long long
using namespace std;



int amar_ceil(int x,int y)
{
    return (x+y-1)/y;
}



int hp[16],dp[1<<16+5];
int w[16][16];
int n;


int to_set(int n,int i) ///set the ith bit
{
    return n|=(1<<i);
}
int to_reset(int n,int i)
{
    return n&=~(1<<i);
}
///ith bit is set or not
bool is_on(int n,int i)
{
    return n&(1<<i);

}


int solve(int mask)
{
    if(mask==(1<<n)-1) return 0;
    if(dp[mask]!=-1) return dp[mask];

    int mnans=1e9;
    for(int i=0;i<n;i++)
    {

        if(!(mask&(1<<i)))   ///searching for alive targets
        {

            // cout<<"ALIVE "<<i<<endl;

            int best_weapon_dam=1e9;

            for(int j=0;j<n;j++)  ///searching for best weapon for maximum damage of dead targets
            {
                if(mask&(1<<j))   ///searching for dead targets to use that weapon
                {

                    if(w[j][i]!=0) best_weapon_dam=min(best_weapon_dam,amar_ceil(hp[i],w[j][i]));


                }
            }


            if(best_weapon_dam==1e9) best_weapon_dam=hp[i];   ///if no weapon found with dam >0 then have to kill with .45
           // cout<<"BESt "<<best_weapon_dam<<endl;

           //ll nxt=solve(to_set(mask,i));
           //cout<<"NEXT "<<nxt<<endl;

           // int x=best_weapon_dam+solve(mask|(1<<i));

            //cout<<"X if he kills i "<<x<<endl;

            mnans=min(mnans,best_weapon_dam+solve(mask|(1<<i)));
           // cout<<"MN "<<mnans<<endl;

        }


    }


    return dp[mask]=mnans;




}


int main()
{


    int i,j,k,t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&hp[i]);

        for(i=0;i<n;i++)
        {
            char s[20];
            scanf("%s",s);
            for(j=0;j<n;j++)
            {
                w[i][j]=s[j]-'0';

            }
        }

        int ans=1e9,msk=0;
       // cout<<to_set(msk,0)<<endl;
        for(i=0;i<n;i++)
        {
            //cout<<"START with I "<<i<<endl;

            ans=min(ans,hp[i]+solve(to_set(msk,i))); ///starting killing ith target with .45
        }


    printf("Case %d: %d\n",++cas,ans);


    }

}







/*

4
3

3 5 7

030

500

007

*/



