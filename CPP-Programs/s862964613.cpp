#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  unsigned long power = 1;
  int w = pow(10,9) + 7;
  
  for(int i=1; i<=N; i++)
  {
    power = (power * i) % w;
  }
  
  cout << power << endl;
}