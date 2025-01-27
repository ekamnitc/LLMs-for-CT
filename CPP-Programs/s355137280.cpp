#include <iostream>

using namespace std;

int main(){
	int a, b, c;

	cin >> a >> b >> c;

	bool poor = false;

	if(a == b && a != c)
		poor = true;
	else if(a != b && a == c)
		poor = true;
	else if(b == c && a != c)
		poor = true;

	if(poor)
		cout << "Yes\n";
	else
		cout << "No\n";
}