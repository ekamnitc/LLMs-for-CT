#include<bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  vector<long> a(n);
  int ans = 0;
  int key = 1;
  bool flag = false;
  for(int i = 0; i < n; i++){
    cin >> a.at(i);
  }
  for(int i = 0; i < n; i++){
    if(a.at(i) != key) ans++;
    else{
      key++;
      flag = true;
    }
  }
  if(flag)
    cout << ans;
  else
    cout << -1;
}