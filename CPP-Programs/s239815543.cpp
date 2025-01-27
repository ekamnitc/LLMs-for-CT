#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

vector<int> v[15];

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    rep(a, 10){
        rep(b, 10){
            rep(c, 10){
                bool f1 = 0, f2 = 0, f3 = 0;
                int i = 0;
                while(i < n){
                    if (!f1) if(s[i]-'0'==a){
                        f1 = 1;
                        i++;
                    }
                    if (f1&&!f2) if(s[i]-'0'==b){
                        f2 = 1;
                        i++;
                    }
                    if (f1&&f2&&!f3) if(s[i]-'0'==c){
                        f3 = 1;
                        i++;
                    }
                    i++;
                }
                if (f1&&f2&&f3) ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
