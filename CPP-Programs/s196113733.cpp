#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vecll vector<long long>
#define vec2ll vector<vector<long long>>
#define vecbool vector<bool>
#define vecpairll vector<pair<long long,long long>>
#define forll(s,a,b) for(long long s = a;s < b;s++)
#define forllde(s,a) for(long long s = a;s > 0;s--)


int main()
{
  ll n, p;
  string s, t;
  cin >> n >> s >> t;
  forll(i, 0, t.size()){
	if(t.substr(0, t.size()-i) == s.substr(i)){
	  p = i;
	  break;
	}
  }
  cout << s.size() + p << endl;
}
