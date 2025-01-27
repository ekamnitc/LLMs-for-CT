#include<bits/stdc++.h>
using namespace std;

int main(){
  int A, B, C;
  cin >> A >> B >> C;
  if(min(A, B)<C && C<max(A, B)){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}