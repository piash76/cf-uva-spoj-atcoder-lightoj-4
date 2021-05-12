
#include<bits/stdc++.h>
#define godspeed() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
using namespace std;

int main()
{
    godspeed()
    double s,theta,O,A;
    int i,ox,oy,ax,ay,bx,by,t;


    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>ox>>oy>>ax>>ay>>bx>>by;
        O=sqrt(((bx-ax)*(bx-ax)) + ((by-ay)*(by-ay)));
        A=sqrt(((ox-bx)*(ox-bx)) + ((oy-by)*(oy-by)));

        theta=acos(((A*A)+(A*A)-(O*O)) / (2.0*A*A));
        s=A*theta;

        printf("Case %d: %lf\n",i,s);
    }





}
