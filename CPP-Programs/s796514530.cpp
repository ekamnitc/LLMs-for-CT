#include <bits/stdc++.h>
using namespace std;

int main() {
  int K;
  cin >> K;
  int A = 0;
  
  for (int i = 1; i <= K; i++) {
    for (int j = 1; j <= K; j++) {
      for (int k = 1; k <= K; k++) {
        int B = min(i,j);
        B = min(B,k);
        for (int l = B; l >= 1; l--) {
          if (i%l == 0 && j%l == 0 && k%l == 0){
            A += l;
            break;
          }
        }
      }
    }
  }
  cout << A << endl;
}
    