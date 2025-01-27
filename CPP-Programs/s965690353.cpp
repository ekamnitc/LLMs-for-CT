#include <bits/stdc++.h>
#define ALL(v) v.begin(), v.end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
using namespace std;
typedef long long ll;
 
int main(){
  
  int k[4]={0,0,0,0};
  rep(i, 6){
    int p;
    cin>>p;
    if(p==1){
      k[0]++;}
    if(p==2){
      k[1]++;}
    if(p==3){
      k[2]++;}
    if(p==4){
      k[3]++;}
  }
  
  int p2=0;
  rep(i, 4){
  if(k[i]>=3||k[i]<=0){
    cout<<"NO"<<endl;
    return 0;}
    if(k[i]==2){
      p2++;}
  }
  
  if(p2==2){
    cout<<"YES"<<endl;}
  else{
    cout<<"NO"<<endl;}
  
  
 return 0;
}
