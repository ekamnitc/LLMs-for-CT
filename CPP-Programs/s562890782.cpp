#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

bool isSameDigits(int x) {
    string S = to_string(x);
    bool isSame = false;
    if (S.at(0) == S.at(1) && S.at(1) == S.at(2)) isSame = true;
    return isSame;
}

int main() {
    int N;
    cin >> N;

    int ans;
    for (int i = N; i <= 999; i++) {
        if (isSameDigits(i)) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
