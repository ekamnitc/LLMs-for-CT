#include <bits/stdc++.h>
using namespace std;
long long sum[200001] = {};

int main() {
    int N; cin >> N;
    vector<int> C(N);
    for(int i=0; i<N; ++i) cin >> C[i];
    C.erase(unique(begin(C), end(C)), end(C));

    const long long MOD = 1000000007;
    sum[C[0]] = 1;
    for(int i=1; i<C.size(); ++i) {
        sum[C[i]] = (sum[C[i]] + sum[C[i - 1]]) % MOD;
    }
    cout << sum[*rbegin(C)] << endl;
}