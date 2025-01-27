#include <bits/stdc++.h>
using namespace std;
const int MAXN = 201;
const int64_t INF = 10000000000;
vector<vector<int64_t>> Cost(MAXN, vector<int64_t>(MAXN, INF));

int main()
{
  int64_t N, M, R, a, b, c;
  cin >> N >> M >> R;
  vector<int64_t> A(R);
  for (int i = 0; i < R; i++)
    cin >> A.at(i);
  for (int i = 0; i < M; i++)
  {
    cin >> a >> b >> c;
    Cost.at(a).at(b) = c;
    Cost.at(b).at(a) = c;
  }
  for (int i = 1; i <= N; i++)
    Cost.at(i).at(i) = 0;
  for (int k = 1; k <= N; k++)
  {
    for (int i = 1; i <= N; i++)
    {
      for (int j = 1; j <= N; j++)
      {
        if (Cost.at(i).at(j) > Cost.at(i).at(k) + Cost.at(k).at(j))
          Cost.at(i).at(j) = Cost.at(i).at(k) + Cost.at(k).at(j);
      }
    }
  }
  sort(A.begin(), A.end());
  int64_t ans = INF;
  do
  {
    int64_t s = 0;
    for (int i = 1; i < R; i++)
    {
      s += Cost.at(A.at(i - 1)).at(A.at(i));
    }
    if (s < ans)
      ans = s;
  } while (next_permutation(A.begin(), A.end()));
  cout << ans << endl;
}