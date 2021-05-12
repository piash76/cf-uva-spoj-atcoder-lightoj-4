#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,i,j,n,a[101],m,k;
    string s;

    cin>>t;
    getchar();
    while(t--)
    {
        getline(cin,s);
        stringstream x(s); //used to convert this string into int array
        j=0;
        while(x>>a[j]) //reading from stream
        {
            j++;
        }
        /*
        for(i=0;i<j;i++)
        {
            cout<<a[i]<<endl;
        }*/

        m=0;
        for(i=0;i<j;i++)
        {
            for(k=i+1;k<j;k++)
            {
              m=max(m,__gcd(a[i],a[k]));
            }
        }

        cout<<m<<endl;


    }

}

