#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,H,W,h,w,count=0;cin>>N>>H>>W;
  for(int i=0;i<N;i++){
    cin>>h>>w;
    if(H<=h && W<=w)count++;
  }
  cout<<count<<endl;
}