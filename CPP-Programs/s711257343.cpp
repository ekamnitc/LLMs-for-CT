#include <bits/stdc++.h>
using namespace std;

int main(){
  int M,D;
  cin >> M >> D;
  
  int count=0;
  for(int m=1; m<=M; m++){
    for(int d=1; d<=D; d++){
      if(d>=10&&d/10>=2&&d%10>=2&&(d/10)*(d%10)==m) count++;
    }
  }
  cout << count << endl;
}