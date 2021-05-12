#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,i,j,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);

        for(i=0;i<n;i++)
        {
            if(i%2==0)
            {
                cout<<a[i]<<" ";
            }
        }
        cout<<endl;
    }


}
