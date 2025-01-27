//
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define PI 3.14159265
#define EPS 1e-9
#define Pi acos(-1.0)
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define clean(arr,val) memset(arr,val,sizeof(arr))
#define forn(i,n) forr(i,0,n)
#define PB push_back
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<pll> vpll;

/*CODE START HERE*/

int n, m;
string a[55];
string b[55];
bool sol, aux;

int main(){
    ios::sync_with_stdio(0);
    cin >> n >> m;
    forn(i,n){
        cin >> a[i];
    }
    forn(i,m){
        cin >> b[i];
    }

    sol = false;

    if(m > n){
        cout << "No\n";
        return 0;
    }

    forn(i,n-m+1){
        forn(j,n-m+1){
            aux = true;
            forn(k,m){
                forn(l,m){
                    if(a[i+k][j+l] != b[k][l]){
                        aux = false;
                        break;
                    }
                }
                if(!aux)
                    break;
            }
            if(aux){
                sol = true;
                break;
            }
        }
    }

    if(sol){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }

    return 0;
}