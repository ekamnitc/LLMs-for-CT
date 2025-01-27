#include <bits/stdc++.h>
using namespace std;

template <class t>
using vc = vector<t>;
template <class t>
using vvc = vector<vector<t>>;
typedef long long ll;
typedef vc<int> vi;
typedef vvc<int> vvi;
typedef pair<int, int> pi;

#define uset unordered_set
#define umap unordered_map

#define endl "\n"

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define bg begin()
#define ed end()

#define all(a) a.bg, a.ed

template <class t, class u>
ostream &operator<<(ostream &os, const pair<t, u> &p) {
    return os << "( " << p.first << ", " << p.second << " )";
}

template <class t>
ostream &operator<<(ostream &os, const vc<t> &v) {
    os << "[ ";
    for (int i = 0; i < v.size(); i++) {
        os << v[i];
        if (i != v.size() - 1) {
            os << ", ";
        }
    }
    return os << " ]";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cout << fixed << setprecision(18);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // Solution

    //

    string n;
    cin >> n;

    int digits = n.size();
    auto reworked = string(digits, '9');

    if (digits == 1) {
        cout << n;
        return 0;
    } else {
        bool all_nines = true;
        for (int i = 1; i < digits; i++) {
            all_nines = n[i] == '9';
        }
        if (all_nines) {
            reworked = n;
        }
    }

    if (n < reworked) {
        reworked[0] = n[0] - 1;
    }
    ll tot = 0;
    for (auto &c : reworked) {
        tot += c - '0';
    }
    cout << tot;
}
