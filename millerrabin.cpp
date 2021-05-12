
///https://cp-algorithms.com/algebra/primality_tests.html
///https://www.hackerearth.com/practice/math/number-theory/primality-tests/tutorial/
///https://www.youtube.com/watch?v=qdylJqXCDGs
///https://www.youtube.com/watch?v=0NXcD5mpoUg


#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define maxn 100005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
using u64 = uint64_t;
using u128 = __uint128_t;


///O(log(d))

///returns /* Calculate ( a^b ) %c */
u64 binpower(u64 base, u64 e, u64 mod)
{
    u64 result = 1;
    base %= mod;
    while(e){
        if(e & 1)
            result = (u128) result * base % mod;
        base = (u128) base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_compsite(u64 n, u64 a,u64 d,  int s)
{
    u64 x = binpower(a, d, n);
    if(x == 1 || x == n - 1)  ///this is prime
        return false;
    for(int r = 1; r < s; r++)
    {
        x = (u128)x * x % n;
        if(x == n - 1)        ///this is prime
            return false;
    }
    return true;
};

bool MillerRabin(u64 n) // returns true if n is probably prime, else returns false.
{
    if(n%2==0) return false;

    if(n < 2)
        return false;

    int s = 0;
    u64 d = n - 1;

     ///d=2^s * d
    ///where if d is odd

    while((d & 1) == 0)
    {
        d >>= 1;
        s++;
    }

   /// 2, 325, 9375, 28178, 450775, 9780504, 1795265022

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_compsite(n, a, d, s))
            return false;
    }
    return true;
}


int main()
{
    FASTIO

    u64 n;
    int T;
    cin >> T;
    while(T--){
    cin >> n;
    if(MillerRabin(n)) cout << "YES\n";
    else cout << "NO\n";
}

    return 0;
}

/*

2920910506223

*/
