#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	int c4 = 0, nc2 = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] % 4 == 0)
				c4++;
			if (a[i] % 2 != 0)
				nc2++;
		}
		if (n % 2 == 1)
			cout << (c4 + 1 < nc2 ? "No" : "Yes") << endl;
		else
			cout << (c4 < nc2 ? "No" : "Yes") << endl;
	return 0;
}