#include <stdio.h>
#include <string.h>

#define maxlen 1000

int n , k;
bool g[30][30];
int deg[30];

char word[2][maxlen];
int len[2];
char s[maxlen];
int leng;
char table[30] , p[30];

void init()
{
	scanf("%d%d" , &n , &k);
	memset(g , 0 , sizeof(g));
	memset(deg , 0 , sizeof(deg));

	scanf("%s" , word[0]); len[0] = strlen(word[0]);
	int curt , next;
	int i , j;	

	curt = 0;
	for(i=1; i<k; i++)
	{
		next = 1 - curt;
		scanf("%s" , word[next]);
		len[next] = strlen(word[next]);

		for(j=0; j<len[curt]; j++)
			if(word[0][j] != word[1][j]) break;
		if(j < len[curt])
		{			
			g[word[curt][j]-'a'][word[next][j]-'a'] = 1;		
		}
		curt = next;
	}
	gets(s);
	gets(s);
	leng = strlen(s);
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			if(g[i][j]) deg[j]++;
}

void solve()
{

	int cnt , i , j , k;
	for(i=0; i<n; i++)
	{
		for(j=cnt=0; j<n; j++)
			if(deg[j] == 0)
			{
				cnt++;
				k = j;			
			}
		if(cnt != 1)
		{
			puts("Message cannot be decrypted.");
			
			return;
		}
		deg[k] = -1;
		for(j=0; j<n; j++)
			if(g[k][j]) --deg[j];
		table[i] = k;
		p[k] = i;
	}


	
	for(i=0; i<leng; i++)
	{
		if(s[i] < 'a' || s[i] - 'a' >= n) putchar(s[i]);
		else putchar(p[s[i]-'a'] + 'a');
	}

	putchar('\n');
}

int main()
{

	int T;
	scanf("%d" , &T);

	while(T--)
	{
		init();
		solve();
	}
	 
	return 0;
}