#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    string t = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'A') t = t + "A";
        else if (s.substr(i, 2) == "BC") {
                t = t + "D"; i++;
        }
        else t = t + s[i];
    }
    
    long long ans = 0;
    int a = 0;
    for (auto c : t) {
        if (c == 'A') a++;
        else if (c == 'D') ans += a; 
        else a = 0;
    }
    
    cout << ans << endl;
    return 0;
}