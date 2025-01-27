
// Problem : B - NarrowRectanglesEasy
// Contest : AtCoder - AtCoder Beginner Contest 056
// URL : https://atcoder.jp/contests/abc056/tasks/abc056_b
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define spc ' '
#define endl '\n'

using namespace std;


int main(){
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a, b, W;
	cin >> W >> a >> b;
	if(a>b) swap(a,b);
	if(a+W>=b){
	    cout << 0;
	    return 0;
	}
	cout << b-a-W;
	return 0;
}