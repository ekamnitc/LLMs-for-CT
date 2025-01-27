#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B;
  cin >> A >> B;
  if(A >= 10) {
    cout << B << endl;
  }
  else {
    cout << B + 100 * (10 - A) << endl;
  }
}