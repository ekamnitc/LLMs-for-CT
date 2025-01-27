#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//---------------------------------------------------------------------------------------------------
ll MOD = 1000000007;
ll f[201010], rf[201010];
ll inv(ll x) {
    ll res = 1;
    ll k = MOD - 2;
    ll y = x;
    while (k) {
        if (k & 1) res = (res * y) % MOD;
        y = (y * y) % MOD;
        k /= 2;
    }
    return res;
}
void init() {
    f[0] = 1;
    for(int i = 1; i < 201010; i++) f[i] = (f[i - 1] * i) % MOD;
    for(int i = 0; i < 201010; i++) rf[i] = inv(f[i]);
}
ll C(int n, int k) {
    if(n < k) return 0;
    ll a = f[n]; // = n!
    ll b = rf[n-k]; // = (n-k)!
    ll c = rf[k]; // = k!

    ll bc = (b * c) % MOD;

    return (a * bc) % MOD;
}
//---------------------------------------------------------------------------------------------------
ll add(ll &a, ll b)
{
    a = (a+b) % MOD;
}
int main()
{
    init();
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> p(n+1);
    p[0] = 0, p[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        p[i] = p[i-1] + inv(i);
        add(p[i], MOD);
    }
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        ll v = p[i+1] + p[n-i] - 1;
        add(v, MOD);
        v = (v * a[i]) % MOD;
        add(ans, v);
    }
    for(int i = 2; i <= n; i++)
    {
        ans = ans * i % MOD;
    }
    cout << ans << endl;
}
