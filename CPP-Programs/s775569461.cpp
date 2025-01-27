#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
	long long N; std::cin >> N;
	std::string str = "";
	while (N) {
		--N;
		str += (char)('a' + (N % 26));
		N /= 26;
	}
	std::reverse(str.begin(), str.end());
	std::cout << str << std::endl;

	return 0;
}