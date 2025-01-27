#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
#include<deque>
#include<cassert>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mod = 1000000007;
const int MAXV =  3502;

int main() {
  ll N;
  cin >> N;
  rep(n, MAXV) rep(h, MAXV) {
    if (n == 0 || h == 0) continue;
    if((4 * h * n - h * N - n * N) == 0) continue;
    ll denominator = (h * n * N);
    ll numerator = (4 * h * n - h * N - n * N);
    ll w = denominator / numerator;
    if (w <= 0 || (denominator % numerator)) continue;
    cout << n << " " << h <<" " << w << endl;;
    return 0;
  }

}