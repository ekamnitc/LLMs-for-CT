#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
int X, Y, Z;
struct node{
	ll x, y, z;
}p[1005];
ll ans;

bool cmp(const node &a, const node &b){
	return a.x * X + a.y * Y + a.z * Z > b.x * X + b.y * Y + b.z * Z;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%lld%lld%lld", &p[i].x, &p[i].y, &p[i].z);
	
	for(X = -1; X <= 1; X += 2){
		for(Y = -1; Y <= 1; Y += 2){
			for(Z = -1; Z <= 1; Z +=2){
				sort(p + 1, p + 1 + n, cmp);
				ll now = 0;
				for(int i = 1; i <= m; i++) now += X * p[i].x + Y * p[i].y + Z * p[i].z;
				ans = max(ans, now);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}