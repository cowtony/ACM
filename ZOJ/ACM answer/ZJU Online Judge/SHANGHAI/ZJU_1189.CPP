#include <stdio.h>
#include <string.h>

char buf[100];
char s[20][100];

int cnt[256];

void solve()
{
	strcpy(s[0] , buf);
	int i , j , k , len;
	
	for(i=0; i<16; i++)
	{
		memset(cnt , 0 , sizeof(cnt));
		len = strlen(s[i]);
		for(j=0; j<len; j++)
			cnt[s[i][j]]++;
		k = 0;
		for(j='0'; j<='9'; j++)
		{
			if(cnt[j])
			{
				if(cnt[j] >= 10)
				{	
					s[i+1][k++] = cnt[j]/10+'0';
					cnt[j] %= 10;
				}
				s[i+1][k++] = cnt[j] + '0';
				s[i+1][k++] = j;
			}			
		}
		s[i+1][k] = 0;
		if(strcmp(s[i+1] , s[i]) == 0)
		{
			if(i == 0) printf("%s is self-inventorying\n" , buf);
			else printf("%s is self-inventorying after %d steps\n" , buf , i);
			return;
		}
		if(i == 15) break;
		for(j=0; j<i; j++)
			if(strcmp(s[i+1] , s[j]) == 0)
			{
				printf("%s enters an inventory loop of length %d\n" , buf , i+1-j);
				return;
			}
	}

	printf("%s can not be classified after 15 iterations\n" , buf);
}

int main()
{
//	freopen("in.txt" , "r" , stdin);
	int T , t;
	scanf("%d" , &T);

	for(t=0; t<T; t++)
	{
		if(t) putchar('\n');
		while(1)
		{
			scanf("%s" , buf);
			if(buf[0] == '-') break;
			solve();
		}
	}
	
	return 0;
}
