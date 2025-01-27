#include<stdio.h>
int main()
{
	int x,y,z;
	scanf("%d %d %d",&x,&y,&z);
	int num=0;
	int t=x-z;
	while(t-z>0)
	{
		if(t-y-z<0)
		break;
		else t-=(y+z);
		num++;
	}
	printf("%d\n",num);
	return 0;
}