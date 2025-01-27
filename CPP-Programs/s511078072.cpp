#include <bits/stdc++.h>
using namespace std;

int main() {
  
  //x匹 y足
  int x, y;
  cin >> x >> y;
  
  int ans = 0;
  
  for (int i = 0; i <= x; i++){
    
    int a, b;
    a = 4 * i;
    b = 2 * (x - i);
    int t;
    t = a + b;
    
    if (y  == t){
      ans = ans + 1;
    }
    
  }
  
  if (ans > 0){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  
  
}
