#include <iostream>
#include <vector>
#include <algorithm>

const long long MOD = 1000000007;

int N, K;
std::vector<std::vector<int>> g;
std::vector<bool> check;

long long dfs(int u, int d) {
    long long res = 1;
    int color = std::max(0, K - std::min(2, d + 1)) % MOD;

    for (int v : g[u])
        if (!check[v]) {
            check[v] = true;
            res = res * (color * dfs(v, d + 1) % MOD) % MOD;
            color--;
        }

    return res;
}

int main() {
    std::cin >> N >> K;

    g.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        std::cin >> a >> b;

        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    check.resize(N);
    check[0] = true;

    std::cout << K * dfs(0, 0) % MOD << "\n";
}