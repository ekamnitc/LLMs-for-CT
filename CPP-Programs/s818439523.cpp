#include <bits/stdc++.h>
using namespace std;

int main() {
  string c ;
  bool check = false ;
  cin >> c ;
  for ( int i = 0 ; i < c.size() ; i++ ){
    if (c.at(i)!='a' && c.at(i)!='i' && c.at(i)!='u' && c.at(i)!='e' && c.at(i)!='o' ){
      check = true ;
      break;
    }
  }
  if (check)
    cout << "consonant" << endl;
  else
    cout << "vowel" << endl;
    
}