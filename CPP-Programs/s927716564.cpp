#include<bits/stdc++.h>
using namespace std;
string s="CODEFESTIVAL2016",a;
int ans;
int main() {
	cin>>a;
	for(int i=0; i<=15; i++) {
		if(a[i]!=s[i])ans++;
	}
	printf("%d",ans);
	return 0;
}