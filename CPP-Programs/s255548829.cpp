#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N;
  string S;
  cin>>N>>S;
  int64_t r=0;
  int64_t g=0;
  int64_t b=0;
  for(int i=0;i<N;i++){
    if(S.at(i)=='R') r++;
    else if(S.at(i)=='G') g++;
    else b++;
  }
  int64_t moto=r*g*b;
  int64_t gen=0;
  for(int i=0;i<N;i++){
    int j=1;
    while(i+2*j<N){
      if(S.at(i)!=S.at(i+j)&&S.at(i)!=S.at(i+2*j)&&S.at(i+j)!=S.at(i+2*j)) gen++;
      j++;
    }
  }
  cout<<moto-gen<<endl;
      
      
  
  
}