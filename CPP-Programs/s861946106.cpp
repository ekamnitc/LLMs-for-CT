#include <string>
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    
    int total = a * b;
    if(total%2){
        cout << "Odd";
    } else {
        cout << "Even";
    }

    return 0;
}