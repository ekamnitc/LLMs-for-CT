#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define All(a) a.begin(),a.end()
#define INF 1000000007
const ll MOD = 1000000007;
//accumulate(vec.begin(), vec.end(), 0)
//std::sort(v.begin(), v.end(), std::greater<Type>());
//set_intersection(x, x+7, y, y+6, back_inserter(v));
//set_union(x, x+7, y, y+6, back_inserter(v));
//set_difference(x, x+7, y, y+6, back_inserter(v));

int gcd(int x,int y){
  if(x%y==0) return y;
  else return gcd(y,x%y);
}

bool isPrime(int n){
  if(n < 2) return false;
  else if(n == 2) return true;
  else if(n%2==0) return false;

  for(int i=3;i<=sqrt(n);i++){
    if(n%i==0) return false;
  }
  return true;
}


int main(){
  int n;
  cin >> n;
  map<int,int>A;
  bool flag = true;
  ll ans = 1;
  for(int i=0;i<n;i++){
    int a;cin>>a;
    A[a]++;
  }
  if(n%2==0){
    for(int i=1;i<n;i+=2){
      if(A[i]!=2){
        flag = false;
        break;
      }
      ans *= 2,ans %=MOD;
    }
  }
  else{
    if(A[0]!=1) flag = false;
    for(int i=2;i<n;i+=2){
      if(A[i]!=2){
        flag = false;
        break;
      }
      ans *= 2,ans %=MOD;
    }
  }
  if(flag) cout<< ans <<endl;
  else cout<< 0 <<endl;

}
