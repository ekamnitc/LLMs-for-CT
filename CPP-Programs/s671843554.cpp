#include <bits/stdc++.h>
using namespace std;

#define print cout <<
#define printl(s) cout << s << endl;
#define rep(i,n) for (int i = 0; i < (n); ++i)

template <typename T>
vector<T> getValues(int num){
    vector<T> values(num);
    for(int i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

int main(){
    auto inputs = getValues<int>(5);
    int ans = 0;
    rep(i,inputs.size()){
      if(inputs.at(i)==0){
        ans = i+1;
        break;
      }
    }
    printl(ans);
}
