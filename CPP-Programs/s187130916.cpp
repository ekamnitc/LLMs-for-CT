#include <bits/stdc++.h>
#define vsort(v) sort(v.begin(), v.end())
#define rvsort(v) sort(v.begin(), v.end(), greater<ll>())
#define vfind(v, target) find(v.begin(), v.end(), target)
#define notFound(v, target) (vfind(v, target) == v.end())
#define maxIndex(v) max_element(v.begin(), v.end()) - v.begin()
#define maxElement(v) *max_element(v.begin(), v.end())
#define minIndex(v) min_element(v.begin(), v.end()) - v.begin()
#define minElement(v) *min_element(v.begin(), v.end())
#define ll long long
#define rep(i, s, g) for (ll i = (s); i < (g); i++)
#define MOD 1000000007
using namespace std;

int main()
{
  ll N; cin >> N;
  vector<pair<ll, ll>> X(N);
  vector<ll> med(N);
  rep(i, 0, N) {
  	ll a; cin >> a;
    X[i] = make_pair(a, i);
  }
  vsort(X);
  rep(i, 0, N) {
  	if (i < N / 2) {
    	med[X[i].second] = X[N / 2].first;
    } else {
    	med[X[i].second] = X[N / 2 - 1].first;
    }
  }
  rep(i, 0, N) {
  	cout << med[i] << endl;
  }
}