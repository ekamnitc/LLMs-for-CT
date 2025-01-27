#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  int count=0;
  for(int i=0; i<S.size(); i++){
    if(i%2==0&&(S.at(i)=='R'||S.at(i)=='U'||S.at(i)=='D')){
      count++;
    }
    else if(i%2!=0&&(S.at(i)=='L'||S.at(i)=='U'||S.at(i)=='D')){
      count++;
    }
  }
  cout<<(count==S.size()?"Yes":"No")<<endl;
}