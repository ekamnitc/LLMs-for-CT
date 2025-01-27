#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int x;
  cin >> x;
  int fine;
  
  int a = x / 500;
  fine = 1000 * a;
  x = x % 500;
  int b = x / 5;
  fine = fine + 5 * b;
  cout << fine << endl;
  
  
}

