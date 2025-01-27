#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int max = 2;
    while(max <= n) {
        max *= 2;
    };

    cout << max / 2 << endl;

    return 0;
}
