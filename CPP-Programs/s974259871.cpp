#include<iostream>
#include<vector>
using namespace std;
int main(){
  int x,a,b,c,n,f,I;
  vector<int> y;
  int dam;
  while(1){
    I=0;
    f=0;
    y.clear();
    cin >> n >> a >> b >> c >> x;
    if(n==0&&a==0&&b==0&&c==0&&x==0)break;
    for(int i=0;i<n;i++){
      cin >> dam;
      y.push_back(dam);
    }
    while(1){
      if(y[I]==x){
	I++;
	if(I==n){
	  cout << f << endl;
	  break;
	}
      }
      x=(a*x+b)%c;
      f++;
      if(f==10001){
	cout << -1 << endl;
	break;
      }
    }
  }
  return 0;
}
  