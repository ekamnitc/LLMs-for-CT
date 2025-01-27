#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <cmath>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int mod=1e9+7;

int main() {
  double a,b,x;
  cin>>a>>b>>x;
  double S=x/a;
  double deg=0;
  if(S>=a*b/2){
    double t=2*(a*b-S)/a;
    deg=atan2(t,a);
  }
  else{
    double t=2*S/b;
    deg=atan2(b,t);
  }
  double PI=acos(-1);
  double ans=deg/PI*180;
  cout<<fixed<<setprecision(10)<<ans<<endl;
  return 0;  
}