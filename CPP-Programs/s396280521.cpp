#include <bits/stdc++.h>
using namespace std;

int main(){

int N;
  cin >> N;
  
  vector<int> vec(N);
  for (int i=0; i<N; i++){
    cin >> vec.at(i);
  }
  
  sort(vec.begin(),vec.end());
  reverse(vec.begin(),vec.end());
  
  int alice, bob;
  alice = 0;
  bob = 0;
  
  for(int i=0; i<N; i++){
    alice += vec.at(i);
    i++;
    if(i == N){
      break;
    }
     else{
       bob += vec.at(i);
     }
}
  cout << alice - bob << endl;
}