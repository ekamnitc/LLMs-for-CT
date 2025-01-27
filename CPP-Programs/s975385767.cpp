#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N,C;
typedef pair<int, int> P;
vector<P> G[31]; 
int video[31][200003];

int main() {
  INCANT;
  cin >> N >> C;
  int s,t,c;
  rep(i, N) {
    cin >> s >> t >> c;
    G[c-1].push_back(P(s,t));
  }
  
  rep(c, C) {
    int tmp[200003];
    fill(tmp, tmp+200003, 0);
    for (auto p: G[c]) {
      tmp[p.first*2]++;
      tmp[p.second*2]--;
    }
    rep(j, 200001) {
      if (tmp[j]==1) {
        tmp[j-1]=1;
        tmp[j]=0;
      }
    }
    video[c][0] = tmp[0];
    rep(j, 200003) video[c][j+1] = video[c][j]+tmp[j+1];
  }
  int mx=0;
  rep(i, 200003) {
    int tmp=0;
    rep(c, C) tmp+=video[c][i];
    mx=max(mx, tmp);
  }
  cout << mx << endl;
  return 0;
}