#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
int main() {
    int W,H,N;
    cin >> W >> H >> N;
     vector<vector<int>> area(H, vector<int>(W));  // 初期値は0
     for (int i =0; i<N; i++){
         int x,y,a;
         cin >> x >> y >> a;
         
         if(a==1){
             for(int i=0;i<x;i++){
                 for(int j=0;j<H;j++){
                     area.at(j).at(i) = 1;
                 }
                }
            }
         if(a==2){
             for(int i=x;i<W;i++){
                 for(int j=0;j<H;j++){
                     area.at(j).at(i) = 1;
                 }
             }
         }
         if(a==3){
             for(int i=0;i<W;i++){
                 for(int j=0;j<y;j++){
                     area.at(j).at(i) = 1;
                 }
             }
         }
         if(a==4){
             for(int i=0;i<W;i++){
                 for(int j=y;j<H;j++){
                     area.at(j).at(i) = 1;
                 }
             }
         }
     }
     int count =0;
     for(int i=0;i<H;i++){
         for(int j=0;j<W;j++){
             if(area.at(i).at(j) == 0){
                 count++;
             }
         }
     }
     cout << count << endl;
}