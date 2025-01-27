#include <iostream>
#include <cstdio>
#include <set>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <fstream>
#include <iomanip>
//#include <unordered_map>
using namespace std;
#define dbg(x) cerr << #x " = " << x << endl;
typedef pair<int, int> P;
typedef long long ll;
#define FIN freopen("in.txt", "r", stdin);

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    double ret = 0;
    for (int i = 1; i <= a; i++)
    {
        double tmp = 1.0 / a;
        int now = i;
        while (now < b)
        {
            now *= 2;
            tmp /= 2;
        }
        ret += tmp;
    }
    printf("%.12f\n", ret);
}
