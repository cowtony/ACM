#include <stdio.h>
#include <string.h>

struct player
{
	char v[10];
	char s[10];
} a , b;

bool read(player& a)
{
	int i , j;
	for(i=0; i<5; i++)
	{
		if(scanf("%1s%1s" , &a.v[i] , &a.s[i]) < 0) return 0;
		if(a.v[i] >= '0' && a.v[i] <= '9') a.v[i] = a.v[i] - '0';
		else if(a.v[i] == 'T') a.v[i] = 10;
		else if(a.v[i] == 'J') a.v[i] = 11;
		else if(a.v[i] == 'Q') a.v[i] = 12;
		else if(a.v[i] == 'K') a.v[i] = 13;
		else if(a.v[i] == 'A') a.v[i] = 14;
	}
	for(i=0; i<5; i++)
		for(j=i+1; j<5; j++)
			if(a.v[i] < a.v[j])
			{
				int t;
				t = a.v[i]; a.v[i] = a.v[j]; a.v[j] = t;
				t = a.s[i]; a.s[i] = a.s[j]; a.s[j] = t;
			}
	return 1;
}

void check_card_2(const player& a , int& len , int list[])
{
	if(a.v[0] == a.v[1] && a.v[2] == a.v[3])
	{
		len = 3;
		list[0] = a.v[0];
		list[1] = a.v[2];
		list[2] = a.v[4];
		return;
	}

	if(a.v[0] == a.v[1] && a.v[3] == a.v[4])
	{
		len = 3;
		list[0] = a.v[0];
		list[1] = a.v[3];
		list[2] = a.v[2];
		return;
	}

	if(a.v[1] == a.v[2] && a.v[3] == a.v[4])
	{
		len = 3;
		list[0] = a.v[1];
		list[1] = a.v[3];
		list[2] = a.v[0];
		return;
	}

	int i , j , k;
	for(i=0; i<=3; i++)
	{
		if(a.v[i] == a.v[i+1])
		{
			len = 4;
			list[0] = a.v[i]; k = 0;
			for(j=0; j<i; j++)
				list[++k] = a.v[j];
			for(j=i+2; i<5; i++)
				list[++k] = a.v[j];
			return;
		}
	}

	len = 5;
	for(i=0; i<5; i++)
		list[i] = a.v[i];
}

void solve_2()
{
	int la[6] , lb[6] , len_a , len_b;
	check_card_2(a , len_a , la);
	check_card_2(b , len_b , lb);

	if(len_a < len_b) puts("Black wins.");
	else if(len_a > len_b) puts("White wins.");
	else
	{
		for(int i=0; i<len_a; i++)
			if(la[i] != lb[i])
			{
				if(la[i] > lb[i]) puts("Black wins.");
				else puts("White wins.");
				return ;
			}
		puts("Tie.");
	}
}

bool check_straight_flush(const player& a)
{
	int i;
	for(i=1; i<5; i++)
	{
		if(a.s[i] != a.s[0]) return 0;
		if(a.v[i] + i != a.v[0]) return 0;
	}
	return 1;
}

void check_card(const player& a , int& p , int& r)
{
	//Type 0 : Straight Flush 同花顺
	if(check_straight_flush(a))
	{
		p = 0; r = a.v[0]; return;
	}
	//Type 1 : Four of a kind 炸弹
	if(a.v[0] == a.v[1] && a.v[0] == a.v[2] && a.v[0] == a.v[3])
	{
		p = 1; r = a.v[0]; return;
	}
	if(a.v[1] == a.v[2] && a.v[1] == a.v[3] && a.v[1] == a.v[4])
	{
		p = 1; r = a.v[1]; return;
	}

	//Type 2 : Full House 三加二
	if(a.v[0] == a.v[1] && a.v[0] == a.v[2] && a.v[3] == a.v[4])
	{
		p = 2; r = a.v[0]; return;
	}
	if(a.v[0] == a.v[1] && a.v[2] == a.v[3] && a.v[2] == a.v[4])
	{
		p = 2; r = a.v[2]; return;
	}

	//Type 3 : Flush 同花
	if(a.s[0] == a.s[1] && a.s[0] == a.s[2] && a.s[0] == a.s[3] && a.s[0] == a.s[4])
	{
		p = 3; r = a.v[0]; return;
	}

	//Type 4 : Straight 顺子
	if(a.v[0] == a.v[1] + 1 && a.v[0] == a.v[2] + 2 && a.v[0] == a.v[3] + 3 && a.v[0] == a.v[4]+ 4)
	{
		p = 4; r = a.v[0]; return;
	}

	//Type 5 : Three of a kind
	if(a.v[0] == a.v[1] && a.v[0] == a.v[2])
	{
		p = 5; r = a.v[0]; return;
	}

	if(a.v[1] == a.v[2] && a.v[1] == a.v[3])
	{
		p = 5; r = a.v[1]; return;
	}

	if(a.v[2] == a.v[3] && a.v[2] == a.v[4])
	{
		p = 5; r = a.v[2]; return;
	}

	p = 6; r = 0;
}

void solve()
{
	int pa , ra;
	int pb , rb;

	check_card(a , pa , ra);
	check_card(b , pb , rb);

	if(pa == pb && pa == 3)
	{
		for(int i=0; i<5; i++)
		{
			if(a.v[i] != b.v[i])
			{
				if(a.v[i] > b.v[i]) puts("Black wins.");
				else puts("White wins.");
				return;
			}
		}

		puts("Tie.");
		return;
	}

	if(pa < pb || (pa == pb && ra > rb) ) puts("Black wins.");
	else if (pa > pb || (pa == pb && ra < rb)) puts("White wins.");
	else 
	{
		if(pa == pb && ra == rb && pa < 6)
		{
			puts("Tie.");
		}
		else solve_2();		
	}
}

int main()
{
	//freopen("q1111.in" , "r" , stdin);
	while(1)
	{
		if(!read(a)) break;
		if(!read(b)) break;

		solve();
	}
	return 0;
}
