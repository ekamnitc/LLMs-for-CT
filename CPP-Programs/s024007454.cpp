#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N; cin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i], a[i] *= 2;

    long long off = 0;
    for (int i = 0; i < N; ++i) off = a[i] - off;
    long long x = off / 2;

    long long cur = x;
    for (int i = 0; i < N; ++i) {
        cout << cur << " ";
        cur = a[i] - cur;
    }
    cout << endl;
}