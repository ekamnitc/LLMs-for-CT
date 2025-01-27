#include<stdio.h>
#include<string.h>
int main(){
	int k;
	char kata[255];
	scanf("%d",&k);
	getchar();
	
	scanf("%[^\n]", &kata);
	int s = strlen(kata);
	
	for(int i= 0; i < k && kata[i] != '\0'; i++){
		printf("%c", kata[i]);
	}
	if(s>k){
		printf("...");
	}
	return 0;
}