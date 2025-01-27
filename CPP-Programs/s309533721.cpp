#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

int n, k;
vector <int> digits;

bool check(int number){
	string num = to_string(number);
	
	for (char c:num){
		for (int dig:digits){
			if (c - '0' == dig) return false;
		}
	}
	
	return true;
}

int main ()
{

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #define int ll
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout);

	int n, k;
	cin >> n >> k;
	
	for (int i=0; i<k; i++){
		int a;
		cin >> a;
		digits.emplace_back(a);
	}	
	
	int ans;
	for (int i=n; true; i++){
		if (check(i)){
			cout << ((n+i-1)/i)*i << endl;
			return 0; 
		}
	}
	    	
    return 0;

}