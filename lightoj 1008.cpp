
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{

    ll t,n,i,a,b,x,y,sq,sqn;

    cin>>t;

    for(i=1;i<=t;i++)
    {
        cin>>n;
         sq= ceil(sqrt(n));
        sqn = sq*sq- n;
        x=0,y=0;

        if(sqn< sq)
        {
            x= sqn + 1;
            y = sq;
        }
        else
        {
            x= sq;
            y = n - (sq - 1) * (sq - 1);
        }

        if(sq % 2 == 0)
        {
            swap(x,y);
        }
        cout << "Case " <<i<< ": ";
        cout <<x<< " " <<y<< endl;
    }

    return 0;

}
