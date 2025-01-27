#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cassert>
#include <queue>
#include <set>
#include <vector>
#include <cmath>
#include <bitset>
#include <functional>
#include <limits>
#include <map>
using namespace std;

typedef long long ll;
#define rep1(i, n) for(ll i = 1; i <=(ll)(n); i++)
#define rep0(i, n) for(ll i = 0; i <=(ll)(n); i++)

ll pow(ll a, ll n) { //compute a^n with o(logn)
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

ll pow(ll a, ll n, ll mod) { //compute a^n (mod mod) with o(logn)
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

const int MAX = 199;
const int MOD = 1000000007;
ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//順列計算
ll PER(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[n - k] % MOD) % MOD;
}
//f(L) = 全部の丸太を長さL以下にするときの最小切断回数
//二分探索でf(L) <= k となる最小のLを見つける
//O(Nlog(max(a_i)))
int main(){
    ll n, k;
    cin >> n >> k;
    ll amax = -1;
    ll a[n+1];
    rep1(i, n){
        cin >> a[i];
        amax = max(amax, a[i]);
    }
    ll l = 1;
    ll r = amax;
    while(l < r){
        ll tmp = (ll)floor((r-l)/2.0) + l;
        ll num = 0;
        rep1(i, n){
            num += max((ll)ceil((a[i]-tmp)/(double)tmp), (ll)0);
        }
        if(num < k) r = tmp;
        else if(num == k) r = tmp;
        else l = tmp + 1;
    }
    cout << r << endl;
    return 0;
}