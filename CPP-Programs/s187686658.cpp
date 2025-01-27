#include<iostream>
using namespace std;
int main() {
	int A, B, C;
	cin >> A >> B >> C;
	int count5 = 0;
	int count7 = 0;
	if (A == 5) {
		count5++;
	}
	else if (A == 7) {
		count7++;
	}
	if (B == 5) {
		count5++;
	}
	else if (B == 7) {
		count7++;
	}
	if (C == 5) {
		count5++;
	}
	else if (C == 7) {
		count7++;
	}

	if (count5 == 2 && count7 == 1) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;

}