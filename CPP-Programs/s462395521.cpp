#include <stdio.h>
int main(){
	char date[15];
	scanf("%s", &date);
	date[3] += 1;
	printf("%s", date);
	return 0;
}
