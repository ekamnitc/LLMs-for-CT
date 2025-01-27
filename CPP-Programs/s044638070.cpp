#include <bits/stdc++.h>

using namespace std;

int N;

void addEdge(int n, int m){
    cout << n << " " << m << "\n";
}

int main(){
    cin >> N;
    if((1<<__builtin_ctz(N)) == N){
        cout << "No" << "\n";
        return 0;
    }
    cout << "Yes" << "\n";

    for(int i = 2; i<N; i+=2){
        addEdge(i, 1);
        addEdge(i+1, 1);
        addEdge(i, i+1+N);
        addEdge(i+1, i+N);
    }
    addEdge(N+2, N+1);
    if(N&1^1){
        int b = 31 - __builtin_clz(N);
        addEdge(N, (1<<b));
        addEdge(N+N, (1<<b)^N^1);
    }
}
