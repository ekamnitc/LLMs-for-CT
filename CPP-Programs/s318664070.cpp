
#include <iostream>
#include <numeric>
#include <stdio.h>
#include <iomanip>
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
using namespace std;
using ll = long long;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
int Max(int(a), int(b), int(c)) {
	return max(max(a, b), c);
}
int Min(int(a), int(b), int(c)) {
	return min(min(a, b), c);
}
int gcd(ll(a), ll(b)) {
	ll q = a;
	ll w = b;
	ll e = q;
	while (q % w != 0) {
		e = q % w;
		q = w;
		w = e;
	}
	return w;

}





int main() {
	ll A,B,K;
	cin >> A >> B >> K;
	int i = 0;
	while (i < K) {
		if (i % 2 == 0) {
			if (A % 2 ==1) {
				A--;
			}
			A /= 2;
			B += A;
			i++;
		}
		else {
			
				if (B % 2 == 1) {
					B--;
				}
				B /= 2;
				A += B;
				i++;
		}
	}
	cout << A << " " << B << endl;


	
	
}