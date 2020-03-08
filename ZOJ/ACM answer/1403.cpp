#include <string.h>
#include <stdio.h>
int main()
{
	char s[13],temp;
	int m;
	int len;
	int i,j,k,p,q;
	long t1,t2,t3,t4,t5;
	long tar;
	while(1)
	{
		scanf("%ld %s",&tar,s);
		if(strcmp(s,"END")==0) break;
		len=strlen(s);
		for(i=0;i<len-1;i++)
		{
			for(j=i+1;j<len;j++)
			{
				if(s[i]<s[j])
				{
					temp=s[i];
					s[i]=s[j];
					s[j]=temp;
				}
			}
		}
		m=0;
		for(i=0;i<len;i++)
		{
			for(j=0;j<len;j++)
			{
				for(k=0;k<len;k++)
				{
					for(p=0;p<len;p++)
					{
						for(q=0;q<len;q++)
						{
							if(i!=j&&i!=k&&i!=p&&i!=q)
							{
								if(j!=k&&j!=p&&j!=q)
								{
									if(k!=p&&k!=q&&p!=q)
									{
										t1=s[i]-64;
										t2=(s[j]-64)*(s[j]-64);
										t3=(s[k]-64)*(s[k]-64)*(s[k]-64);
										t4=(s[p]-64)*(s[p]-64)*(s[p]-64)*(s[p]-64);
										t5=(s[q]-64)*(s[q]-64)*(s[q]-64)*(s[q]-64)*(s[q]-64);
										if(tar==t1-t2+t3-t4+t5)
										{
											m=1;
											printf("%c%c%c%c%c\n",s[i],s[j],s[k],s[p],s[q]);
										}
									}
								}
							}
							if(m==1) break;
						}
						if(m==1) break;
					}
					if(m==1) break;
				}
				if(m==1) break;
			}
			if(m==1) break;
		}
		if(m==0) printf("no solution\n");
	}
	return 0;
}


