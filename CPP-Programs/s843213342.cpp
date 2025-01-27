#include <bits/stdc++.h>
using namespace std;

int main() {
  // 入力整数
  double a = 0;
  double b = 0;
  
  // 整数を入力
  cin >> a >> b;
  
  // 平均値を計算
  double avg = (a + b) / 2;
  
  // 切り上げをするため、0.5を足す
  int answer = avg + 0.5;
  
  // 答え
  cout << answer << endl;
}