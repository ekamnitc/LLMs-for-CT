// https://www.youtube.com/watch?v=C5_NnCp1CRI
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#define int long long

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    if (n % 2)
        for (int l = 1, r = n - 1; l <= m; l++, r--) {
            cout << l << " " << r << endl;
        }
    else {
        bool flag = false;
        for (int l = 1, r = n - 1; l <= m; l++, r--) {
            if (!flag && r - l <= n / 2) {
                r--;
                flag = true;
            }
            cout << l << " " << r << endl;
        }
    }
}
