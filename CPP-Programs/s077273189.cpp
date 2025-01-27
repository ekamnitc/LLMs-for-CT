#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,L; cin >> N >> L;
  vector<string> mojiretu(N);
  for(int i = 0; i < N; i++)
    cin >> mojiretu.at(i);
  
  sort(mojiretu.begin(),mojiretu.end());
  string ans;
  ans = mojiretu.at(0);
  for(int i = 1; i < N;i++)
    ans = ans + mojiretu.at(i);
  
  cout << ans <<endl;
}