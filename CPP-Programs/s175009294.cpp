#include <stdio.h>

int main(){
	int A,B,C;
	scanf("%d %d %d", &A, &B, &C);
	int cnt = 0;
	for(int i = 1; i <= A; i++){
		int number = i;
		int sum = 0;
		while(number != 0){
			sum += number % 10;
			number /= 10;
		}
		if(sum >= B && sum <= C){
			cnt += i;
		}
		
	}
	printf("%d\n", cnt);
	
	return 0;
}