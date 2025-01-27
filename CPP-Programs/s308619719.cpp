#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s.at(i);
    }
    cin >> m;
    vector<string> t(m);
    for (int i = 0; i < m; i++) {
        cin >> t.at(i);
    }
    int answer = 0;
    for (int i = 0; i < n; i++) {
        int score = 0;
        for (int j = 0; j < n; j++) {
            if (s.at(j) == s.at(i)) {
                score++;
            }
        }
        for (int j = 0; j < m; j++) {
            if (t.at(j) == s.at(i)) {
                score--;
            }
        }
        answer = max(answer, score);
    }
    cout << answer << endl;
}