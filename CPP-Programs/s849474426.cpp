#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>


#define rep(i,n) for(int i = 0; i < n; ++i)
#define all(x) x.begin(),x.end()
using namespace std;

int main(void){
  string s;
  cin >> s;
  string t(s);
  reverse(all(t));

  for(int i = 0; i < t.size(); ++i){
    switch(t[i]){
      case 'p':
        t[i] = 'q';
        break;
      case 'q':
        t[i] = 'p';
        break;
      case 'd':
        t[i] = 'b';
        break;
      case 'b':
        t[i] = 'd';
        break;
    }
  }

  if( s == t){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}

