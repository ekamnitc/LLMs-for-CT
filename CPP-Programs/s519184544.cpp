#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin>>N>>M;
  
  vector<int> vec(N,-1);
  
  for(int i=0;i<M;i++){
    int s,c;
    cin>>s>>c;
    if(vec.at(s-1)!=-1){
      if(vec.at(s-1)==c) vec.at(s-1)=c;
      else{
        cout<<-1<<endl;
        return 0;
      }
    }
    else vec.at(s-1)=c;
  }
  if(N==1){
    if(vec.at(0)==-1) cout<<0<<endl;
    else cout<<vec.at(0)<<endl;
  }
  else{
    if(vec.at(0)==-1) cout<<1;
    else if(vec.at(0)==0) {
      cout<<-1<<endl;
      return 0;
    }
    else cout<<vec.at(0);
    for(int i=1;i<N;i++){
      if(vec.at(i)==-1) cout<<0;
      else cout<<vec.at(i);
    }
    cout<<endl;
  }
  
  
}