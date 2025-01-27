#include <iostream>
#include <vector>
#define rep(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> v(h+2, vector<char>(w+2,'.'));
  rep(i, 1, h+1) {
    rep(j, 1, w+1) {
      cin >> v[i][j];
    }
  }
  rep(i, 1, h+1) {
    rep(j, 1, w+1) {
      if(v[i][j] == '#') {
        if(!(v[i-1][j] == '#' || v[i][j-1] == '#' || v[i+1][j] == '#' || v[i][j+1] == '#')) {
          cout << "No\n";
          return 0;
        }
      }
    }
  }
  cout << "Yes\n";
  return 0;
}