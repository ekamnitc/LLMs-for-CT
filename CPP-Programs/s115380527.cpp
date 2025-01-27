#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

typedef long long llint;

const int mod = 998244353;
const int maxn = 300100;

llint  n, a, b;
llint k;

llint y;

llint rj = 0;

llint fakt[maxn];

llint pot(llint baza, llint eks)
{
    llint ret = 1;
    llint trbaza = baza;
    while(eks)
    {
        if(eks & 1)
        {
            ret *= trbaza;
            ret %= mod;
        }
        trbaza *= trbaza;
        trbaza %= mod;
        eks >>= 1;
    }
    return ret;
}

llint pov(llint apov, llint bpov)
{
    return fakt[apov] * pot(fakt[bpov] * fakt[apov - bpov] % mod, mod - 2) % mod;
}

int main()
{
    scanf("%lld%lld%lld%lld", &n, &a, &b, &k);
    fakt[0] = 1;
    REP(i, 1, maxn)
    {
        fakt[i] = fakt[i - 1] * i % mod;
    }
    REP(x, 0, n + 1)
    {
        if((k - x * a) % b == 0 && (k - x * a) / b >= 0)
        {
            y = (k - x * a) / b;
            if(x > n || y > n || y < 0) continue;
            rj += pov(n, x) * pov(n, y);
            rj %= mod;
        }
    }
    printf("%lld\n", rj);
    return 0;
}
