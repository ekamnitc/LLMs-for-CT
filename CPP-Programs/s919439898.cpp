#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M,X;cin>>N>>M>>X;
  vector<vector<int>>V(N,vector<int>(M));
  vector<int>D(N);
  for(int L=0;L<N;L++){
    cin>>D[L];
    for(int R=0;R<M;R++){
      cin>>V[L][R];
    }
  }
  int P=10000000;bool bre=false;
  for (int bit = 0; bit < (1 << N); bit++) {
    long long sum = 0;bool K=true;
    vector<int>E(M);
    for (int i = 0; i < N; i++) {
      if ((bit>>i)&1){
        sum += D[i];
        for(int L=0;L<M;L++)E[L]+=V[i][L];
      }
    }
    for(int L=0;L<M;L++){
      if(E[L]<X){
        K=false;break;
      }
    }
    if(K&&P>sum){
      P=sum;bre=true;
    }
  }
  if(bre)cout<<P<<endl;
  else cout<<-1<<endl;
}
