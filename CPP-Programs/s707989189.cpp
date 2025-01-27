#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

#define pb push_back
#define mp make_pair

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;
typedef long long ll;

int main() {
  string s, t;
  cin >> s >> t;

  string sr = s;

  bool ok = false;
  do {
    if (sr == t) {
      ok = true;
      break;
    }
    rotate(sr.begin(), sr.begin()+1, sr.end());
  } while (s != sr);

  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
