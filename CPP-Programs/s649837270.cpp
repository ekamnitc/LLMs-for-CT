//
// Created by Huang,Zhiqiang on 2018/6/24.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

ll k;

ll getdigitsum(ll n) {
    ll ans = 0;
    while (n) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int main() {
    cin >> k;
    ll cur = 1;
    while(k--) {
        cout << cur << endl;
        ll t = -1;
        for (ll i = 1; i <= 1000000000000000; i *= 10) {
            if (t == -1 || t * getdigitsum(cur + i) > (cur + i) * getdigitsum(t))
                t = cur + i;
        }
        cur = t;
    }
}