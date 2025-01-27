#include<bits/stdc++.h>
using namespace std;

int digit(int a)
{
  int cnt = 0;
  
  while(1)
    { 
      a /= 10;
      cnt++;
      if(!a) break;
    }
  return cnt;
}
int main(){
  int a,b;

  while(scanf("%d%d",&a,&b) != EOF)
    {
      int n;
      int sum = a + b;
      
      n = digit(sum);
      
      cout << n << endl;
    }
  return 0;
}

