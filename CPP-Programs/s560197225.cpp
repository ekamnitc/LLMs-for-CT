#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <cassert>
#include <random>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const ll INF = 10000000000;
const double PI = acos(-1);
const ll mod = 1000000007;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> a_sorted(n);
    rep(i, n) {
        cin >> a[i];
        a_sorted[i] = a[i];
    }

    sort(a_sorted.rbegin(), a_sorted.rend());
    int first_max = a_sorted[0];
    int second_max = a_sorted[1];
    rep(i, n) {
        if (a[i] == first_max) {
            cout << second_max << endl;
        }
        else {
            cout << first_max << endl;
        }
    }
    return 0;
}
