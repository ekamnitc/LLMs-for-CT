#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int main(){

	int x1,y1,x2,y2;

	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

	int dx = x2-x1,dy = y2-y1;

	printf("%d %d %d %d\n",x2-dy,y2+dx,x2-(dy+dx),y2+dx-dy);

	return 0;
}
