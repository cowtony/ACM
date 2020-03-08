#include <stdio.h>
#include <string.h>
int main()
{
	char a[7];
	char b[26],c;
	int i,j,t1,t2;
	int cas;
	scanf("%d%*c",&cas);
	while(cas--)
	{
		gets(a);
		gets(b);
		for(i=strlen(a)-1;i>=0;i--)
		{
			t2=strlen(b);
			switch(a[i])
			{
			case 'J':
				{
					c=b[t2-1];
					for(j=t2-1;j>0;j--)
					{
						b[j]=b[j-1];
					}
					b[0]=c;
					//puts(b);
					break;
				}
			case 'C':
				{
					c=b[0];
					for(j=0;j<t2-1;j++)
					{
						b[j]=b[j+1];
					}
					b[j]=c;
					break;
				}
			case 'E':
				{
					t1=t2%2;
					t2=t2/2;
					for(j=0;j<t2;j++)
					{
						c=b[j];
						b[j]=b[j+t1+t2];
						b[j+t1+t2]=c;
					}
					break;
				}
			case 'A':
				{
					for(j=0;j<t2/2;j++)
					{
						c=b[j];
						b[j]=b[t2-1-j];
						b[t2-1-j]=c;
					}
					//puts(b);
					break;
				}
			case 'P':
				{
					for(j=0;j<t2;j++)
					{
						if(b[j]=='0') b[j]='9';
						else if(b[j]>'0'&&b[j]<='9') b[j]--;
					}
					//puts(b);
					break;
				}
			case 'M':
				{
					for(j=0;j<t2;j++)
					{
						if(b[j]=='9') b[j]='0';
						else if(b[j]>='0'&&b[j]<'9') b[j]++;
					}
					//puts(b);
					break;
				}
			default: break;
			}
		}
	puts(b);
	}
	return 0;
}



