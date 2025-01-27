#include<bits/stdc++.h>
using namespace std;
int n,m,q;
vector<int> a,b,c,d;

long long score(const vector<int>& A){
  long long res=0;
  for(int i=0; i<q; ++i) if(A[b[i]]-A[a[i]]==c[i]) res+=d[i];
  return res;
}

long long dfs(vector<int>& A){
  if(A.size()==n) return score(A);
  
  long long res=0;
  int start=(A.empty()? 0 : A.back());
  
  for(int j=start; j<m; ++j){
    A.push_back(j);
    res = max(res,dfs(A));
    A.pop_back();
  }
  return res;
}

int main(void){
  cin>>n>>m>>q;
  a.resize(q);b.resize(q);c.resize(q);d.resize(q);
  for(int i=0; i<q; ++i){ cin>>a[i]>>b[i]>>c[i]>>d[i]; --a[i];--b[i];}
  vector<int> A;
  cout<<dfs(A)<<endl;
  return 0;
}
