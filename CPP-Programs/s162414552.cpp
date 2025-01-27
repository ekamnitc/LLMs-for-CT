#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 1e15;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<int> &o) {
    ll a;
    in >> a;
    o.insert(a);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

struct Reach {
    int x, y, time;
};

int main() {
    int n;
    cin >> n;

    int xa = 0, bx = 0, ba = 0;
    int ans = 0;
    rep(i, n) {
        string s;
        cin >> s;
        rep(j, s.size() - 1) {
            if (s[j] == 'A' && s[j + 1] == 'B') ans++;
        }
        if (s.front() == 'B' && s.back() == 'A') ba++;
        else if (s.front() == 'B') bx++;
        else if (s.back() == 'A') xa++;
    }

    if (ba == 0) {
        int add = min(bx, xa);
        cout << ans + add << endl;
    } else {
        int add = ba - 1;
        if (xa > 0) {
            add++;
            xa--;
        }
        if (bx > 0) {
            add++;
            bx--;
        }
        add += min(bx, xa);
        cout << ans + add << endl;
    }


}