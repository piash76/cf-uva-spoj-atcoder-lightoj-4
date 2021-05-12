#include<cstdio>
#include<iostream>
#include<sstream>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<ctime>
#include<vector>
#include<fstream>
#include<list>
using namespace std;

#define ms(s) memset(s,0,sizeof(s))
typedef unsigned long long ULL;
typedef long long LL;

const int INF = 0x3fffffff;

const int N = 10000000;
bool primeTable[N+5];

void make_primeTable(){
    fill(primeTable,primeTable+N,1);
    primeTable[0] = false;
    primeTable[1] = false;

    int maxed = sqrt(N);
    for(int i = 2; i <= maxed; ++i){
        if(primeTable[i]){
            for(int j = i*i; j <= N; j += i)
                primeTable[j] = false;
        }
    }
}
const int maxn = 10000000;
const int mod = 100000007;
long long phi[maxn+5];
void phi_table(){
    memset(phi,0,sizeof(phi));
    phi[1] = phi[2] = 1;
    for(int i = 3; i <= maxn; ++i){
        if(primeTable[i] == true)
            phi[i] = (i-1)*phi[i-1]%mod;
        else
            phi[i] = i*phi[i-1]%mod;
    }
}

int main(){
//    freopen("F:\\input.txt","r",stdin);
//    freopen("F:\\output.txt","w",stdout);
//    ios::sync_with_stdio(false);

    make_primeTable();
    phi_table();
    int n,m;
    LL ans;
   // cout<<phi[4]<<endl;
    while((~scanf("%d%d",&n,&m)) && n){

        ans = phi[m];
        for(int i = n; i > m; --i){
            ans = ans*(LL)i%100000007LL;
        }
        printf("%lld\n",ans-1);
    }

    return 0;
}



