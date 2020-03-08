#include <stdio.h>
#include <string.h>

int main()
{
	int a[26][101];
	char s1[1001];
	char s2[101];
	int i,j,k,l1,l2,s2len;
	int temp1;
	int t2,result,t1;
	int cha;
	while(gets(s1))
	{
		for(i=0;i<26;i++)
		{
			a[i][0]=0;
		}
		for(i=0;;i++)
		{
			scanf("%c",&s2[i]);
			if(s2[i]=='\n') break;
			temp1=s2[i]-97;
			a[temp1][0]++;
			a[temp1][a[temp1][0]]=i;
		}
		s2len=i;
		result=0;
		cha=strlen(s1)-s2len;
		for(i=0;i<=cha;i++)
		{
			temp1=s1[i]-97;
			for(j=1;j<=a[temp1][0];j++)
			{
				l1=i;
				k=a[temp1][j];
				l2=k;
				t1=0;
				for(;l2<s2len;l2++)
				{
					if(s1[l1++]!=s2[l2]) {t1=1;break;}
				}
				t2=0;
				if(l2==s2len)
				{
					for(l2=0;l2<k;l2++)
					{
						if(s1[l1++]!=s2[l2]) {t2=1;break;}
					}
				}
				if(!t1&&!t2) {result++;break;}
			}
		}
		printf("%d\n",result);
	}
	return 0;
}


