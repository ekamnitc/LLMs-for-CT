#include <iostream>

int main(){
   int X;
   std::cin >> X;
   int N = X/100;
   if ((N*100 <= X) && (X <= 105*N)){
      std::cout << 1 << std::endl;
   } else{
      std::cout << 0 << std::endl;
   }
}

