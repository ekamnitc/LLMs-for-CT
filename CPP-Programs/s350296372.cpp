#include <bits/stdc++.h>
using namespace std;
int main(){
  long long x,N,sum=0;
  cin>>N>>x;
  vector<long long> a(N);
  for(int i=0;i<N;i++){
    cin>>a.at(i);
    sum+=a.at(i);
  }
  sort(a.begin(),a.end());
  int ans=0;
  if(sum==x){
    ans=N;
  }
  else if(sum<x){
    ans=N-1;
  }
  else{
    ans=N;
    while(x<sum){
      sum-=a.at(ans-1);
      ans--;
      if(ans==0)
        break;
   }
  }
  
  cout<<ans<<endl;
}
