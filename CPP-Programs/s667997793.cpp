#include <bits/stdc++.h>

#include <fstream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  /*
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  //*/
  string S;
  cin >> S;
  int red = 0, blue = 0;
  for(int i = 0; i < S.size(); i++){
    if(S[i] == '0'){
      red++;
    } else{
      blue++;
    }
  }
  cout << min(red, blue) * 2<<endl;
}
