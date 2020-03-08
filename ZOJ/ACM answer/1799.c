#include <stdio.h>
#include <string.h>
int main()
{
	int a[11];
	char c;
	char str[12];
	char str1[102];
	char str2[102][102];
	int i,j,k,l,t,m,P1,P2,p,temp;
	while(1)
	{
		gets(str);
		if(strcmp(str,"THEEND")==0) break;
		m=0;
		while(1)
		{
			temp=0;
			for(i=0;i<strlen(str);i++)
			{
				if(str[i]!='c') break;
			}
			for(j=i;j<strlen(str);j++)
			{
				if(str[i]>str[j]&&str[j]!='c') {i=j;temp=1;}
			}
			if(temp==0) {str[i]='c';a[m]=i+1;}
			else
			{	
				str[i]='c';
				a[m]=i+1;
			}
			m++;
			if(m==strlen(str)) break;
		}
		gets(str1);
		P1=strlen(str1);
		P2=strlen(str);
		l=P1/P2; 
		m=0;
		for(i=0;i<strlen(str);i++)
		{
			k=0;
			for(j=m;j<m+l;j++)
			{
				str2[k++][a[i]-1]=str1[j];
			}
			m+=l;
		}
		for(i=0;i<l;i++)
		{
			for(j=0;j<strlen(str);j++)
			{
				printf("%c",str2[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}
