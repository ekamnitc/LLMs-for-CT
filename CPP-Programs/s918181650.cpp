#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// namespace mp = boost::multiprecision;
// using Bint = mp::cpp_int;
// using Real = mp::number<mp::cpp_dec_float<1024>>;

int main(){
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N);
    rep(i, N) cin >> A.at(i);
    rep(i, N) cin >> B.at(i);
    rep(i, N) cin >> C.at(i);
    sort(all(A));
    sort(all(C));
    A.push_back(INF);
    C.push_back(INF);

    ll ans = 0;
    rep(i, N){
        int b = B.at(i);
        ll an = lower_bound(all(A), b) - A.begin();
        ll cn = C.end() - upper_bound(all(C), b) - 1;
        ans += an * cn;
    }
    cout << ans << endl;
}