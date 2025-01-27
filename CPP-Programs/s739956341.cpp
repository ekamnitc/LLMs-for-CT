#include<bits/stdc++.h>
using namespace std;
int  k,t,a[101],s,maxa=0;
int main(){
	cin>>k>>t;
	for(int i=1;i<=t;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
		s+=a[i];
	}
	if(s-maxa>=maxa-1)cout<<0<<endl;
	else cout<<maxa-s+maxa-1<<endl;
}