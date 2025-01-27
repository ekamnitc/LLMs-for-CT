#include <bits/stdc++.h>
using namespace std;

int main()
{
  int H, W;
  cin >> H >> W;
  
  string A_Z = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  
  int ansH;
  char ansW;
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      string S;
      cin >> S;
      if (S == "snuke")
      {
        ansH = i + 1;
        ansW = A_Z.at(j);
        break;
      }
    }
  }
  
  cout << ansW << ansH << endl;
}