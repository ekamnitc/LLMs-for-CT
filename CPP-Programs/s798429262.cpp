#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
#define rep(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
using namespace std;

int main() {
  string s;
  cin >> s;
  if(s[0] == '9' || s[1] == '9') cout << "Yes\n";
  else cout << " No\n";
}
