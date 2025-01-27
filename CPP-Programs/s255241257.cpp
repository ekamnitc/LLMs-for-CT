#include <bits/stdc++.h>
using namespace std;
#define EXCEPTERROR cout << "-1" << endl;
#define rep(k,nu)    for(int i=k; i<nu;  i++)
#define rep2(k,n)   for(int j=k; j<n;  j++)
#define size_a(array) sizeof(array) / sizeof(array[0])
#define INF 1000000000000 //1e+12
#define MOD 10000007 //1e9+7
#define ll long long
#define pb pop_back
template<typename T> inline void chMin(T* a, T* b) {if(*a>*b) *a=*b;}
template<typename T> inline void chMax(T* a, T* b) {if(*a<*b) *a=*b;}
template<typename T> inline int  divUp(T a, T b)   {return ((a+b-1)/b);}
const double PI = acos(-1);


int main(){
    int x, y, z;
    cin >> x >> y >> z;
    swap(x,y);
    swap(x,z);

    cout << x << " " << y << " " << z << endl;
    return 0;
}
/*

*/
