#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define mod 1000000007
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define f first
#define s second
#define pb push_back
#define mp make_pair


int n, a[202020], ans;

int main(){
cin >> n;
rep(i, 1, n)cin >> a[i];
rep(i, 1, n-1){
if(a[i]==i)swap(a[i], a[i+1]), ans++;
}
rep(i, 2, n){
if(a[i]==i)swap(a[i], a[i+1]), ans++;
}
cout << ans << endl;


return 0;}
