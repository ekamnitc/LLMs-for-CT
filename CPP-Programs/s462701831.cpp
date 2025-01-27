#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <cmath>
#define ll long long
#define lli long long int

using namespace std;
using P = pair<int,int>;

int main(){

  int N;
  cin >> N;
  int ans = 0;

  for (int i = 1; i <= N; i++) {
    if(i < 10){ //9
      ans++;
    }else if(i > 99 && i < 1000){ // 100 - 999
      ans++;
    }else if(i > 9999 && i < 100000){ // 10000 - 99999
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}