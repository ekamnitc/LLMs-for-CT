#include<iostream>

using namespace std;

int main() {
	int i, j, W, H;
	while (cin >> H >> W, H || W){
		for (i = 1; i <= H; i++){
			for (j = 1; j <= W; j++){
				cout << "#";
			}
			cout << endl;
		}
          cout << endl;
	}
}