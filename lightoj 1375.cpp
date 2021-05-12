

#include<bits/stdc++.h>

using namespace std;
#define ULL unsigned long long

///https://forthright48.com/spoj-lcmsum-lcm-sum
///http://lightoj.com/volume_showproblem.php?problem=1375
/*

unsigned long long allPairLcm( int n ) {
    unsigned long long res = 0;
    for( int i = 1; i <= n; i++ )
        for( int j = i + 1; j <= n; j++ )
            res += lcm(i, j); // lcm means least common multiple
    return res;
}
*/


const int M= 3000010 ;
int phi[M];
ULL sum[M];
///log(log(N))
void calculatePhi()
{
    for(int i=1; i<=M; i++)
        phi[i] = i;

    for(int i =2; i<=M; i++)
    {
        if(phi[i]==i)
        {
            for(int j=i; j<=M; j+=i)
                phi[j]-=phi[j]/i;
        }
    }

    for (int i = 2; i <= M; i++)
		for (int j = i; j <= M; j += i)
			sum[j] += phi[i] * 1ULL * i/ 2 * j;
	for (int i = 2; i <= M; i++)
		sum[i] += sum[i - 1];

}

int main()
{
   // flash()
    calculatePhi();

    int t,cas=0;

   scanf("%d",&t);
    while(t--)
    {
       int n;
        scanf("%d",&n);


        ULL ans=sum[n];

        printf("Case %d: ",++cas);

        printf("%llu\n",ans);




    }


}


