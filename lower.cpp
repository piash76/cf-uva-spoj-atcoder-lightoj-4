#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,c=1,i;
    cin>>n;
    long long a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(i=0;i<n-1;i++)
    {
        if(a[i]<a[i+1])
        {
            break;
        }
        c++;
    }
    cout<<c<<endl;
}
