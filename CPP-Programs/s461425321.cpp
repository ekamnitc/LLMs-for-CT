#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long mod = 1000000007LL;

bool isprime(int x) {
  int i;
  if(x < 2) return 0;
  else if(x == 2) return 1;
  if(x%2 == 0) return 0;
  for(i = 3; i*i <= x; i += 2) if(x%i == 0) return 0;
  return 1;
}

int main() {
  int n;
  cin >> n;
  vi v;
  for(int i = 2; i<=55555; i++) if(isprime(i) && i%5==1) v.push_back(i);
  rep(i,n) cout << v[i] << " ";
  cout << endl;
  return 0;
}