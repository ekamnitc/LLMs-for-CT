#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a(3);
    for (int i = 0; i < 3; i++) cin >> a.at(i);
    vector<bool> odd(3, 0);
    int oddcount = 0;
    int res = 0;

    for (int i = 0; i < 3; i++) {
        if (a.at(i) % 2 != 0) {
            oddcount++;
            odd.at(i) = 1;
        }
    }

    if (oddcount == 0 || oddcount == 3) {
        sort(a.begin(),a.end());
        res = (a.at(2) * 2 - a.at(0) - a.at(1)) / 2;
    }
    else if (oddcount == 1) {
        for (int i = 0; i < 3; i++) {
            if (odd.at(i) == 0) a.at(i)++;
        }
        sort(a.begin(),a.end());
        res =(a.at(2) * 2 - a.at(0) - a.at(1)) / 2 + 1;
    }
    else {
        for (int i = 0; i < 3; i++) {
            if (odd.at(i) == 1) a.at(i)++;
        }
        sort(a.begin(),a.end());
        res =(a.at(2) * 2 - a.at(0) - a.at(1)) / 2 + 1;
    }
    cout << res << endl;
}
