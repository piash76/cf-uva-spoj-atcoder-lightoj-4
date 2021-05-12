#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,n,k,s,q;
    cin>>q;
    while(q--)
    {
        s=0;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n,greater<int>());
        for(i=0;i<n;i++)
        {

            if(a[i]<=s)
            {
                break;
            }
            s++;
        }
        cout<<s<<endl;
    }

}
