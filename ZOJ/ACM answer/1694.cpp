//392363 2003-12-10 22:30:27 Accepted 1694 C++ 00:00.00 380K just for play 
#include<stdio.h>
#include<string.h>

bool	unique=true;
int		max=-1;
int		val[10];
int n;char str[10];

bool	valid(int curval[])
{
	return true;
	int i;
	for(i=1;i<strlen(str);i++)
	{
		if(str[i]=='0'&&(curval[i-1]==1&&curval[i]==0))	return false;
	}
	return true;
}

int cal_val(int curval[])
{
	int tsum=0;
	int i;int tt=0;
	for(i=0;i<strlen(str);i++)
	{
		tt=tt*10+str[i]-'0';
		if(curval[i]==1)
		{
			tsum+=tt;
			tt=0;
		}
	}
	return tsum;
}

void try_put(int curval[],int cur)
{
	int i;
	if(cur==strlen(str))
	{
		if(valid(curval))	
		{
			int tsum=cal_val(curval);
			if(tsum==max)	unique=false;
			if(tsum>max&&tsum<=n)
			{
				unique=true;
				max=tsum;
				for(i=0;i<strlen(str);i++)	val[i]=curval[i];
			}
		}
		return ;
	}
	curval[cur]=1;
	try_put(curval,cur+1);
	if(cur==strlen(str)-1)	return;	
	curval[cur]=0;
	try_put(curval,cur+1);
}
bool	search_num()
{
	int curval[10];
	try_put(curval,0);
	if(unique)	return true;
	return false;
}
int main()
{
//	freopen("1694.in","r",stdin);
	while(scanf("%d %s",&n,str)!=EOF)
	{
		int i;
		if(n==0&&strcmp(str,"0")==0)	break;
		int min=0;
		int len=strlen(str);
		for(i=0;i<len;i++)
			min+=str[i]-'0';
		if(min>n)
		{
			printf("error\n");
			continue;
		}
		max=-1;unique=true;
		if(search_num())
		{
			printf("%d ",max);
			for(i=0;i<len;i++)
			{
				printf("%c",str[i]);
				if(val[i]==1&&i!=len-1)				
					printf(" ");
				
			}
			printf("\n");
		}else	printf("rejected\n");
	}
	return 0;
}

