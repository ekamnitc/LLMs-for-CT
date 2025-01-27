#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  string s;
  cin >> s;
  if(s=="zyxwvutsrqponmlkjihgfedcba"){
    cout << -1 << endl;
  }else if(s.size()==26){
    int i=24,j;
    while(s.at(i)>s.at(i+1)){
      i--;
    }
    char m='z';
    for(j=i+1;j<26;j++){
      if(s.at(j)>s.at(i)){
        m=min(m,s.at(j));
      }
    }
    string t="";
    for(j=0;j<i;j++){
      t += s.at(j);
    }
    t += m;
    cout << t << endl;
  }else{
    vector<int> a(26,0);
    int i;
    for(i=0;i<s.size();i++){
      a.at(s.at(i)-'a')++;
    }
    i=0;
    while(a.at(i)==1){
      i++;
    }
    char m='a'+i;
    cout << s << m << endl;
  }
}