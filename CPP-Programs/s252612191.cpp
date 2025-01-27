#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int N, T; cin >> N >> T;
    vector<int> a(N);
    for (int& ai : a) cin >> ai;
    vector<int> rangeMin(N);
    rangeMin[0] = a[0];
    for (int i = 1; i < N; i++) {
        rangeMin[i] = min(rangeMin[i - 1], a[i]);
    }
    map<int, int> cnt;
    for (int i = 1; i < N; i++) {
        cnt[a[i] - rangeMin[i - 1]]++;
    }
    cout << (--cnt.end())->second << endl;
    return 0;
}