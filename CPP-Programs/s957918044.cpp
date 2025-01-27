#include <bits/stdc++.h>
using namespace std;
 
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ", "; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ", "; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ", "; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ", "; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ", "; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ", "; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << ", " << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << ": " << v.second << ", "; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << ": " << v.second << ", "; os << "}"; return os; }
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (q < m) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
#define f first
#define s second
 
string genny(int a, int b) {
    int len = 0;
    int copy_a = a, copy_b = b;
    while(a > 0) {
        len++;
        a /= 10;
    }
    string ans = "";
    for(int i = 0; i < 6 - len; i++)
        ans += "0";
    ans += to_string(copy_a);
    len = 0;
    while(b > 0) {
        len++;
        b /= 10;
    }
    for(int i = 0; i < 6 - len; i++)
        ans += "0";
    ans += to_string(copy_b);
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int p, c;
    cin >> p >> c;
    vector<vector<pair<int, int>>> pre(p);
    vector<string> cities(c);
    for(int i = 0; i < c; i++) {
        int a, b;
        cin >> a >> b;
        pre[a - 1].push_back({b, i});
    }
    for(int i = 0; i < p; i++)
        sort(pre[i].begin(), pre[i].end());
    for(int i = 0; i < p; i++) {
        for(int j = 0; j < pre[i].size(); j++) {
            cities[pre[i][j].s] = genny(i + 1, j + 1);
        }
    }
    for(int i = 0; i < c; i++)
        cout << cities[i] << endl;
}

