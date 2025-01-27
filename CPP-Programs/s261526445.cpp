#include <bits/stdc++.h>
using namespace std;

long lcd(long a,long b) {
  long c = __gcd(a,b);
  return (a * b)/ c ;
}

int main() {
  long A,B; cin >> A >> B;
  cout << lcd(A,B) << endl; 
}