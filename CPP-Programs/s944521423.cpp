#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define loop(i, a, n) for(int i = (a); i < (n); i++)
#ifdef _DEBUG
#define dd(x) cout << #x << " : " << x << endl
#else
#define dd(x)
#endif
using namespace std;
using ll = int64_t;

ll gcd(ll a, ll b){
    while(b != 0){
        ll c = a%b;
        a = b;
        b = c;
    }
    return a;
}

ll lcm(ll a, ll b){
    return a/gcd(a, b)*b;
}

ll nlcm(set<ll> a){
    ll res = *a.begin();
    for(ll num : a) res = lcm(res, num);
    return res;
}

int main(){
    ll n, m; cin >> n >> m;
    set<ll> a;
    rep(i, n) {
        ll tmp; cin >> tmp;
        a.insert(tmp/2);
    }

    ll min_a = *a.begin();
    ll two_pow = 1;
    while(min_a%2 == 0) {
        two_pow *= 2;
        min_a /= 2;
    }
    for(ll num : a) {
        ll tmp = num/two_pow;
        if(tmp%2 == 0 && tmp != 1) {
            cout << 0 << endl;
            return 0;
        }
    }

    ll base = nlcm(a);
    if(base > m) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = m/base;
    cout << ((ans & 1)?ans/2+1:ans/2) << endl;
    return 0;
}
