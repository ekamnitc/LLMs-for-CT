#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;
using namespace std;


int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    int i;
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a.begin(),a.end());

    ll min=LINF;
    int mini=0;
    for(i=0; i<n-1; i++) {
        ll tmp=abs(a[n-1]-2*(ll)a[i]);
        if(tmp<min) {
            min=tmp;
            mini=i;
        }
    }
    printf("%d %d\n", a[n-1], a[mini]);

    return 0;
}

