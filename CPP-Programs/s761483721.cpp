#include <iostream>
using namespace std;

int main(){
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;

    int internal_stu = 0;
    int international_stu = 0;
    int passed_stu = 0;
    for(size_t i = 0; i < s.size(); i++){
        if(s[i] == 'a') {
            if(passed_stu < a + b){
                internal_stu++;
                passed_stu = internal_stu + international_stu;
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }else if(s[i] == 'b'){
            if(passed_stu < a + b && international_stu < b){
                international_stu++;
                passed_stu = internal_stu + international_stu;
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }else{
            cout << "No" << endl;
        }
    }

}