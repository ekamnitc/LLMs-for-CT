#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define REP1(i,n) for(int i=1;i<=(int)(n);i++)
#define RREP(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<b;i++)

int main(){
  int H,W;
  cin >> H >> W;
  bool elmnt;
  vector<bool> hcheckline(H),wcheckline(W);
  vector<vector<char>>data(H,vector<char>(W));
  REP(i,H){
    REP(j,W)cin >> data.at(i).at(j);
  }

  REP(i,H){
    elmnt=1;
    REP(j,W){
      if(data.at(i).at(j)=='#'){
	elmnt=0;
	wcheckline.at(j)=1;
      }
    }
    if(elmnt==0)hcheckline.at(i)=1;
  }

  //output
  REP(i,H){
    if(hcheckline.at(i)==1){
      REP(j,W){
	if(wcheckline.at(j)==1){
	  cout << data.at(i).at(j);
	}
      }
      cout << endl;
    }
  }
}
