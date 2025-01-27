#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<pair<int, int>> wars;

int main() {
    cin >> N >> M;
    wars.resize(M);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        wars.at(i) = make_pair(a, b);
    }

    sort(wars.begin(), wars.end(), [](auto const &lhs, auto const &rhs) {
        return lhs.second < rhs.second;
    });

// i番目とi+1番目をかける橋
    int right_bridge = 0;
    int res = 0;

    for (auto &e: wars) {
        if (right_bridge < e.first || right_bridge >= e.second) {
            res++;
            right_bridge = e.second - 1;
        }
    }

    cout << res << endl;
}

    