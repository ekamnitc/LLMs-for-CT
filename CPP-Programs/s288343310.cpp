#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<vector<int>> C(3, vector<int>(3));
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      cin >> C.at(i).at(j);
    }
  }

  vector<int> A(3);
  vector<int> B(3);
  for(int i=0; i<3; i++){
    int it = min(C.at(i).at(0), C.at(i).at(1));
    A.at(i) = min(it, C.at(i).at(2));
  }
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      C.at(i).at(j) -= A.at(i);
    }
  }  
  for(int i=0; i<3; i++){
    int it = min(C.at(0).at(i), C.at(1).at(i));
    B.at(i) = min(it, C.at(2).at(i));
  }
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      C.at(i).at(j) -= B.at(j);
    }
  }

  int sum = 0;
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      sum += C.at(i).at(j);
    }
  }
  
  if(sum == 0){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}