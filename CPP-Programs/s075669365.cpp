#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,X;
  cin >> A >> B >> C >> X;
  int count = 0;
  int Y = X;
  
  for (int i = 0; i < A+1; i++) {
    
    if (Y - i * 500 >= 0) {
      Y = Y - i * 500;
      
      for (int j = 0; j < B+1; j++) {
        if (Y - j * 100 >= 0 && (Y - j * 100) / 50 <= C) {
          count++;
        }
      }
    }
    Y = X;
  }
  cout << count << endl;
}