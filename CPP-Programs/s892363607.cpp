#include<bits/stdc++.h>
using namespace std;
const int maxn = 200000;
int is_prime[maxn+5];

int main(){
	for(int i=2; i<=maxn; i++) is_prime[i] = i;
	for(int i=2; i*i<=maxn; i++){
		if(is_prime[i] == i){
			for(int j=i; j<=maxn; j+=i) is_prime[j] = i;
		}
	}
	int x;
	cin>>x;
	while(is_prime[x]!=x) x++;
	cout<<x;
}