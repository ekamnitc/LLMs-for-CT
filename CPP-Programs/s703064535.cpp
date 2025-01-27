#include <bits/stdc++.h>

using namespace std;


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int k;
    cin >> k;
    int cur = 7 % k;
    for (int i = 0; i < 3 * k; ++i) {
        if(!cur) {
            cout << i + 1;
            return 0;
        }
        cur = (cur * 10 + 7) % k;
    }
    cout << "-1";

}