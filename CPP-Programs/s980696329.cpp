#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

int main(){
	int a,b;
	cin >> a >> b;
	cout << a/b << endl;
	cout << a%b << endl;
	printf("%.10f\n",1.*a/b);
	return 0;
}