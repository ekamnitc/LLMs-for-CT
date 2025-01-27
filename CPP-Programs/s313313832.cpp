#include <stdio.h>
#include <iostream>
// #include <math.h>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>

//#include <bits/stdc++.h>
using namespace std;
#define print(x) cout<<(x)<<endl
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long int
#define pb push_back

int main() {
  int a, b;
  cin >> a >> b;
  if(a+b >= 24) print(a+b-24);
  else print(a+b);
}
