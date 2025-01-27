#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,-1,sizeof(x))
const int INF = 1000000001;

int main(){
  char a[3][3];
  rep(i, 3){
    rep(j, 3){
      cin >> a[i][j];
    }
  }
  cout << a[0][0]<<a[1][1]<<a[2][2] <<endl;
}