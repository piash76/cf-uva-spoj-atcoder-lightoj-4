
#include<bits/stdc++.h>
#define godspeed() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
using namespace std;

int main()
{
    godspeed()
    int i,j,t;
    double r1,r2,r3,areat,c1,c2,c3,a,b,c,s,th1,th2,th3,tc,ans;
    cin>>t;
    for(i=1;i<=t;i++)
    {

    cin>>r1>>r2>>r3;
    a=r1+r2;
    b=r2+r3;
    c=r1+r3;
    th1=acos((a*a+c*c-b*b)/(2.0*a*c));
    th2=acos((a*a+b*b-c*c)/(2.0*a*b));
    th3=acos((c*c+b*b-a*a)/(2.0*b*c));

    //cout<<th1<<" "<<th2<<" "<<th3<<endl;
    c1=(r1*r1*th1)/2.0;
    c2=(r2*r2 *th2)/2.0;
    c3=(r3*r3*th3)/2.0;
    tc=c1+c2+c3;
    //cout<<tc<<endl;

    s=(a+b+c)/2;
    areat=sqrt(s*(s-a)*(s-b)*(s-c));
    //cout<<areat<<endl;

    ans=areat-tc;
    printf("Case %d: %.10lf\n",i,ans);
    }


}
