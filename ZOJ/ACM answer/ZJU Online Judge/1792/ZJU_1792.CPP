#include <stdio.h>
#include <string.h>

#define maxlen 502
char s1[maxlen] , s2[maxlen];
int len1 , len2;
int f[maxlen][maxlen][2][2];

void read_string(char s[] , int& len)
{
	len = 0;
	char ch;
	while(1)
	{
		ch = getchar();
		if(ch == 'A' || ch == 'T' || ch == 'C' || ch == 'G') break;
	}
	s[0] = '#';
	while(ch == 'A' || ch == 'T' || ch == 'C' || ch == 'G')
	{
		s[++len] = ch;
		ch = getchar();
	}
}

inline int max(int a , int b)
{
	return a > b ? a : b;
}

inline void renew(int& c , int p)
{
	if(p > c) c = p;
}

void solve()
{	
	int i , j , p;
	int up , down , up0 , down0;
	int gain;

	for(i=0; i<=len1; i++)
		for(j=0; j<=len2; j++)
			f[i][j][0][0] = f[i][j][0][1] = f[i][j][1][0] = f[i][j][1][1] = -10000000;
	f[0][0][0][0] = 0;
	
	for(i=0; i<=len1; i++)
	{
		for(j=0; j<=len2; j++)
		{
			for(up0=0; up0<2; up0++)
				for(down0=0; down0<2; down0++)
				{
					if(up0 && down0) continue;
					if(f[i][j][up0][down0] > -10000000)
					{
						for(up=0; up<2; up++)
							for(down=0; down<2; down++)
							{
								if(up && down) continue;
								gain = 0;
								if(up && !up0) gain = -4;
								if(down && !down0) gain = -4;
								
								if(up || down || s1[i+1] != s2[j+1]) gain--;
								else gain += 2;
								renew(f[i+1-up][j+1-down][up][down] , f[i][j][up0][down0] + gain);
							}
					}
				}
		}
	}

	printf("%d\n" , max(max(f[len1][len2][0][0] , f[len1][len2][1][0]) , f[len1][len2][0][1]));
}

int main()
{
	freopen("in.txt" , "r" , stdin);
	int T;
	scanf("%d" , &T);

	while(T--)
	{
		read_string(s1 , len1);
		read_string(s2 , len2);
		solve();
	}

	return 0;
}