///Bismillahir Rahmanir Rahim
///ALLAHU AKBAR
#include<bits/stdc++.h>




using namespace std;
#define ll long long


//ll a[maxn];

char grid[205][205];
ll costj[205][205],costf[205][205];
bool visj[205][205],visf[205][205];

int main()
{


    ll i,j,k,t,cas=0;

    scanf("%lld",&t);
    while(t--)
    {


        ll n,m;
        scanf("%lld %lld",&n,&m);



        queue<pair<ll,ll> > qj,qf;
        vector<pair<ll,ll> >fire;


         ll x1,x2,y1,y2;
        for(i=0;i<n;i++)
        {
            char s[m+5];
            scanf("%s",s);
            for(j=0;j<m;j++)
            {
                grid[i][j]=s[j];


                costj[i][j]=costf[i][j]=1e18;
                visj[i][j]=visf[i][j]=false;

                if(grid[i][j]=='J') {x1=i,y1=j;}
                if(grid[i][j]=='F')
                {
                   fire.push_back({i,j});
                }
            }

        }

       /* for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++) cout<<grid[i][j];
            cout<<endl;
        }*/

        for(auto x:fire)
        {
            ll id1=x.first;
            ll id2=x.second;

            costf[id1][id2]=0;
            qf.push({id1,id2});
            visf[id1][id2]=true;
        }



        const int dx[]={+1,-1,+0,+0};
        const int dy[]={+0,+0,+1,-1};


    while(!qf.empty())
    {
        ll uxf=qf.front().first;
        ll uyf=qf.front().second;
        qf.pop();



    for(i=0;i<4;i++)
    {
        ll vxf=uxf+dx[i];
        ll vyf=uyf+dy[i];


     if (vxf>=0 and vxf<n and vyf>=0 and vyf<m and visf[vxf][vyf]==false and grid[vxf][vyf]!='#' and costf[vxf][vyf]>costf[uxf][uyf]+1)
        {
            costf[vxf][vyf]=costf[uxf][uyf]+1;
            visf[vxf][vyf]=true;
            qf.push({vxf,vyf});

        }

    }



   }

   qj.push({x1,y1});
   visj[x1][y1]=true;
   costj[x1][y1]=0;


    while(!qj.empty())
    {
        ll uxj=qj.front().first;
        ll uyj=qj.front().second;
        qj.pop();
        //cout<<"uxj "<<uxj<<endl;
        //cout<<"uyj "<<uyj<<endl;



    for(i=0;i<4;i++)
    {
        ll vxj=uxj+dx[i];
        ll vyj=uyj+dy[i];
       // cout<<"before"<<endl;
       // cout<<"vxj "<<vxj<<" vyj "<<vyj<<endl;
       // cout<<"costj[uxj][uyj] "<<costj[uxj][uyj]<<endl;
       // cout<<"costj[vxj][vyj] "<<costj[vxj][vyj]<<endl;
       // cout<<"costf[vxj][vyj] "<<costf[vxj][vyj]<<endl;


     if (vxj>=0 and vxj<n and vyj>=0 and vyj<m and visj[vxj][vyj]==false and grid[vxj][vyj]=='.' and min(costj[vxj][vyj],costj[uxj][uyj]+1)<costf[vxj][vyj])
        {
           // cout<<"after"<<endl;
            //cout<<"vxj "<<vxj<<" vyj "<<vyj<<endl;
            costj[vxj][vyj]=min(costj[vxj][vyj],costj[uxj][uyj]+1);
            visj[vxj][vyj]=true;
            qj.push({vxj,vyj});

        }

    }



   }


       /*cout<<"costf"<<endl;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cout<<costf[i][j]<<" ";
            }
            cout<<endl;
        }*/


       /* cout<<"cost1"<<endl;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cout<<cost1[i][j]<<" ";
            }
            cout<<endl;
        }*/





      ll ans=1e18;
      for(i=0;i<m;i++)
      {
            ans=min(ans,costj[0][i]);
            ans=min(ans,costj[n-1][i]);

      }

      for(i=0;i<n;i++)
      {
       ans=min(ans,costj[i][0]);
        ans=min(ans,costj[i][m-1]);

      }



      printf("Case %lld: ",++cas);
      if(ans!=1e18) printf("%lld\n",ans+1);
     else printf("IMPOSSIBLE\n");






    }




}

