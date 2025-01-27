#include<iostream>
using namespace std;
int main () {
  long long X;
  cin >> X;
  long long mi = 0;
  long long ma = 1e5;
  while (mi != ma) {
    long long mu = (mi + ma) / 2;
    if (mu * mu > X) ma = mu;
    else mi = mu + 1;
  }
  mi --;
  cout << mi * mi << endl;
}
