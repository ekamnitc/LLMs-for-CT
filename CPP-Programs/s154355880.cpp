#include <bits/stdc++.h>
using namespace std;
int main(){
	int A, B, C; cin >> A >> B >> C; 
	if(A + B + C == max({A, B, C}) * 2) cout << "Yes" << endl; 
	else cout << "No" << endl; 
}