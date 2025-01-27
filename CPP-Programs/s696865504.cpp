#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,sum=0,ans;cin>>N;
  for(int i=1;;i++){
    sum+=i;
    if(sum>=N){
      ans=i;
      break;
    }
  }
  cout<<ans<<endl;
}