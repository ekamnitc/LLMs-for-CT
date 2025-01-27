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

char get_best_action(char tc) {
    if(tc == 'r') {
        return 'p';
    } else if(tc == 's') {
        return 'r';
    } else {
        return 's';
    }
}

int main(){
    int n, k; cin >> n >> k;
    int r, s, p; cin >> r >> s >> p;
    string t; cin >> t;

    string h = "";
    int ans = 0;
    int tsize = t.size();
    rep(i, tsize) {
        char tc = get_best_action(t[i]);
        if(i < k) {
            h += tc;
            if(tc == 'p') ans += p;
            else if(tc == 's') ans += s;
            else ans += r;
        } else {
            if(h[i-k] == tc) {
                if(i+k < tsize) {
                    char tc2 = get_best_action(t[i+k]);
                    if(tc == 'p' && tc2 == 'p') h += 's';
                    else if(tc == 'p' && tc2 == 'r') h += 's';
                    else if(tc == 'p' && tc2 == 's') h += 'r';
                    else if(tc == 's' && tc2 == 's') h += 'r';
                    else if(tc == 's' && tc2 == 'r') h += 'p';
                    else if(tc == 's' && tc2 == 'p') h += 'r';
                    else if(tc == 'r' && tc2 == 'r') h += 'p';
                    else if(tc == 'r' && tc2 == 'p') h += 's';
                    else if(tc == 'r' && tc2 == 's') h += 'p';
                } else {
                    if(tc == 'p') h += 's';
                    else if(tc == 's') h += 'r';
                    else h += 'p';
                }
            } else {
                h += tc;
                if(tc == 'p') ans += p;
                else if(tc == 's') ans += s;
                else ans += r;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
