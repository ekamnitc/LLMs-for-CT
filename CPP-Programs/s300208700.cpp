//E.H//
# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
int n,k;
ll arr[100005];
ll ps[100005],psposi[100005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        ps[i]=ps[i-1] + arr[i];
        psposi[i]=psposi[i-1] + max(0LL,arr[i]);
    }
    ll temp=0;
    int awal=-1;
    for(int i=k;i<=n;i++){
        ll x=max(0LL,ps[i]-ps[i-k]);
        x+=psposi[i-k];
        x+=(psposi[n]-psposi[i]);
        if(x>temp){
            temp=x;
            awal=i-k+1;
        }
    } 
    cout<<temp<<endl;

}