#include <stdio.h>
#include <string.h>

struct judgement
{
	char left[12];
	char right[12];
	short judge;
} list[5];

void init()
{
	char buf[5];
	for(int i=0; i<3; i++)
	{
		scanf("%s%s%s" , list[i].left ,list[i].right , buf);
		if(strcmp(buf , "even") == 0) list[i].judge = 0;
		else if(strcmp(buf , "up") == 0) list[i].judge = 1;
		else list[i].judge = -1;
	}
}

bool test(int k , int w)
{
	for(int i=0; i<3; i++)
	{
		int c = 0;
		for(int j=0; j<strlen(list[i].left); j++)
		{
			if(list[i].left[j] == k) c += w;
			else c += 1;

			if(list[i].right[j] == k) c -= w;
			else c -= 1;
		}
		if(c != list[i].judge) return 0;
	}
	return 1;
}

void solve()
{
	for(int i='A'; i<='L'; i++)
	{
		if(test(i , 0))
		{
			printf("%c is the counterfeit coin and it is light.\n" , i);
			return;
		}
		if(test(i , 2))
		{
			printf("%c is the counterfeit coin and it is heavy.\n" , i);
			return;
		}
	}
}

int main()
{
//	freopen("in.txt" , "r" , stdin);
	int T;
	scanf("%d" , &T);

	while(T--)
	{
		init();
//		printf("%d\n" , T);
		solve();
	}
	
	return 0;
}
