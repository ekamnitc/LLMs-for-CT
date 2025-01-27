#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 3e5 + 5;

int n, m;
int l[maxn], r[maxn];
int c[maxn];

void add(int x, int d){
    for(int i = x;i < maxn;i += i & -i){
        c[i] += d;
    }
}

int Sum(int x){
    int res = 0;
    for(int i = x;i > 0;i -= i & -i){
        res += c[i];
    }
    return res;
}

vector<int> G[maxn];

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        scanf("%d%d", &l[i], &r[i]);
        r[i]++;
        G[r[i] - l[i]].push_back(i);
    }
    int sum = n;
    for(int i = 1;i <= m;i++){
        for(auto it : G[i]){
            add(l[it], 1);
            add(r[it], -1);
        }
        sum -= G[i].size();
        int ans = sum;
        for(int j = i;j <= m;j += i){
            ans += Sum(j);
        }
        printf("%d\n", ans);
    }
    return 0;
}
