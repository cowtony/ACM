#include <iostream>
#include <deque>
using namespace std;
char ch[10000];
int main()
{
	int cas;
	int L;
	int i, j, k;
	char c;
	scanf("%d", &cas);
	while(cas--)
	{
		int count = 0;
		int xixi = 0;
		scanf("%d", &L);
		while(scanf("%c", &c))
		{
			if(c== '\n') break;
		}
		int index = 0;
		while(1)
		{
			if(count == L) break;
			scanf("%c", &ch[index]);
			if(ch[index] == '\n') count++;
			index++;
		}
		int t = 0;
		for(i=0; i<index-1; i++)
		{
			if(ch[i] == '/' && ch[i+1] == '*')
			{
				for(j=i+2; j<index-1; j++)
				{
					if(ch[j] == '*' && ch[j+1] == '/')
					{
						t = 1;
						break;
					}
				}
				if(t==1)
				{
					xixi++;
					for(k=i; k<=j+1; k++)
					{
						if(ch[k] >= 'a' && ch[k] <= 'z')
						{
							ch[k] = ch[k] - 32;
						}
					}
					i = j+1;
					t = 0;
				}
				else
				{
					for(k=i; k<index-1; k++)
					{
						if(ch[k] == '/' && ch[k+1] == '/'&& t== 0) {t=1;xixi++;}
						if(ch[k] == '\n') t = 0;
						if(t == 1 && ch[k] >= 'a' && ch[k] <= 'z')
						{
							ch[k] = ch[k] - 32;
						}
					}
				}
			}
			else if(ch[i] == '/' && ch[i+1] == '/')
			{
				t = 1;
				xixi++;
				for(j=i; ; j++)
				{
					if(ch[j] >= 'a' && ch[j] <= 'z' && t == 1)
					{
						ch[j] = ch[j] - 32;
					}
					if(ch[j] == '\n') {t=0; i=j; break;}
				}
			}
		}
		printf("%d\n", xixi);
		for(i=0; i<index; i++)
		{
			printf("%c", ch[i]);
		}
		printf("\n");
	}
	return 0;
}