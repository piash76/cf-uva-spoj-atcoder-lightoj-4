#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long N, f, i,c;



    while (cin>>N)
        {
            if(N==0) return 0;

        if (N < 0)
            N *= -1;

        f = -1;
        c = 0;

        for ( i = 2; i*i <= N && N != 1; i++) {
            while (N%i == 0){
                N /= i;
                f = i;
            }
            if (f == i){
                c++;
            }
        }


        if (N!=1 && f!=-1)
            f = N;
        else if(c == 1)
            f = -1;

        cout<<f<<endl;
     }


}
