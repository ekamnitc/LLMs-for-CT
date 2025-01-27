#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    int a[51], b[51];
    int c[51], d[51];
    int min_point[51];
    for(int i = 0; i < N; i++) cin >> a[i] >> b[i];
    for(int i = 0; i < M; i++) cin >> c[i] >> d[i];

    for(int i = 0; i < N; i++){
        int min = 400000000;
        for(int j = 0; j < M; j++){
            if(min > abs(a[i]-c[j])+abs(b[i]-d[j])){
                min_point[i] = j;
                min = abs(a[i]-c[j])+abs(b[i]-d[j]);
            }
        }
    }
    for(int i = 0; i < N; i++) cout << min_point[i]+1 << endl;
    return 0;
}