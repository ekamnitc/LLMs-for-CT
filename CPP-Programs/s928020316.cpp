#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    int t_score = 0;
    int h_score = 0;
    
    for (int i = 0; i < n; i++) {
        std::string t_card;
        std::cin >> t_card;
  
        std::string h_card;
        std::cin >> h_card;
        
        if(t_card > h_card)
            t_score+=3;
        if(h_card > t_card)
            h_score+=3;
        if(t_card == h_card){
            t_score++;
            h_score++;
        }
    }
    std::cout << t_score << " " << h_score << std::endl;
            
    return 0;
}