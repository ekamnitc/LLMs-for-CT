#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long int ll;
#define MOD 1000000007
//#define MOD 998244353
#define N 100005
#define INF 1e18
#include <ctime>
#define rep(i, x, n) for (ll i = x; i < n; i++)
#define rev(i, n, x) for (ll i = n; i > x; i--)
#define all(c) (c).begin(), (c).end()
#define int long long int
#define endl "\n"
#ifdef mishra
#define debug(x) cout << " >> " << #x << ": " << x;
#define debugend() cout << endl;
#define print_time() cout << setprecision(6) << "time: " << (clock() - start) / (double)CLOCKS_PER_SEC << '\n';
#else
#define debug(x) ;
#define debugend() ;
#define print_time() ;
#endif

clock_t start;
void FAST(ll argc)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    start = clock();
    if (argc == 2)
        freopen("std.in", "r", stdin);
}

/*vector<ll> v;
void seive()
{
    v.pb(2);
    for (int i = 3; i < 100000; i += 2)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (i % v[j] == 0)
                break;
            if (v[j] * v[j] > i)
            {
                v.pb(i);
                break;
            }
        }
    }
}
/*
void prime_factor(ll x, vector<ll> &r)
{
    ll sqrt_x = sqrt(x);

    for (ll i : v)
    {
        if (i > sqrt_x)
            break;

        if (x % i == 0)
            r.pb(i);

        while (x % i == 0)
        {
            x /= i;
        }
    }

    if (x >= 2)
        r.pb(x);
}
*/
/*
ll power(ll x, ll y)
{
    ll res = 1;
    x = x % MOD;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}
*/
/*
inline void dfs(ll curr, ll prev)
{

    for (ll i : a[curr])
        if (i != prev)
            dfs(i, curr);
}
*/
/*
ll multi(ll a, ll b)
{
    return ((a * b) % MOD);
}
*/
//---------------------CODE STARTS HERE---------------------

signed main(char argc, char *argv[])
{
    FAST(argc);

    ll testcase = 1;
    //cin >> testcase;

    while (testcase--)
    {
        double n;
        cin >> n;
        vector<vector<vector<double>>> dp;
        dp.resize(n + 1, vector<vector<double>>(n + 1, vector<double>(n + 1)));
        int a[3] = {0};
        rep(i, 0, n)
        {
            int x;
            cin >> x;
            a[x - 1]++;
        }
        rep(i, 0, n + 1)
        {
            rep(j, 0, n + 1)
            {
                rep(k, 0, n + 1)
                {
                    dp[i][j][k] = 0;
                    if ((i + j + k) == 0 || (i + j + k) > n)
                        continue;
                    if (k > 0)
                        dp[i][j][k] += dp[i][j][k - 1] * k;
                    if (j > 0)
                        dp[i][j][k] += dp[i][j - 1][k + 1] * j;
                    if (i > 0)
                        dp[i][j][k] += dp[i - 1][j + 1][k] * i;
                    dp[i][j][k] += n;
                    dp[i][j][k] /= (i + j + k);
                }
            }
        }
        cout << setprecision(30)<<dp[a[2]][a[1]][a[0]] << endl;

        //--------??--------CLEAR VECTORS--------??--------
    }

    //v.clear();
    print_time();
    return 0;
}