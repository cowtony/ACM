//260809 2003-08-16 21:25:37 Accepted 1512 C++ 00:00.00 776K just for play 
#include<stdio.h>
#include<string.h>

struct NUM
{
	int dig[500];
	int bit;
	NUM()
	{bit=0;}
	void output()
	{
		int i;
		while(bit>0&&dig[bit-1]==0)	bit--;
		for(i=bit-1;i>=0;i--)
			printf("%d",dig[i]);
		printf("\n");
	}
	void add(NUM num)
	{
		int i=0,left=0;
		int tt;
		while(i<num.bit&&i<bit)
		{			
			tt=num.dig[i]+dig[i]+left;
			dig[i]=tt%10;
			left=tt/10;
			i++;
		}
		if(i>=num.bit)
		{
			while(i<bit)
			{
				tt=dig[i]+left;
				dig[i]=tt%10;
				left=tt/10;
				i++;
			}
			if(left>0){dig[bit]=left;bit++;}
		}
		else if(i>=bit)
		{
			bit=num.bit;
			while(i<num.bit)
			{
				tt=num.dig[i]+left;
				dig[i]=tt%10;
				left=tt/10;
				i++;
			}
			if(left>0){dig[bit]=left;bit++;}
		}			
	}	
	void input()
	{
		char ch[100];
		scanf("%s",ch);
		
		int len=strlen(ch);
		int i;
		for(i=len-1;i>=0;i--)
			dig[len-1-i]=ch[i]-'0';
		bit=len;
	}
};			




int main()
{
	NUM a[101],b[101];
	a[1].bit=1;a[1].dig[0]=1;
	b[1].bit=1;b[1].dig[0]=0;
	int i;
	for(i=2;i<101;i++)
	{
		a[i].add(a[i-1]);a[i].add(a[i-1]);a[i].add(b[i-1]);
		
		b[i].add(a[i-1]);b[i].add(b[i-1]);
	}
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		NUM temp=a[n];
		temp.add(b[n]);
		temp.output();
	}
	return 0;
}

