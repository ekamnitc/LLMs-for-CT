#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;

int main()
{
    int n, ans = 0;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    sort(p.rbegin(), p.rend());
    ans += p[0] / 2;
    for (int i = 1; i < n; i++) ans += p[i];
    cout << ans << endl;
    return 0;
}
