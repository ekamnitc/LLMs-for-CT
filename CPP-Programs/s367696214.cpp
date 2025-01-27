#include<bits/stdc++.h>
#include<bitset>

using namespace std;

#define M 1000000007
#define pb push_back
#define f first
#define s second
#define rep(i, st, ed) for(int i=st; i<ed; i++)
#define repn(i, st, ed) for(int i=st; i<=ed; i++)


typedef long long ll;
typedef unsigned long long int llt;

const int N = 5e5 + 10;

vector<int> g[N];
bool viss[N];
int vis[N];

void dfs(int curr, int par)
{
  for(auto x: g[curr])
    if(x != par)
      dfs(x, curr);
}

void dfs1(int curr, int par)
{
  viss[curr] = 1;
  for(auto x: g[curr])
    if(!viss[x])
      dfs1(x, curr);
}

void dfs2(int curr, int par, int num)
{
  vis[curr] = num;
  for(auto x: g[curr])
    if(vis[x] == 0)
      dfs2(x, curr, num);
}

ll fxor(ll n)
{
  if(n < 0) return 0;
  if(n % 4 == 3) return 0;
  else if(n % 4 == 0) return n;
  else if(n % 4 == 1) return n^(n-1);
  else if(n%4 == 2) return n^(n-1)^(n-2);
}

llt ppow(llt x, llt y)
{
  llt res = 1;
  while(y > 0){
    if(y&1)
      res = (res * x)%M;
    y = y >> 1;
    x = (x * x)%M;
  }
  return res;
}

llt factdp[N];
llt fact(llt x)
{
  if(x == 0) return 1;
  if(x == 1) return 1;
  if(factdp[x] != -1) return factdp[x];
  return factdp[x] = (x*fact(x-1))%M;
}

string ans ="";
void convert10tob(llt N, int b)
{
     if (N == 0)
        return;
     int x = N % b;
     N /= b;
     if (x < 0)
        N += 1;
     convert10tob(N, b);
     ans += to_string(x);
     return;
}

llt convertstrtob(string a, int b)
{
  llt aa = 0;
  llt mul = 1;
  for(int i=a.length()-1; i>=0; i--)
  {
    int curr = a[i] - '0';
    aa += (curr * mul);
    mul *= b;
  }
  return aa;
}



int main()
{
  llt n;
  cin>>n;
  llt a, b;
  a = b = 1;
  rep(i, 0, n)
  {
    llt x, y;
    cin>>x>>y;
    llt j = max(a /x, b / y);
    while(true)
    {
      llt xx = x*j;
      llt yy = y*j;
      if(xx >= a && yy >= b)
      {
        a = xx;
        b = yy;
        break;
      }
      j++;
    }
  }
  cout<<a+b<<endl;
  return 0;
}
