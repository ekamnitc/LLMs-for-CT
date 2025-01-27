using namespace std;
#include <iostream>
int main(){
    int r,d,x,m;
    cin>>r>>d>>x;
    for(int i=1;i<=10;i++){
        x=r*x-d;
        
        std::cout << x << std::endl;
    }
}
