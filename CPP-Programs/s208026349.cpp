#include <iostream>
#include<map>
using namespace std;
#define fin(ans) cout << (ans) << '\n'
int main()
{
    map<string, int> m;
    string temp,temp2,temp3;
    cin >> temp;
    cin >> temp2;
    cin >> m[temp];
    cin >> m[temp2];

    cin >> temp3;
    m[temp3]--;
    cout << m[temp] << " " << m[temp2] << endl;
    return 0;
}