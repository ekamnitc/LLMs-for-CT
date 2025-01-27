#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool Check(string t){
    
    int t_len = t.size();
    vector<char> tt{};

    for(int i=0;i<t_len;i++){
        if(t[i] != 'A') tt.push_back(t[i]);
        else{
            if(i != t_len-1 && t[i+1] == 'A') return false;
            if(i-1 >= 0 && t[i-1] == 'I') return false;
            if(i+1 < t_len-1 && t[i+1] == 'I') return false;
        }
    }
    
    string s="";
    for(int i=0;i<tt.size();i++) s+=tt[i];
    if(s == "KIHBR") return true;
    else return false;
}

int main(){
   
  string t; cin >> t;
  if(t.size() > 9){
      cout << "NO" << endl;
  }
  else{
      if(Check(t)) cout << "YES" << endl;
      else cout << "NO" << endl;
  }
}