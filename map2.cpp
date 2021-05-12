
#include <bits/stdc++.h>
using namespace std;

int main()
{

    cout<<"MAP "<<endl;
    map<int,int> m;

    m[3]=2; ///initializing m
    m[1]=4; ///cant initialize m[1]=4,m[1]=5

    ///map will be like this
    ///m[1]=4;
    ///m[3]=2;
    /// auto matically sorted(ascending) by key

    for(auto x: m)
    {
        cout<<"KEY VALUE OF MAP m "<<x.first<<endl<<"ELEMENT VALUE OF MAP m  "<<x.second<<endl;
    }

}
