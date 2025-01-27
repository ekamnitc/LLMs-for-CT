#include <iostream>
using namespace std;

int main() {
	int e, x, y, z, min;

	while (cin >> e && e != 0) {
		min = 999999999;
		
		for (z = 0; z*z*z <= e; z++) {
			for (y = 0; y*y <= e - z*z*z; y++) {
					x = e - y*y - z*z*z;
				
				if (min > x + y + z) {
					min = x + y + z;
				}
			}

		}

		cout << min << endl;
	}
}