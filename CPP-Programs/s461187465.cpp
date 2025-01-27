#include<bits/stdc++.h>
using namespace std ;

int main() {
	int  n;
	cin >> n;
	string str;
	map<string,bool>m;

	for(int i=1;i<=n;i++){
		cin >> str ;
		m[str]=1;
	}
		cout <<m.size() << '\n' ;
	}