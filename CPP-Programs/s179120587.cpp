#include <bits/stdc++.h>
using namespace std;
#define ll long long
int  N = 2e5+7;
int n;
vector<int> h(N,0);
vector<int> val(N,0);
vector<ll>tree(4*N,0);

ll query(int tree_l,int tree_r,int treeix,int q_l,int q_r)
{
  //cout<<"tree_range : "<<tree_l<<":"<<tree_r<<endl;
  if(q_l<=tree_l && q_r>=tree_r)
  {
    return tree[treeix];
  }
  else if(q_l>tree_r || q_r<tree_l)
  {
    return 0;
  }
  int m = (tree_l + tree_r)/2;
  ll left = query(tree_l,m,2*treeix,q_l,q_r);
  ll right = query(m+1,tree_r,2*treeix+1,q_l,q_r);
  return max(left,right);
  //cout<<"timestamp : "<<left.timestamp<<" "<<right.timestamp<<endl;
  //cout<<"for range "<<tree_l<<" "<<tree_r<<" : "<<ans.data<<endl;
  //ans.timestamp = max(left.timestamp,right.timestamp);
}

void update(int tree_l,int tree_r,int treeix,int valix,ll value)
{
  //cout<<"tree_range : "<<tree_l<<":"<<tree_r<<endl;
  if(tree_l == tree_r)
  {
    tree[treeix] = max(tree[treeix],value);
    return;
  }
  int m = (tree_l + tree_r)/2;
  if(m<valix)
  {
    update(m+1,tree_r,2*treeix+1,valix,value);
  }
  else
  {
    update(tree_l,m,2*treeix,valix,value);
  }
  ll l = tree[2*treeix];
  ll r = tree[2*treeix+1];
  tree[treeix] = max(l,r);
}


int main()
{
  cin>>n;
  for(int i=1;i<=n;i++) cin>>h[i];
  for(int i=1;i<=n;i++) cin>>val[i];
  vector<ll> sol(n+1);
  ll ans = 0;
  for(int i=1;i<=n;i++)
  {
    sol[i] = val[i] + query(1,N,1,0,h[i]-1);
    ans = max(ans,sol[i]);
    update(1,N,1,h[i],sol[i]);
  }
  cout<<ans<<endl;
  return 0;
}
