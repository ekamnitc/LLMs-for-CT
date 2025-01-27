#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<char> c;
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0' || s[i] == '1') {
            c.push_back(s[i]);
        } else if (s[i] == 'B') {
            if (c.empty() != true) c.pop_back();
        }
    }
    for (int i = 0; i < c.size(); i++) {
        cout << c[i];
    }
    cout << endl;
}
