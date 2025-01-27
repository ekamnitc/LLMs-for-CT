#include <iostream>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <vector>
using namespace std;

#define D

#ifdef D
int main(void)
{
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	vector<double> tmp(n);
	for (auto &a : x)
	{
		cin >> a;
	}
	for (auto &a : y)
	{
		cin >> a;
	}
	for (size_t i = 0; i < n; i++)
	{
		tmp[i] = abs(x[i] - y[i]);
	}
	double L1 = 0, L2= 0, L3= 0, Lmax= 0;
	for (auto a : tmp)
	{
		L1 += a;
		L2 += pow(a, 2);
		L3 += pow(a, 3);
		if (Lmax < a) Lmax = a;
	}
	L2 = sqrt(L2);
	L3 = pow(L3, 1.0 / 3);

	cout << fixed << setprecision(12) << L1 << endl;
	cout << fixed << setprecision(12) << L2 << endl;
	cout << fixed << setprecision(12) << L3 << endl;
	cout << fixed << setprecision(12) << Lmax << endl;


	return 0;
}
#endif // D