

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


map<string,vector<string>> m;

string khuj(string s)
{


    for(auto x:m)
    {
        //cout<<x.ff<<endl;
        for(auto st:x.ss)
        {
            if(st==s) return x.ff;
        }

    }

    return "-1";




}


int main()
{


    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);



    ll t,i,j;

    ll n;cin>>n;



    for(i=1;i<=n;i++)
    {
        char s[500];
        gets(s);
        //cout<<s<<endl;

        ll l=strlen(s),cnt=1;

        string st="",mp;
        for(j=0;j<l;j++)
        {
            if(s[j]==' ')
            {
                //cout<<st<<" ";
                if(cnt==1)
                {
                    mp=st;
                }
                else
                {
                   // cout<<st<<" ";
                    m[mp].push_back(st);

                }
                st="";
                cnt++;
            }
            else
            {
                st+=s[j];
            }


        }

        //cout<<endl;

        m[mp].push_back(st);

        //cout<<st<<endl;

    }

    /*for(auto x:m)
    {
        cout<<x.ff<<endl;
        for(auto st:x.ss)
        {
            cout<<st<<endl;
        }
        cout<<endl;
    }
    cout<<endl;*/


    getchar();

    map<ll,string> ans;

   // char q[500];
   string q;

    ll idx=1;

    //for(i=1;i<=2;i++)
    while(getline(cin,q))
    {

       //gets(q);
        ll l=q.size();

        bool f=false;

        string st="";
        for(j=0;j<l;j++)
        {
            if(q[j]==' ')
            {
                string str=khuj(st);
                if(str!="-1")
                {
                    cout<<str<<endl;
                   // ans[idx]=str;
                    //idx++;
                    f=true;break;
                }

                st="";

            }
            else
            {
                st+=q[j];
            }

        }

        if(!f)
        {
           string str1=khuj(st);
                if(str1!="-1")
                {
                    cout<<str1<<endl;
                    //ans[idx]=str1;
                    //idx++;

                }
        }





    }

    //for(auto x:ans) cout<<x.ss<<endl;





    return 0;

}


/*

4
Vulcan throks kilko-srashiv k’etwel
Romulan Tehca uckwazta Uhn Neemasta
Menk e’satta prah ra’sata
Russian sluchilos

Dif-tor heh, Spohkh. I’tah trai k’etwel
Uhn kan’aganna! Tehca zuhn ruga’noktan!
*/





