#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <functional>
#include <queue>
#include <unordered_set>
#include <climits>
#include <set>
#include <list>
#include <cmath>
#include <map>

using namespace std;
typedef long long ll;

int main()
{
	int N,C;
	cin >> N >> C;
	int D[31][31];
	int Count[3][31];
	for(int i = 1; i <= C; i++){
		for(int j = 1; j <= C; j++){
			cin >> D[i][j];
		}
	}
	for(int i = 1; i <= 30; i++){
		Count[0][i] = 0;
		Count[1][i] = 0;
		Count[2][i] = 0;
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			int C;
			cin >> C;
			Count[(i+j)%3][C]++;
		}
	}
	
	ll ans = LLONG_MAX;
	for(int p = 1; p <= C; p++){
		for(int q = 1; q <= C; q++){
			for(int r = 1; r <= C; r++){
				if(p == q || q == r || r == p){
					continue;
				}
				ll discomfort = 0;
				for(int c = 1; c <= C; c++){
					discomfort += Count[0][c] * D[c][p];
					discomfort += Count[1][c] * D[c][q];
					discomfort += Count[2][c] * D[c][r];
				}
				ans = min(ans, discomfort);
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}