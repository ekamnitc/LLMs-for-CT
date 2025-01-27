#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>


using namespace std;



int main() {

	int a, b, product=1;

	cin >> a >> b;

	if (a <= 0 && b >= 0) {
		cout << "Zero";
	}
	else if (a > 0) {
		cout << "Positive";
	}
	else if (b < 0) {
		if ((b - a) % 2 == 0) {
			cout << "Negative";
		}
		else cout << "Positive";
	}
	return 0;

}