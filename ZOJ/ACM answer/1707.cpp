//346443 2003-11-11 22:15:22 Wrong Answer 1707 C++ 00:00.00 380K just for play 
//348346 2003-11-13 11:41:37 Accepted 1707 C++ 00:00.00 380K just for play 
#include<stdio.h>
#include<string.h>

struct REPLACE
{
	char find[100];
	char replace[100];
};

REPLACE	inp[11];
int n;

void change(int k,char input[])
{
	int i,j;
	char res[300];
	int len1=strlen(inp[k].find);
	int len2=strlen(inp[k].replace);	
	int pt=0;
	while(1)
	{
		int len3=strlen(input);
		bool found=false;
		for(i=0;i<len3;i++)
		{
			for(j=0;j<len1;j++)
			{
				if(j+i>=len3)	break;
				if(input[i+j]!=inp[k].find[j])	break;
			}
			if(j==len1)
			{
				
				found=true;
				for(j=0;j<i;j++)
					res[j]=input[j];
				for(j=0;j<len2;j++)
					res[i+j]=inp[k].replace[j];
				int p=0;
				for(j=i+len1;j<len3;j++)
				{
					res[len2+i+p]=input[j];
					p++;
				}
				res[i+len2+p]='\0';
				
				strcpy(input,res);
				break;				
			}
		}
		if(!found)	break;
	}
}


int main()
{
//	freopen("1707.in","r",stdin);
	int i;	
	char tstr[5];
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)	break;
		gets(tstr);
		for(i=0;i<n;i++)
		{
			gets(inp[i].find);
			gets(inp[i].replace);
			
		}
		char input[300];
		gets(input);
		for(i=0;i<n;i++)
		{
			change(i,input);
		}
		printf("%s\n",input);
	}
	return 0;
}
