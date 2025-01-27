#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string s;
	cin>>s;
	vector<int> v(26, 0);
	for(char ch: s) {
		v[ch-'a']++;
	}
	for(int x: v) {
		if(x%2 == 1) {cout<<"No"; return 0;}
	}
	cout<<"Yes";
}
