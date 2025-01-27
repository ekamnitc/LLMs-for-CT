#include <iostream>
#include <string>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  string S;
  cin >> S;

  int num = 0;
  rep(i, S.size())
  {
    if (S[i] == '+')
      num++;
    else
      num--;
  }

  cout << num << endl;

  return 0;
}
