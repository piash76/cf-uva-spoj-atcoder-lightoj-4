
#include<bits/stdc++.h>

#define ll long long
using namespace std;

int main()
{

     ll t,s1,s2,l1,l2;

    cin>>t;
    getchar();

    string a,b;

    for(ll j= 1; j<= t; j++)
    {
       a.clear(),b.clear();
       getline(cin, a);
       getline(cin, b);
       s1 = 0,s2 = 0;
       l1 = a.size(), l2 = b.size();


       for(ll i = 0;i<l1; i++ )
        {
           a[i] = tolower(a[i]);
           if(a[i]!=' ') s1 += a[i];
       }

       for(ll i = 0; i<l2; i++ )
        {
           b[i] = tolower(b[i]);
           if(b[i]!=' ') s2 += b[i];
       }

       if(s1==s2) printf("Case %lld: Yes\n",j);
       else printf("Case %lld: No\n",j);

    }



    return 0;
}
