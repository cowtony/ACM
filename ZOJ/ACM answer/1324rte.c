#include <stdio.h>
#include <string.h>
int main()
{
	char a[100][61];
	char str[61];
	int i,j,num,p2,p3,row,t,l,k;
	int maxlen,column,left;
	while(scanf("%d%*c",&num)!=EOF)
	{
		maxlen=0;
		for(i=0;i<num;i++)
		{
			gets(a[i]);
			if(strlen(a[i])>maxlen) maxlen=strlen(a[i]);
		}
		for(i=0;i<num-1;i++)
		{
			for(j=i+1;j<num;j++)
			{
				if(strcmp(a[i],a[j])>0) 
				{
					strcpy(str,a[i]);
					strcpy(a[i],a[j]);
					strcpy(a[j],str);
				}
			}
		}
		column=60/(maxlen+2);
		left=60-column*(maxlen+2);
		p2=num%(1+column);
		if(p2!=0) p2=1;
		row=num/(1+column)+p2;
		t=row*column;
		while(t<num)
		{
			for(i=t;i<num;i++)
			{
				if(strlen(a[i])>left) break;
			}
			if(i<num) 
			{
				if((i-t+1)%column==0)
				{
					row+=(i-t+1)/column;
					t=i+1;
				}
				else
				{
					p3=(i-t+1)/column+1;
					row+=p3;
					t=i+column*p3;
				}
			}
			else break;
		}
		printf("------------------------------------------------------------\n");
		for(i=0;i<row;i++)
		{
			l=i;
			while(l<num)
			{
				printf("%s",a[l]);
				if(l<row*(column-1))
				{
					for(k=0;k<(maxlen-strlen(a[l]+2))&&(l+row)<num;k++)
						printf(" ");
				}
				l+=row;
			}
			printf("\n");
		}
	}
	return 0;
}
