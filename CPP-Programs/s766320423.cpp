#include <bits/stdc++.h>
using namespace std;
int main(){
	string a , b;
	cin >> a;
	cin >> b;
	for(int i = 0;i < a.size();i++){
		if(a.at(i) != b.at(i)){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;		
}
			
