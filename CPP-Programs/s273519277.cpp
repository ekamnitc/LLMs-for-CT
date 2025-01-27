#include<iostream>
#include<cstdio>
#include<math.h>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<set>
#include<map>
#define INF 999999
#define EPS 1.0e-6

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> PP;

int h, w, d;
char c[525][525];
string col = "RGBYRGBY";

int main()
{
	cin >> h >> w >> d;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			c[i][j] = 'a';
		}
	}

	if (d%2==0) {
		int n = d / 2;
		for (int i = 0; i < d; i++) {
			int s;
			s = i / 2;
		
			int j = 0;

			while (1) {
				int ope = 0;
				int k = 0, m = i + j*d;
				while (k < h&&m >= 0) {
					if (j % 2 == 0 && m < w) {

						int n = d / 2;
						if (((k-s+2*d) / n) % 2 == 0)c[k][m] = col[0];
						else c[k][m] = col[2];
						//c[k][m] = col[0];

						ope++;
					}
					else if (j % 2 == 1 && m < w) {

						int n = d / 2;
						if (((k-s+2*d) / n) % 2 == 0)c[k][m] = col[1];
						else c[k][m] = col[3];
						//c[k][m] = col[1];

						ope++;
					}
					k++; m--;
				}
				if (ope == 0)break;
				j++;
			}
		}
	}
	if (d%2==1) {
		for (int i = 0; i < d; i++) {
			c[0][i] = col[0];
			int j = 0;

			while (1) {
				int ope = 0;
				int k = 0, m = i + j*d;
				while (k < h&&m >= 0) {
					if (j % 2 == 0 && m < w) {
						c[k][m] = col[0];
						ope++;
					}
					else if (j % 2 == 1 && m < w) {
						c[k][m] = col[1];
						ope++;
					}
					k++; m--;
				}
				if (ope == 0)break;
				j++;
			}
		}

		for (int i = w - 1; i >= max(w - 1 - d + 1, 0); i--) {
			int icol;
			if (c[0][i] == col[0]) icol = 0;
			else icol = 1;
			int j = 0;
			while (1) {
				int ope = 0;
				int k = 0, m = i - j*d;
				while (k < h&&m <= w - 1) {
					if (j % 2 == 0 && m >= 0) {
						if (c[k][m] == col[1 - icol])c[k][m] = col[icol + 2];
						ope++;
					}
					else if (j % 2 == 1 && m >= 0) {
						if (c[k][m] == col[icol])c[k][m] = col[3-icol];
						ope++;
					}
					k++; m++;
				}
				if (ope == 0)break;
				j++;
			}
		}


	}
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << c[i][j];
		}
		cout << endl;
	}
	return 0;
	
}