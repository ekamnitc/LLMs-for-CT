#include<bits/stdc++.h>
using namespace std ;
 
/*                        [Template]                        */
#define async ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long int
#define let auto
#define of :
#define all(y) y.begin(), y.end()
#define present( x, y ) x.find( y ) != x.end()
#define _matrix(T) vector<vector<T>>
template<class T>
auto matrix( int r, int c, T v ){
	return vector<vector<T>>( r, vector<T>( c, v ) ) ;
}
const int mod = (int)1e9 + 7 ;
const int inf = (int)1e9 ;
/************************************************************/

 
signed main(){
	int X, K, D ;
	cin >> X >> K >> D ;
	int n = min(abs(X) / D, K) ;
	int leftMoves = K - n ;
	// cerr << leftMoves << endl ;
	int curCord ;
	if( X <= 0 ){
		curCord = X + n*D ;
	}
	else{
		curCord = X - n*D ;
	}
	if( leftMoves % 2 == 0 ){
		cout << abs(curCord) ;
	}
	else{
		// cerr << curCord << endl ;
		cout << min( D + abs(curCord), abs( D - abs(curCord) ) ) ;
	}

	return 0 ;
}
  
