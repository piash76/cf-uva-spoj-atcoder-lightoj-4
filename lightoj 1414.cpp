
#include<bits/stdc++.h>
#define godspeed() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
using namespace std;
map<string,int> mp;
string mon[]={"January",
 "February", "March", "April",
  "May", "June", "July", "August",
   "September", "October", "November",
   "December"};
int main()
{
    godspeed()
    int t,i,j,d1,d2,s,y1,y2,x,y;
    string m1,m2;
    char ch;
    for(i=0;i<12;i++)
    {

    mp[mon[i]]=i;
    }

    cin >>t;
    for(i=1;i<=t;i++)
    {

        cin>>m1>>d1>>ch>>y1;
        cin>>m2>>d2>>ch>>y2;
        if(mp[m1]>1)
        {
            y1++;
        }
        if(mp[m2]==0 || (mp[m2]==1 && d2<29))
        {
            y2--;
        }
        //cout<<y1<<" "<<y2<<endl;
        s= y2/4 - (y1-1)/4;
         s-= y2/100 - (y1-1)/100;
        s += y2/400 - (y1-1)/400;


        printf("Case %d: %d\n",i,s);
    }
    return 0;
}
