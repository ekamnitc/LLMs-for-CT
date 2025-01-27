#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m,a,b;
  cin >> n >> m;
  vector<int>ball(n,1);
  vector<bool>red(n,false);
  red.at(0)=true;
  for(int i=0;i<m;i++){
    cin >> a >> b;
    a--,b--;
    ball.at(a)--;
    ball.at(b)++;
    if(red.at(a))
      red.at(b)=true;
    if(ball.at(a)==0)
      red.at(a)=false;
  }
  int ans=0;
  for(int i=0;i<n;i++)
    if(red.at(i)) ans++;
  cout << ans << endl;
  return 0;
}