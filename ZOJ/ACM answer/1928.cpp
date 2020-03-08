#include <stdio.h>
int main()
{
	int a1,a2,a3,a4;
	int temp;
	long degree;
	while(1)
	{
		scanf("%d%d%d%d",&a1,&a2,&a3,&a4);
		if(a1==0&&a2==0&&a3==0&&a4==0) break;
		degree=1080;
		temp=a1-a2;
		if(temp<0) temp+=40;
		degree+=temp*9;
		temp=a3-a2;
		if(temp<0) temp+=40;
		degree+=temp*9;
		temp=a3-a4;
		if(temp<0) temp+=40;
		degree+=temp*9;
		printf("%ld\n",degree);
	}
	return 0;
}
