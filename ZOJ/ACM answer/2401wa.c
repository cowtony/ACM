#include <stdio.h>
#include <string.h>
int main()
{
	char str[203],str1[203],str2[406];
	int i;
	int cas,t=0,count;
	int m,n,p,l;
	scanf("%d%*c",&cas);
	while(cas--)
	{
		scanf("%s %s %s",str,str1,str2);
		count=0;
		m=strlen(str);
		n=strlen(str1);
		p=strlen(str2);
		str[m]='1';
		str[m+1]='2';
		str1[n]='3';
		str1[n+1]='4';
		l=0;
		m=0;
		for(i=0;i<p;i++)
		{
			if(str2[i]==str[l]&&str2[i]!=str1[m])
			{
				l++;
				count++;
			}
			else if(str2[i]==str1[m]&&str2[i]!=str[l])
			{
				m++;
				count++;
			}
			else if(str2[i]==str1[m]&&str2[i]==str[l])
			{
				if(str2[i+1]==str1[m+1])
				{
					m++;
					count++;
				}
				else 
				{
					l++;
					count++;
				}
			}
			else break;
		}
		if(count==p) printf("Data set %d: yes\n",++t);
		else printf("Data set %d: no\n",++t);
	}
	return 0;
}