#include <stdio.h>
#include <string.h>
int main()
{
	char a[5000];
	long b[5000];
	long i;
	int len;
	long l;
	while(gets(a))
	{
		if(strcmp(a,"0")==0) break;
		len=strlen(a);
		if(len==1) {printf("1\n");continue;}
		if(a[len-1]>'0') b[0]=1;
		else b[0]=0;
		if(a[len-2]>'2')    b[1]=1;
		else if(a[len-2]=='1') 
		{
			if(a[len-1]=='0') b[1]=1;
			else b[1]=2;
		}
		else if(a[len-2]=='2')
		{
			if(a[len-1]>'6') b[1]=1;
			else 
			{
				if(a[len-1]=='0') b[1]=1;
				else b[1]=2;
			}
		}
		else b[1]=0;
		if(len==2) {printf("%ld\n",b[1]);continue;}
		l=2;
		for(i=len-3;i>=0;i--)
		{
			if(a[i]=='0') b[l]=0;
			else if(a[i]=='1') b[l]=b[l-1]+b[l-2];
			else if(a[i]>'2') b[l]=b[l-1];
			else
			{
				if(a[i+1]>'6') b[l]=b[l-1];
				else b[l]=b[l-1]+b[l-2];
			}
			l++;
		}
		printf("%ld\n",b[l-1]);
	}
	return 0;
}



