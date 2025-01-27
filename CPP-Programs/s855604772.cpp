#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
#define FOR(i, m, n) for(ll i = m; i < (n); i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
using vi = vector<int>;
using vii = vector<vi>;
using pii = pair<int, int>; 
using vl = vector<ll>;
using vll = vector<vl>;
using pll = pair<ll, ll>;

int main() {
    ll N;
    cin >> N;
    vl H(N);
    rep(i, N){
        cin >> H[i];
    }
    ll ans = 0;
    rep(i, N){
        bool ok = true;
        rep(j, i){
            if(!(H[j] <= H[i])){
                ok = false;
                break;
            }
        }
        if(ok) ans++;
    }
    cout << ans;
}