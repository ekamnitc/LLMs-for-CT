#include <bits/stdc++.h>
using namespace std;
 
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    cin >> s;
    
    if (s[0] == s[s.size()-1]) {
    	cout << (s.size()&1 ? "Second" : "First") << '\n';
    }
    else {
    	cout << (s.size()&1 ? "First" : "Second") << '\n';
    }
   	
    return 0;
}