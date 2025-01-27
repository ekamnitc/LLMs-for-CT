#include<stdio.h>
int main(){
	int i,n,j,k,o;
	scanf("%d",&o);
	int flag=1,flag1=1;
	int min,max;
	while(o--){
		scanf("%d",&n);
		if(flag){
			min=n;
			flag=0;
		}
		else if(!flag&&flag1){
			max=n-min;
			flag1=0;
			if(n<min)	min=n;
		}
		else if(!flag&&!flag1){
			if(n-min>max){
				max=n-min;
			}
			if(n<min){
				min=n;
			}
		}
	}
	printf("%d\n",max);
} 
