/**
 *    author:  math2do
 *    created: 05.09.2020 12:49:26
**/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  } 
  vector <vector <long long> > dp(n, vector <long long>(n));
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i; j < n; j++) {
      if (i == j) {
        dp[i][j] = arr[i];
        continue;
      }     
      dp[i][j] = max(arr[i] - dp[i + 1][j], arr[j] - dp[i][j - 1]);
    } 
  } 
  cout << dp[0][n - 1] << endl;
  return 0;
}
