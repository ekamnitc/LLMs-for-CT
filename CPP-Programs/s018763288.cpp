/**
 *    author:  FromDihPout
 *    created: 2020-08-14
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> r1(n), r2(n);
    for (int i = 0; i < n; i++) {
        cin >> r1[i];
        r1[i] += r1[i-1];
    }
    for (int i = 0; i < n; i++) {
        cin >> r2[i];
    }
    for (int i = n-2; i >= 0; i--) {
        r2[i] += r2[i+1];
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, r1[i] + r2[i]);
    }
    cout << ans << '\n';
    return 0;
}