#include <bits/stdc++.h>
#define rep(a,n) for (int a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

int main(){
    int n;
    string t;
    cin >> n >> t;
    int ans = 0;
    rep(now,n){
        string s = t.substr(now);
        int l = s.size();
        vector<int>z(l);
        z[0]=l;
        int i = 1,j = 0;
        while(i<l){
            while(i+j < l && s[j] == s[i+j]) j++;
            z[i] = j;
            if(j == 0){
                i++;
                continue;
            }
            int k = 1;
            while(k < j && k+z[k] < j){
                z[i + k] = z[k];
                k++;
            }
            i += k;
            j -= k;
        }
        rep(i,l){
            if (i == 0)continue;
            chmax(ans,min(i,z[i]));
        }
    }
    cout << ans << endl;
    return 0;
}