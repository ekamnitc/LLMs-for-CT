#include <iostream>
#define MAXN 305
using namespace std;

int n, a[MAXN][MAXN];
bool del[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            if (i == k)
                continue;

            for (int j = 1; j <= n; ++j) {
                if (j == k)
                    continue;

                if (a[i][k] + a[k][j] < a[i][j]) {
                    cout << "-1\n";
                    return 0;
                }
                if (a[i][k] + a[k][j] == a[i][j]) {
                    del[i][j] = 1;
                }
            }
        }
    }

    long long sol = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (!del[i][j])
                sol += a[i][j];

    cout << sol << "\n";

    return 0;
}