#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    char b;
    cin >> b;
    if (b == 'A'){ 
        println("T");
    }
    else if (b == 'T') {
        println("A");
    }
    else if (b == 'C') {
        println("G");
    }
    else if (b == 'G') {
        println("C");
    }
    return 0;
}