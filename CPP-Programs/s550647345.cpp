// https://leetcode.com/problems/count-complete-tree-nodes/
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

	
	string s; cin >> s;

	map<char,int> m {};

	for (char c : s)
		m[c]++;

	if (m.size() != 2)
		cout << "No";
	else
		cout << "Yes";

    return 0;
}