#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
#define INF 100000000
#define MAX 9000000000000000000
#define MOD 1000000007
typedef vector<vector<int> > Graph;

int main(){
    string s;cin>>s;
    map<char,int> al;
    vector<char> v(26);
    int n=s.size();
    int k;cin>>k;
    for(int i=0;i<26;i++){
        char m='a'+i;
        v[i]=m;
        al[m]=i;
    }
    for(int i=0;i<n;i++){
        if(k==0){
            cout<<s[i];
            continue;
        }
        if(i==n-1){
            int idx=(al[s[i]]+k)%26;
            cout<<v[idx];
            break;
        }
        char now=s[i];
        if(now=='a'){
            cout<<'a';
            continue;
        }
        int c=26-al[now];
        if(c<=k){
            cout<<'a';
            k-=c;
        }
        else{
            cout<<now;
        }
    }
    cout<<endl;
}