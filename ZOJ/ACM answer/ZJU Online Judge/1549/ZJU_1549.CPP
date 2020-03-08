#include <stdio.h>
#include <string.h>

//typedef __int64 int64;
typedef long long int64;

char s[20];
char s2[20];
int m , len;

int64 power(int p)
{
	int64 ret = 1;
	while(p--) ret *= 10;
	return ret;
}

int64 calc(int len)
{
	int64 ret = 1 + (s[0] - '0' - 1) * power(len - 1);
	for(int i=1; i<len; i++)
	{
		ret += (s[i] - '0') * power(len - i - 1);
	}
	return ret;
}

void solve()
{
	int64 curt , ps , d;
	int i , p;
	// 计算比k小 且 字母序优先于k的数的个数P

	curt = 0;
	for(i=len; i; i--)
	{
		curt += calc(i);
	}

	// 若P > M 无解; P = M 答案就是 k; P > M 将是一个位数大于k的数

	if(curt == m)
	{
		puts(s);
		return;
	}
	if(curt > m || curt == len)
	{
		puts("0"); return;
	}


	// 先计算N的位数 , 逐位精确
	
	m -= curt;
	curt = calc(len) - 1;

	memset(s2 , 0 , sizeof(s2));
	for(p=1; ;p++)
	{
		ps = curt * power(p);
		if(m <= ps)
		{			
			for(i=0; i<len; i++)
			{
				s2[i] = '0'; if(i == 0) s2[i] = '1';
				d = power(len - i - 1 + p);
				while(m > d)
				{
					s2[i]++;
					m -= d;
				}
			}
			m--;
			for(p--; p>=0; p--)
			{
				s2[len + p] = (m % 10) + '0';
				m /= 10;
			}
			
			puts(s2);
			
			break;
		}	
		m -= ps;
	}


	
}

int main()
{
//	freopen("amusing.in" , "r" , stdin);
//	freopen("out.txt" , "w" ,stdout);

	while(scanf("%s%d" , s , &m) >= 0)
	{
		len = strlen(s);
		solve();
	}
	
	return 0;
}