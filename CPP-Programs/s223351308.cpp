#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  if(n % 2 == 1) {
    cout << "No" << endl;
  } else {
    string s;
    cin >> s;
    string sf = s.substr(0, n / 2);
    string sb = s.substr(n / 2 , n / 2);
    cout << (sf == sb ? "Yes" : "No") << endl;
  }
}