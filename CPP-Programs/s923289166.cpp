#include <iostream>
#include <vector>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int c = b-a;
    int ans = c * (c+1);
    ans /= 2;
    ans -= b;
    cout << ans << endl;
    return 0;
}