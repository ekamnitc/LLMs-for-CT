#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <functional>
using namespace std;


int main(){
  string s;
  cin >> s;
  int n = s.size() - 2;
  string c = to_string(n);
  cout << s[0] + c + s[s.size() - 1] << endl;
}