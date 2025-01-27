#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
int mod = (int) 1e9 + 7;

int main(){
    
    int n;
    cin >> n;
    
    n %= 10;
    
    if(n == 2 || n == 4 || n == 5 || n == 7 || n == 9){
        cout << "hon" << "\n";
    } else if(n == 0 || n == 1 || n == 6 || n == 8){
        cout << "pon" << "\n";
    } else {
        cout << "bon" << "\n";
    }
    
    return 0;
}
