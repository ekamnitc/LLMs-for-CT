#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(s) (int)s.size()

int main() {
    long long x;
    cin >> x;
    long long turn = 2 * (x / 11);
    x %= 11;
    if (x > 6) turn += 2;
    else if (x > 0) ++turn;
    cout << turn << endl;
}