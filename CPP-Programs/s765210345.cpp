#include<stdio.h>
int main(){
    
    int A, B, sum=0;
    scanf("%d%d", &A, &B);
    
    char S[A+B+1];
    scanf("%s", S);
    
    for(int i=0;i<A;i++){
    	if(S[i]<48 || S[i]>57){
    		printf("No");
    		return 0;
		}
	}
	if(S[A] != '-'){
		printf("No");
    	return 0;
	} 
	for(int i=A+1;i<A+B+1;i++){
    	if(S[i]<48 || S[i]>57){
    		printf("No");
    		return 0;
		}
	}
	printf("Yes");
    return 0;
}