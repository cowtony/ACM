#include <stdio.h>
#include <string.h>

#define max_len 10010

char s[max_len * 2];
int len;

void solve()
{
	int p1 , p2 , k , i;

	len = strlen(s);
	for(i=0; i<len; i++)
		s[i+len] = s[i];	

	p1 = 0; p2 = 1;
	while(p1 < len && p2 < len)
	{
		for(k=0; k<len; k++)
			if(s[p1 + k] != s[p2 + k]) break;
		if(k == len) break;
		if(s[p1 + k] > s[p2 + k]) p1 += k + 1;
		else p2 += k + 1;
		if(p1 == p2) p2++;
	}
	p1++; p2++;
	printf("%d\n" , p1 < p2 ? p1 : p2);
}

int main()
{
	int T;
	scanf("%d" , &T);

	while(T--)
	{
		scanf("%s" , s);
		solve();
	}	
	
	return 0;
}
