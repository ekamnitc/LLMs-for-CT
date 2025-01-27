#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct UnionFind {
    int size;
    int numComponents;
    vector<int> sz;
    vector<int> id;

    UnionFind(int N) {
        size = numComponents = N;
        sz = vector<int>(N, 1);
        id = vector<int>(N);
        for(int i = 0; i < N; i++) {
            id[i] = i;
        }
    }

    int find(int p) {
        int root = p;
        while(root != id[root]) {
            root = id[root];
        }
        while(p != root) {
            int next = id[p];
            id[p] = root;
            p = next;
        }
        return root;
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    int componentSize(int p) {
        return sz[find(p)];
    }

    void unify(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if(rootP == rootQ) return;

        if(sz[rootP] < sz[rootQ]) {
            sz[rootQ] += sz[rootP];
            id[rootP] = rootQ;
        } else {
            sz[rootP] += sz[rootQ];
            id[rootQ] = rootP;
        }
        numComponents--;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    UnionFind UF(N);

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        UF.unify(a, b);
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        ans = max(ans, UF.componentSize(i));
    }
    cout << ans << endl;
}