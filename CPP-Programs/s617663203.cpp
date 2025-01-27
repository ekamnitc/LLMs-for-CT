#include <iostream>
#include <vector>

using namespace std;

// First try: TLE, O(QN)

void transform(vector<vector<int>>& graph, vector<vector<int>>& tree, int parent, int current) {
  for (int child : graph[current]) {
    if (child != parent) {
      tree[current].push_back(child);
      transform(graph, tree, current, child);
    }
  }
}

// void operate(vector<vector<int>>& tree, vector<int>& counter, int p, int x) {
//   counter[p] += x;
//   for (int child : tree[p]) {
//     operate(tree, counter, child, x);
//   }
// }

void add(vector<vector<int>>& tree, vector<int>& counter, int parent_sum, int current) {
  counter[current] += parent_sum;
  for (int child : tree[current]) {
    add(tree, counter, counter[current], child);
  }
}

int main() {
  int N, Q; cin >> N >> Q;
  vector<vector<int>> graph(N);
  for (int i = 0; i < N - 1; i++) {
    int a, b; cin >> a >> b;
    graph[a - 1].push_back(b - 1);
    graph[b - 1].push_back(a - 1);
  }
  int p[Q];
  int x[Q];
  for (int j = 0; j < Q; j++) {
    cin >> p[j] >> x[j];
    p[j]--;
  }

  vector<vector<int>> tree(N);
  transform(graph, tree, -1, 0);

  vector<int> counter;
  counter.assign(N, 0);
  for (int i = 0; i < Q; i++) {
    counter[p[i]] += x[i];
  }

  add(tree, counter, 0, 0);

  for (int i = 0; i < N; i++) {
    cout << counter[i];
    if (i < N - 1) cout << " ";
  }
  cout << endl;
}