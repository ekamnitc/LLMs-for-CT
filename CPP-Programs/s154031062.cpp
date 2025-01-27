#include <iostream>
#include <string>

int main(){
   std::string S;
   std::cin >> S;
   bool b1, b2, b3;
   if (S.at(0) == 'A'){
      b1 = true;
   } else{
      b1 = false;
   }

   int cnt = 0;
   int N = S.size();
   for(int i=2; i<=N-2; i++){
      if (S.at(i) == 'C'){
         cnt++;
      }
   }
   if (cnt == 1){
      b2 = true;
   } else{
      b2 = false;
   }

   if ((S.at(1) <= 'z') && (S.at(1) >= 'a') && (S.at(N-1) <= 'z') && (S.at(N-1) >= 'a'))
      b3 = true;
   else
      b3 = false;

   bool b4 = true;
   for (int i=2; i<=N-2; i++){
      if (S.at(i) != 'C'){
         if ((S.at(i) >= 'a') && (S.at(i) >= 'z')){
            b4 = false;
         }
      }
   }

   if (b1 && b2 && b3 && b4){
      std::cout << "AC" << std::endl;
   } else{
      std::cout << "WA" << std::endl;
   }
}

