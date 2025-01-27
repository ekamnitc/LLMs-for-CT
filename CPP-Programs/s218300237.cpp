//C
#include <cassert>
//#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>

//ここまで標準include

using namespace std;

long aCb(long a, long b) {
	long out = 1;
	for (long i = 1; i <= b; i++) {
		out = out * (a + 1 - i) / i;
	}
	return out;
}

long long gcd(long long a, long long b) {
	long long r = -1;
	if (a < b) {
		swap(a, b);
	}
	while (r != 0) {
		r = a % b;
		if (r == 0) {
			return b;
		}
		else {
			a = b;
			b = r;
		}
	}
}

long long lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}

int main() {
	int A, B;
	cin >> A >> B;
	if (A % 3 == 0 || B % 3 == 0 || (A + B) % 3 == 0) {
		cout << "Possible" << endl;
	}
	else {
		cout << "Impossible" << endl;
	}
}
