#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<i64> D1(N), D2(N);
  for (i64 i = 0; i < N; i++)
    cin >> D1[i] >> D2[i];
  i64 cnt = 0;
  for (i64 i = 0; i < N; i++)
    if (D1[i] == D2[i])
    {
      cnt++;
      if (3 <= cnt)
      {
        cout << "Yes" << endl;
        return 0;
      }
    }
    else
      cnt = 0;
  cout << "No" << endl;
  return 0;
}
