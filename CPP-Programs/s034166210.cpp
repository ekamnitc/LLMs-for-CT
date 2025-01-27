#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define MOD 1000000007LL

#define rep(i, n) for(ll (i) = 0LL;(i) < (ll)(n);(i)++)
#define rep2(i, s, e) for(ll (i) = (ll)(s);(i) < (ll)(e);(i)++)
#define repi(i, n) for(ll (i) = 0LL;(i) <= (ll)(n);(i)++)
#define repi2(i, s, e) for(ll (i) = (ll)(s);(i) <= (ll)(e);(i)++)
#define per(i, n) for(ll (i) = (ll)(n) - 1LL;(i) >= 0LL;(i)--)
#define per2(i, s, e) for(ll (i) = (ll)(s) - 1LL;(i) >= (ll)(e);(i)--)
#define peri(i, n) for(ll (i) = (ll)(n);(i) >= 0LL;(i)--)
#define peri2(i, s, e) for(ll (i) = (ll)(s);(i) >= (ll)(e);(i)--)
#define iter(i, it) for(auto &(i): (it))

template<typename T, typename U> ostream& operator<<(ostream &s, const pair<T, U> m) {
    cout << "(" << m.first << ", " << m.second << ")";
    return s;
}
template<typename T, typename U> ostream& operator<<(ostream &s, const map<T, U> m) {
    ll c = 0;
    cout << "{ ";
    iter(i, m) cout << i << (c++ == m.size() - 1 ? " " : ", ");
    cout << "}";
    return s;
}
template<typename T> ostream& operator<<(ostream &s, const vector<T> &v) {
    cout << "{ ";
    rep(i, v.size()) cout << v[i] << (i == v.size() - 1 ? " " : ", ");
    cout << "}";
    return s;
}
template<typename T> ostream& operator<<(ostream &s, const list<T> &v) {
    ll c = 0;
    cout << "{ ";
    iter(i, v) cout << i << (c++ == v.size() - 1 ? " " : ", ");
    cout << "}";
    return s;
}

ll po(ll x, ll y) {
    ll ans = 1;
    while(y) {
        if(y % 2) (ans *= x) %= MOD;
        (x *= x) %= MOD;
        y >>= 1;
    }
    return ans;
}

ll fact(ll x) {
    ll ans = 1;
    repi2(i, 2, x) (ans *= i) %= MOD;
    return ans;
}

ll gyakugen(ll x) {
    return po(x, MOD - 2);
}

map<ll, pair<ll, ll>> mae;

void prepare() {
    repi(i, 2000) {
        ll temp = fact(i);
        ll gyaku = gyakugen(temp);
        mae[i] = pair<ll, ll>{temp, gyaku};
    }
}

ll comb(ll n, ll r) {
    return mae[n].first * mae[r].second % MOD * mae[n - r].second % MOD;
}

int main(void) {
    prepare();
    ll N, K;
    cin >> N >> K;
    repi2(i, 1, K) cout << comb(N - K + 1, i) * comb(K - 1, i - 1) % MOD << endl;
    return 0;
}
