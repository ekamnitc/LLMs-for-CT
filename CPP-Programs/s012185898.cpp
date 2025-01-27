#include <iostream>

using namespace std;

int main()
{
    int a , p , x , y;
    cin>> a>>p;
    x = a*3;
    y = x+p;
    if (y > 0) {
        cout<< y/2;
    }
    else {
        cout<< 0;
    }
    return 0;
}
