#include <iostream>
using namespace std;
int main(void){
    
    int H, W;
    cin >> H >> W;
    char a[102][102];
    
    for(int i = 0; i <= H+1; i++){
        for(int j = 0; j <= W+1; j++){
            if(i == 0 || i == H+1 || j == 0 || j == W+1) a[i][j] = '#';
            else cin >> a[i][j];
            
        }
    }
    
    for(int i = 0; i <= H+1; i++){
        for(int j = 0; j <= W+1; j++){
            cout  << a[i][j];
        }cout << endl;
    }
 
} 