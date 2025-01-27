#include <iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int main() {
	int a,b,c,x;
	cin >> a>>b;
	x = 0;
	if (a * b * 1 % 2 == 0)x = x + 1;
	if (a * b * 2 % 2 == 0)x = x + 1;
	if (a * b * 3 % 2 == 0)x = x + 1;
	
	if (x == 3) cout << "No" << endl;
	else cout << "Yes" << endl;

	return 0;
}