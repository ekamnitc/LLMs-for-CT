#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,b;
  cin >> N;
  map<int,int>a;
  for(int i=0;i<N;i++){
    cin >> b;
    a[b]++;
  }
  int ans=0;
  for(auto x:a){
    if(x.first!=x.second){
      if(x.first>x.second)
        ans+=x.second;
      else
        ans+=x.second-x.first;
    }
  }
  cout << ans << endl;
  return 0;
}