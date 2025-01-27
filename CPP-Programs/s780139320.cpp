#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int x;

void solve(){
	scanf("%d",&x);
	for(int i=1;;i++){
		if(i*360%x==0){
			printf("%d\n",i*360/x);
			break;
		}
	}	
}
int main(){
	solve();
	return 0;
}