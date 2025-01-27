#include <bits/stdc++.h>
using namespace std;

int main() {
    // input
    int N;
    cin >> N;
    vector<pair<long long, long long>> ranges(N);
    for (int i = 0; i < N; i++) {
        long long x, l;
        cin >> x >> l;
        // right
        ranges.at(i).first = x + l;
        // left
        ranges.at(i).second = x - l;
    }

    // sort
    sort(ranges.begin(), ranges.end());

    // count
    int count = 0;
    long long current = -1000000000;

    for(int i = 0; i < N; i++) {
        if(current <= ranges.at(i).second) {
            count++;
            current = ranges.at(i).first;
        }
    }

    cout << count << endl;

    return 0;
}