#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,y,w,u,v;
  cin>>x>>y;
  vector<int> z(x);
  for(w=0;w<y;w++){
    cin>>u>>v;
    u--;v--;
    z[u]++;
    z[v]++;
  }
  for(w=0;w<x;w++) cout<<z[w]<<endl;
}