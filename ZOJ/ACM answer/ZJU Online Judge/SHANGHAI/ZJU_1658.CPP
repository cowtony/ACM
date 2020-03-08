#include <stdio.h>
#include <string.h>

struct board
{
	char s[6] , f[6];
	int vs , vf;
} list[11];

int g[5][64];

bool init()
{
	char buf[10];
	int i , j;

	scanf("%s" , buf);
	if(strcmp(buf , "END") == 0) return 0;

	strcpy(list[0].s , buf);
	
	for(i=1; i<10; i++)
	{
		scanf("%s" , list[i].s);		
	}

	memset(g , 0 , sizeof(g));

	for(i=0; i<10; i++)
	{
		for(j=0; j<5; j++)
			list[i].f[j] = list[i].s[4-j];
		list[i].vs = list[i].vf = 0;
		for(j=0; j<5; j++)
			list[i].vs += ( (list[i].s[j] == '1') * (1<<(4-j)) ) , 
			list[i].vf += ( (list[i].f[j] == '1') * (1<<(4-j)) ) ;

		for(j=0; j<5; j++)
		{
			g[4-j][list[i].vs >> j] ++;
			g[4-j][list[i].vf >> j] ++;
		}
	}
	
	return 1;
}

int ret;
bool used[11] , mark[11];
int c[5];

bool put(int k , char* s)
{
	for(int i=0; i<5; i++)
	{
		c[i] = (c[i] << 1) | (s[i] == '0');
		g[k][c[i]]--;
		if(g[k][c[i]] < 0)
		{
			for(; i>=0; i--)
			{
				g[k][c[i]]++;
				c[i] >>= 1;
			}
			return 0;
		}		
	}
	return 1;
}

void resume(int k)
{
	for(int i=0; i<5; i++)
	{
		g[k][c[i]] ++;
		c[i] >>= 1;
	}	
}

void kok(int k , int v)
{
	g[k][v >> (4-k)]--;
}

void back(int k , int v)
{
	g[k][v >> (4-k)]++;
}

int check()
{
	memcpy(mark , used , sizeof(used));
	for(int p=0; p<5; p++)
	{
		int i;
		for(i=0; i<10; i++)
			if(!mark[i] && (list[i].vf == c[p] || list[i].vs == c[p]))
			{
				mark[i] = 1;
				break;
			}
		if(i == 10) return 0;
	}
	return 1;
}

void search(int k)
{
	if(k == 5)
	{
	//	check(0);
		ret += check();
		return;
	}
	for(int i=0; i<10; i++)
		if(!used[i])
		{
			used[i] = 1;			

			kok(k , list[i].vs);
			kok(k , list[i].vf);
			
			if(put(k , list[i].s))
			{
				search(k + 1);
				resume(k);
			}

			if(list[i].vf != list[i].vs && put(k , list[i].f))
			{
				search(k + 1);
				resume(k);
			}

			back(k , list[i].vs);
			back(k , list[i].vf);

			used[i] = 0;
		}
}

void solve()
{
	ret = 0;

	memset(used , 0 , sizeof(used));
	memset(c , 0 , sizeof(c));

	search(0);

	printf("%d\n" , ret / 8);
}

int main()
{
//	freopen("in.txt" , "r" , stdin);

	while(init())
	{
		solve();
	}
	
	return 0;
}