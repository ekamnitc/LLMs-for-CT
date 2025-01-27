#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n, q;
    string s;
    cin >> n >> s >> q;
    for (int z = 0; z < q; z++) {
        int k;
        cin >> k;
        lint ans = 0;
        lint m = 0, c = 0, mc = 0;
        //区間を[l,r)で管理
        int l = 0, r = 0;
        while (l != n) {
            if (r >= k) {
                if (s[l] == 'M') {
                    m--;
                    mc -= c;
                }
                if (s[l] == 'C') {
                    c--;
                }
                l++;
            }
            if (r < n) {
                r++;
                if (s[r - 1] == 'C') {
                    c++;
                    mc += m;
                }
                if (s[r - 1] == 'M') {
                    m++;
                }
            }
            if (r >= k && s[l] == 'D') {
                ans += mc;
            }
        }
        cout << ans << endl;
    }
}