
#include<bits/stdc++.h>
#define godspeed() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
using namespace std;

int main()
{
    godspeed()
    ll t,i,j,n,x,ans;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>n;
        string s="";
        while(n)
        {
            if(n%2)
            {
                s+='1';
            }
            else
            {
                s+='0';
            }
            n/=2;
        }
        s+='0';
        reverse(s.begin(),s.end());
        next_permutation(s.begin(),s.end());
        reverse(s.begin(),s.end());
        //cout<<s<<endl;
        x=1,ans=0;
        for(j=0;j<s.size();j++)
        {
            if(s[j]=='1')
            {

            ans+=x;

            }
            x*=2;
        }
        printf("Case %lld: %lld\n",i,ans);
    }
}
