#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

int main() {
    int n, k; cin >> n >> k;
    vint v(n);
    rep(i,n) cin >> v[i];
    vint v_sort = v;
    sort(all(v_sort));
    vint x_accu(n+1,0), y_accu(n+1,0);
    REP(i,n+1) {
        x_accu[i] = x_accu[i-1]+v[i-1];
        y_accu[i] = y_accu[i-1]+v[n-i];
    }
    int ans = 0;
    for (int x = 0; x <= k; x++) {
        for (int y = 0; y <= k; y++) {
            if (x+y > k) continue;
            int rev = k-(x+y);
            int sum = 0;
            vint tmp;
            if (x+y >= n) {
                sum += x_accu[n];    
                rep(i,min(rev,n)) {
                    if (v_sort[i] < 0) sum -= v_sort[i];
                }
            }
            else {
                sum += x_accu[x]+y_accu[y];
                rep(i,x) tmp.push_back(v[i]);
                rep(i,y) tmp.push_back(v[n-i-1]);
                sort(all(tmp));
                int tmp_n = tmp.size();
                rep(i,min(rev,tmp_n)) {
                    if (tmp[i] < 0) sum -= tmp[i];
                }
            }
            ans = max(ans,sum);
        }
    }
    cout << ans << endl;
}