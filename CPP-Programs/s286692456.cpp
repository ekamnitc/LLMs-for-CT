#include <iostream>
using namespace std;
#define N (123456*2+1)

int main(){
  bool isP[N];
  int k[N];

  for( int i=0;i<N;i++ )
    isP[i]=true;
  isP[0]=false;  isP[1]=false;
  k[0]=0;  k[1]=0;
  for( int i=2;i<N;i++ ){
    k[i]=k[i-1];
    if( !isP[i] ) continue;
    k[i]++;
    for( int j=2*i;j<N;j+=i )
      isP[j] = false;
  }

  int n;
  while( cin>>n && n )
    cout << (k[2*n]-k[n]) << endl;

  return 0;
}