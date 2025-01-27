#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); ++i) {
        int l1 = s[i] - 'A';
        int l2 = s[i] - 'a';
        if (l1<26 && l1>=0) { cout<<(char)(l1 + 97); }
        else if (l2<26 && l2>=0) { cout<<(char)(l2 + 65); }
        else { cout<<s[i]; }
    }
    cout<<"\n";
    return 0;
}

