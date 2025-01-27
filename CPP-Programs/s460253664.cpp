#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<bool> is_prime;

int main() {
    ll N;
    cin >> N;
    ll sup = pow(10, 6);
    is_prime.assign(sup + 1, true);
    for (ll i = 2; i <= sup; i++) {
        if (is_prime[i] == true) for (ll j = i * 2; j <= sup; j += i) {
            is_prime[j] = false;
        }
    }
    int cnt = 0;
    for (ll i = 2; i <= sup; i++) {
        if (is_prime[i]) {
            ll i_temp = i;
            while (N % i_temp == 0)
            {
                cnt++;
                N /= i_temp;
                i_temp *= i;
            }
            if (N <= i) break;
        }
    }
    if (N > sup) cnt++;

    cout << cnt << endl;
    return 0;
}