#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

const int mod = 1000000007;
int n;
int freq[128];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		char c;
		scanf(" %c", &c);
		freq[c]++;
	}
	
	int ans = 1;
	for(int i = 'a'; i <= 'z'; i++){
		ans = 1LL * ans * (1 + freq[i]) % mod;
	}
	ans = (ans + mod - 1) % mod;
	printf("%d\n", ans);
	return 0;
}