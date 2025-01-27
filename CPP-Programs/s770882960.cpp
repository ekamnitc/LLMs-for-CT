#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> nums(105, -1);
    vector<pair<string, int>> v(N, pair<string, int>());
    rep(i, N) {
        string s;
        int n;
        cin >> s >> n;
        v[i] = {s, n};
        nums[n] = i + 1;
    }

    sort(all(v), [](pair<string, int> a, pair<string, int> b) {
        if (a.first == b.first)
            return a.second > b.second;
        else
            return a.first < b.first;
    });
    rep(i, N) { cout << nums[v[i].second] << endl; }
}