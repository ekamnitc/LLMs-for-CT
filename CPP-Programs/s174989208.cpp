#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;

int main()
{
  string s; cin >> s;
  bool a=false, b=false, c=false, d=false;
  for (auto v:s) {
    if (v == 'N') a = true;
    if (v == 'S') b = true;
    if (v == 'E') c = true;
    if (v == 'W') d = true;
  }
  if (!(a^b) && !(c^d)) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
