#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int x, a, b;
  string ans = "dangerous";
    cin >> x >> a >> b;
    if(b<=a) ans = "delicious";
    else if(b-a<=x) ans = "safe";
    cout << ans << endl;

}