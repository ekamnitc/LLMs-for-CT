#include <iostream>
#include <string>
using namespace std;

int main() {
  string str = "";
  bool leftFlag = false;
  int count = -1;
  int i = -1;
  while(str != "#") {
    cin >> str ;
    leftFlag = false;
    count = -1;
    i = -1;
    while(true) {
      i++;
      if(str[i] == '\0') break;
        if(str[i] < 'h') {
          if(leftFlag == false || count == -1) {
            count++;
            leftFlag = true;
          }
        } else if(str[i] < 'q' && str[i] >= 'h') {
          if(leftFlag == true || count == -1) {
            count++;
            leftFlag = false;
          }
        } else if(str[i] < 'u' && str[i] >= 'p') {
          if(leftFlag == false || count == -1) {
            count++;
            leftFlag = true;
          }
        } else if(str[i] == 'u' || str[i] == 'y') {
          if(leftFlag == true || count == -1) {
            count++;
            leftFlag = false;
          }
        } else {
          if(leftFlag == false || count == -1) {
            count++;
            leftFlag = true;
          }
        }
    }
    if(str != "#"){
      cout << count << endl;
    }

  }


}

