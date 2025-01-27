#include<iostream>

using namespace std;
int m;
const int mmax=1e5+8;
long long d,c;
long long ans,sum;
int main(){
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>d>>c;
		sum+=d*c;
		ans+=c;
	}
	ans--;
	sum--;
	sum/=9;
	cout<<ans+sum;
	return 0;
} 