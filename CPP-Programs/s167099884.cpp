#include <iostream>
#include <cmath>
#include <climits>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <numeric>
using namespace std;
// scanf
#pragma warning(disable: 4996)
// v:vector  type:型  order:greater or less
#define _sort(v,type,order) do { sort(v.begin(),v.end(),order<type>()); } while(0)
// v:vector  default_value:初期値
#define _sum(v,default_value) accumulate(v.begin(),v.end(),default_value )
// 丸め
#define _round(v) round(v)
// 2乗 / 3乗
#define _square(v) pow(v,2)
#define _cube(v)   pow(v,3)
// 大小判定
#define _max(x,y) max(x,y)
#define _min(x,y) min(x,y)
// string ⇒ int
#define _stringtoi(s) stoi(s)
// double 平方根
#define _sqrt(x) sqrt(x)
// double 引数 x 以上で最小の整数値
#define _ceil(x) ceil(x)

int main()
{
	char c[3] = { 0 };
	char temp;
	uint32_t i;
	for (i = 0; i < 3; i++) {
		cin >> temp;
		if (c[temp - 'a']) {
			break;
		}
		c[temp - 'a']++;
	}
	if (i >= 3) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	return 0;
	//	std::cout << "Hello World!\n"; 
}
