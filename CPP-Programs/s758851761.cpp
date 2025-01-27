#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	if (m==1){
		puts("0");
		return 0;
	}
	printf("%d\n",n-m);
}