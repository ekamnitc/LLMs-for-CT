#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  long long n,m,res;
  cin >> n >> m;
  if(n==1&&m==1)
    res=1;
  else if(n==1||m==1)
    res=max(n,m)-2;
  else
    res=(n-2)*(m-2);
  cout << res << endl;
  return 0;
}