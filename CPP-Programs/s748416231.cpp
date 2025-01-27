#include<iostream>
using namespace std;
int main(){
int n,a[1001],i;
  cin >> n;
  int ans=0;
  for(i=0;i<n;i++){
  cin >> a[i];
    if(a[i]%2 == 0){
    if(a[i]%3 != 0 && a[i]%5 != 0){
    ans++;
    }
    }
  }
  if(ans != 0){
  cout << "DENIED" << endl;
  }else{
  cout << "APPROVED" << endl;
  }
}