/*problem from Wolfycz*/
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define inf 0x7f7f7f7f
#define lowbit(x) ((x)&-(x))
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
inline char gc(){
	static char buf[1000000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;
}
inline int frd(){
	int x=0,f=1; char ch=gc();
	for (;ch<'0'||ch>'9';ch=gc())	if (ch=='-')	f=-1;
	for (;ch>='0'&&ch<='9';ch=gc())	x=(x<<3)+(x<<1)+ch-'0';
	return x*f;
}
inline int read(){
	int x=0,f=1; char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar())	if (ch=='-')	f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar())	x=(x<<3)+(x<<1)+ch-'0';
	return x*f;
}
inline void print(int x){
	if (x<0)	putchar('-');
	if (x>9)	print(x/10);
	putchar(x%10+'0');
}
const int N=1e5;
int v[N+10];
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int check(int n){
	int odd=0,even=0; bool flag=0;
	for (int i=1;i<=n;i++){
		v[i]&1?odd++:even++;
		if (v[i]==1)	flag=1,odd--;
	}
	if (even&1)	return 1;
	if (flag)	return 0;
	if (odd>1)	return 0;
	return -1;
}
int main(){
	int n=read(),Time=0;
	for (int i=1;i<=n;i++)	v[i]=read();
	while (true){
		int tmp=check(n),d=0; ++Time;
		if (~tmp){
			printf((tmp^Time)&1?"Second\n":"First\n");
			break;
		}
		for (int i=1;i<=n;i++)	if (v[i]&1)	v[i]--;
		for (int i=1;i<=n;i++)	d=gcd(d,v[i]);
		for (int i=1;i<=n;i++)	v[i]/=d;
	}
	return 0;
}