#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

const int mod = 1000000007;

int main() {
    int N; cin >> N;
    vector<ll> A(N);
    ll ans = 0;
    rep(i, N){
        cin >> A[i];
    }
    rep(i, 60){
        ll c1 = 0;
        rep(j, N){
            if(A[j]>>i&1){
                c1++;
            }
        }
        ll c0 = N - c1;
        ll cc = (c1*c0) % mod;
        ll p = pow(2, i);
        p %= mod;
        p = (cc * p) % mod;
        ans += p;
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}