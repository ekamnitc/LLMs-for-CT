#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, res = 0;
    int Z[5] = {{ }};
    cin >> A >> B;

    for (int i = A; i <= B; i++) {
        int tmp = i;
        for (int j = 0; j < 5; j++) {
            Z[j] = tmp % 10;
            tmp /= 10;
        }
        if (Z[0] == Z[4] && Z[1] == Z[3]) res++;
    }

    cout << res << endl;
}