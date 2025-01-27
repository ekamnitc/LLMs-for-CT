#include <bits/stdc++.h>

using namespace std;

int main(){

	int a,b;

	int soma;
	int su;
	int vezes;

	cin >> a;
	cin >> b;

	soma = a + b;
	su = a - b;
	vezes = a * b;

	if(soma >= su && soma >= vezes)
	{
		cout << soma << "\n";
	}else 

	if(su >= soma && su >= vezes)
	{
		cout << su << "\n";
	}else

	if(vezes >= soma && vezes >= su)
		cout << vezes << "\n";

	return 0;
}
