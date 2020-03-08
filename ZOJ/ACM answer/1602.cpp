//177601 2003-06-22 23:09:48 Wrong Answer 1602 C++ 00:00.00 376K just for play 
//177607 2003-06-22 23:20:21 Wrong Answer 1602 C++ 00:00.00 376K just for play 
#include<stdio.h>


int main()
{
	int n,num[101];
	while(scanf("%d",&n)!=EOF)
	{
		int i;

		for(i=0;i<n;i++)	scanf("%d",&num[i]);		
		//for(i=0;i<n;i++)	num[i]=100;
		int min_num=1000,min_pt;
		for(i=0;i<n;i++)
			if(num[i]<min_num){min_num=num[i];min_pt=i;}
		int total=0;
		for(i=min_pt-1;i>0;i--)
			total+=min_num*num[i]*num[i-1];
		for(i=min_pt+1;i<n-1;i++)
			total+=min_num*num[i]*num[i+1];
		if(min_pt!=0&&min_pt!=n-1)	total+=min_num*num[0]*num[n-1];
		printf("%d\n",total);
	}
	return 0;
}
			





