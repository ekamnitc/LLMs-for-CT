#include <iostream>
using namespace std;

char get_group(int a) {
    switch (a)
    {
    case 1: return 'a';
    case 2: return '2';
    case 3: return 'a';
    case 4: return 'b';
    case 5: return 'a';
    case 6: return 'b';
    case 7: return 'a';
    case 8: return 'a';
    case 9: return 'b';
    case 10: return 'a';
    case 11: return 'b';
    case 12: return 'a';
    default:
        return 'z';
    }
}
int main(void) {
    int x,y;cin>>x>>y;
    if (get_group(x) == get_group(y)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}