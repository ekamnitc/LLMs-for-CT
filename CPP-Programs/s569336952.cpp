#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>

using namespace std;

typedef long long ll;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const vector<int> cost = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

vector<int> as;

// can_create[i][j] means j consisting of i numbers can create
vector<vector<bool>> can_create;
// vector<vector<ll>> dp;

int calc_expected_digits(const int N, const int M) {
    vector<int> memo(N + 1, -1);
    memo[0] = 0;
    for (int i = 0; i < M; i++) {
        const int a = as[i];
        for (int j = 0; j < N; j++) {
            if (j + cost[a]  > N) {
                continue;
            }
            if (memo[j] >= 0) {
                chmax(memo[j + cost[a]], memo[j] + 1);
            }
        }
    }

    return memo[N];
}

void calc_can_create(const int expected_digits, const int N) {
    can_create.resize(expected_digits + 1, vector<bool>(N + 1, false));
    can_create[0][0] = true;
    for (int i = 0; i < expected_digits; i++) {
        for (auto a : as) {
            for (int j = 0; j < N; j++) {
                if (j + cost[a] > N) {
                    continue;
                }
                if (can_create[i][j]) {
                    can_create[i + 1][j + cost[a]] = true;
                }
            }
        }
    }
}

int main(void) {
    int N, M;
    cin >> N >> M;

    as.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> as[i];
    }
    // sort by descending order
    sort(as.begin(), as.end());
    reverse(as.begin(), as.end());

    const int expected_digits = calc_expected_digits(N, M);
    calc_can_create(expected_digits, N);

#ifdef DEBUG
    printf("can_create: \n");
    for (auto row : can_create) {
        for (auto x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
#endif

    vector<int> ans;
    int n = N;
    for (int i = expected_digits; i > 0; i--) {
        for (auto a : as) {
            if (i > 1) {
                if (n - cost[a] > 0) {
                    if (can_create[i - 1][n - cost[a]]) {
                        ans.push_back(a);
                        n -= cost[a];
                        break;
                    }
                }
            } else {
                if (n - cost[a] == 0) {
                    if (can_create[i - 1][n - cost[a]]) {
                        ans.push_back(a);
                        n -= cost[a];
                        break;
                    }
                }
            }
        }
    }

    for (auto x : ans) {
        cout << x;
    }
    cout << endl;

    return 0;
}
