#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> vec(N), mochi(N,0);
   for (int i = 0; i < N; i++) {
     cin >> vec.at(i);
   }
  int x = 0;
   for (int i = 0; i < N; i++) {
     int a = 0;
     int b = vec.at(i);
     int c = i;
      for (int i = 0; i < N; i++) {
        if (i == c)
          break;
        if(vec.at(i) == b && mochi.at(i) == 0){
          mochi.at(i) = 1;
        }      
      }
      for (int i = 0; i < N; i++) {
        if(mochi.at(i) == 0)
          a ++;
      }
     x = a;
   }
  cout << x << endl;
}