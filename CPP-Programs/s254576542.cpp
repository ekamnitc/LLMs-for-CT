#include <bits/stdc++.h>
using namespace std;

int main() {
  int A[101];
    for (int i=0 ; i<101 ;i++){
      A[i]=0 ;
    }
  int a ,b , c ;
  cin >> a >> b >> c ;
  A[a] = 1;
  A[b] =1 ;
  A[c]=1;
  int count =0;
  for (int i=0 ; i<101 ;i++){
    if ( A[i]==1){
      count++;
    }
  }
    cout << count << endl;
}