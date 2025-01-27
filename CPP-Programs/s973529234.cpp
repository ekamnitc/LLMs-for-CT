#include <bits/stdc++.h>
using namespace std;

// このコードでは活用していないが、
// (a+b)^2= (a-b)^2+ 4ab より
// sqrt(N)に近い約数のペアa,bがa+bを最小化する
int main(){
  int64_t N;
  cin >> N;

  int64_t ans= INT64_MAX;
  int64_t div= 1;
  while(div*div <= N){
    if(N% div==0){
      ans= min(ans, (div- 1)+(N/div- 1)); 
    }

    div++;
  }

  cout << ans << endl;
}