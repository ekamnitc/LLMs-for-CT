#include <bits/stdc++.h>
#define rep(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define repr(i, n, m) for (int i = (int)(n) - 1; i >= (int)(m); i--)
using namespace std;
using ll = int64_t;
const int MOD = 1000000007; // 10^9+7
// https://atcoder.jp/contests/agc017/tasks/agc017_a

vector<ll> fac;
vector<ll> finv, inv; // いらないときはコメントアウト

// テーブルを作る前処理
void com_init(int maxK){
    fac.resize(maxK + 1);
    finv.resize(maxK + 1);
    inv.resize(maxK + 1);
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < maxK + 1; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll com(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    int n, p;
    cin >> n >> p;

    com_init(n);

    int even = 0; int odd = 0;
    rep(i, 0, n) {
        int a;
        cin >> a;
        if (a % 2 == 0) even++;
        else odd++;
    }

    ll evenNum = pow(2, even);
    ll oddNum0 = 0;
    ll oddNum1 = 0;
    rep(i, 0, odd  + 1) {
        if (i % 2 == 0) oddNum0 += com(odd, i);
        else oddNum1 += com(odd, i);
    }

    ll ans = (p == 0) ? evenNum * oddNum0 : evenNum * oddNum1;
    cout << ans << endl;

}
