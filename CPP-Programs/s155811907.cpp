#include <iostream>
#include <string>
using namespace std;

int main(){
    int A[3][3];
    int B;
    bool mark[3][3]={0};
    string ans="No";
    int i,j,k;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            cin >> A[i][j];
        }
    }
    int N;
    cin >> N;

    for(k=0; k<N; k++){
        cin >> B;
        for(i=0; i<3; i++){
            for(j=0; j<3; j++){
                if(A[i][j]==B) mark[i][j]=true;
            }
        }
    }

    for(i=0; i<3; i++){
        if(mark[i][0] && mark[i][1] && mark[i][2]) ans="Yes";
        if(mark[0][i] && mark[1][i] && mark[2][i]) ans="Yes";
    }
    if(mark[0][0] && mark[1][1] && mark[2][2]) ans="Yes";
    if(mark[0][2] && mark[1][1] && mark[2][0]) ans="Yes";    

    cout << ans << endl;

    return 0;
}