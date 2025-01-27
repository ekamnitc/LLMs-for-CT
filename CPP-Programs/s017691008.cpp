#include <iostream>
using namespace std;
typedef long long int LLI;
LLI power(LLI pods, LLI wykl)
{
	LLI wynik = 1;
	for(int i = 0; i < wykl; i++)
		wynik *= pods;
	return wynik;
}
int main()
{
	LLI n, k;
	cin >> n >> k;
	cout << k*power((LLI)(k-1),(LLI)(n-1));
}