#include <iostream>
#include <utility>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;

//---- Print a Frame
int main(){
    int H,W;
    while(1){
        scanf("%d %d", &H, &W);
        if(H==0 && W==0){break;}
        for(int i=0; i<H; i++){
            if(i==0 || i==H-1){
                for(int j=0; j<W; j++){
                    printf("#");
                }
            }
            else{
                for(int j=0; j<W; j++){
                    if(j==0 || j==W-1){
                        printf("#");
                    }
                    else{
                        printf(".");
                    }
                }
            }
            
            printf("\n");
        }
        printf("\n");
    }
}