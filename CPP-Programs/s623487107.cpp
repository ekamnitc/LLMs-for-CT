#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 

signed main(void){ 
  
  int N; cin >> N;
  vector<int> A(N); 
  
  int sum = 0;
  
  for(int i = 0; i < N; i++){ 
    cin >> A[i]; sum += A[i];
  }
  
  int res = ( N*(N+1) )/2;
  
  if( sum % res != 0 ){ cout << "NO" << endl; return 0;}
  
  int m = sum/res; //全体の操作回数
  
  vector<int> delta(N);
  
  for(int i = 0; i < N; i++){ 
    if( i == N-1 ){ delta[N-1] = A[0]-A[N-1];} // N-1の次は0だから
    else{ delta[i] = A[i+1]-A[i];}
  }
  
  int test = 0;
  
  for(int i = 0; i < N; i++){ 
    if( (m-delta[i]) % N == 0 && m-delta[i] >= 0 ){ 
      test +=  (m-delta[i])/N; //これだけの回数iから足す操作を行う
    }
    else{ 
      cout << "NO" << endl; return 0;
    }
  }
  
  if( test != m ){ cout<< "NO" << endl; return 0;}
  
  cout << "YES" << endl;
  
  return 0;
} 