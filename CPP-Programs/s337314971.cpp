#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int a,b,c;
	cin >> a >> b >> c;
	int ans=0;
	for(int i=1;i<=100;i++)
		if(c>=a*i) ans+=b;
	cout << ans;
	return 0;
}