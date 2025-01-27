#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  for (int i=0;i<3;i++){
if(s.at(i)=='1'){s.at(i)='9';
                continue;}
    else if(s.at(i)=='9'){s.at(i)='1';
                         continue;}
  }
  cout<<s<<endl;
}
