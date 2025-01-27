#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
    int n,x,p=0;
    cin >> n >> x;
    vector<int>sq(n);
    rep(i, n)cin >> sq[i];
    vector<int>point;
    point.push_back(0);
    for (int i = 0; i < n; i++) {
        p = point[i] + sq[i];
        if (p <= x)point.push_back(p);
        else break;

    }
    cout << point.size() << endl;
    return 0;
}