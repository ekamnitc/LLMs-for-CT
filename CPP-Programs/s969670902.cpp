#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<math.h>
#include<iostream>
using namespace std;

bool era[1000000];

int main(){
	era[0]=false;
	era[1]=false;
	for(int i=2;i<=1000000;i++) era[i]=true;
	for(int i=2;i<=1000;i++){
		for(int j=2;i*j<1000000;j++) era[i*j]=false;
	}
	int a,b,n,cnt;
	while(cin>>a>>b>>n && a && b && n){
		cnt=0;
		while(cnt!=n){
			if(era[a]==true) cnt++;
			a+=b;
		}
		cout<<a-b<<endl;
	}
	return 0;
}