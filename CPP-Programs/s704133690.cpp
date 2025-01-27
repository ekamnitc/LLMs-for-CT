#include <iostream>

int main()
{
	int H, W;
	std::cin >> H >> W;

	while (H != 0 || W != 0) {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if ((i + j) % 2) {
					std::cout << ".";
				}
				else {
					std::cout << "#";
				}
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		std::cin >> H >> W;
	}
}