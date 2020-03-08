#include <iostream>
using namespace std;

int a[103][103];
int n, m;

void init(int n, int m)
{
	int i, j;
	memset(a,0,sizeof(a));
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=m; j++)
		{
			cin >> a[i][j];
		}
	}
}

void change1(int &x1, int &x2, int &y1, int &y2)
{
	int temp;
	if(y1 > y2)
	{
		temp = x1;
		x1 = x2;
		x2 = temp;
		temp = y1;
		y1 = y2;
		y2 = temp;
	}
}

void change2(int &x1, int &x2, int &y1, int &y2)
{
	int temp;
	if(x1 > x2)
	{
		temp = x1;
		x1 = x2;
		x2 = temp;
		temp = y1;
		y1 = y2;
		y2 = temp;
	}
}

bool find(int x1, int y1, int x2, int y2)
{
	int i, j, k;
	if(x1 == x2 && y1 == y2) return false;
	if(a[x1][y1] != a[x2][y2] || !a[x1][y1]) return false;
	if(y1 != y2)
	{
		change1(x1, x2, y1, y2);
		for(i=0; i<=n+1; i++)
		{
			int flag = 0;
			for(j=y1+1; j<y2; j++)
			{
				if(a[i][j]) {flag = 1; break;}
			}
			if(flag) continue;
			if(i<x1)
			{
				for(k=i; k<x1; k++)
				{
					if(a[k][y1]) {flag = 1; break;}
				}
				if(flag) continue;
			}
			else
			{
				for(k=i; k>x1; k--)
				{
					if(a[k][y1]) {flag = 1; break;}
				}
				if(flag) continue;
			}
			if(i<x2)
			{
				for(k=i; k<x2; k++)
				{
					if(a[k][y2]) {flag = 1; break;}
				}
				if(flag) continue;
			}
			else
			{
				for(k=i; k>x2; k--)
				{
					if(a[k][y2]) {flag = 1; break;}
				}
				if(flag) continue;
			}
			return true;
		}
	}//
	if(x1 != x2)
	{
		change2(x1, x2, y1, y2);
		for(i=0; i<=m+1; i++)
		{
			int flag = 0;
			for(j=x1+1; j<x2; j++)
			{
				if(a[j][i]) {flag = 1; break;}
			}
			if(flag) continue;
			if(i<y1)
			{
				for(k=i; k<y1; k++)
				{
					if(a[x1][k]) {flag = 1; break;}
				}
				if(flag) continue;
			}
			else
			{
				for(k=i; k>y1; k--)
				{
					if(a[x1][k]) {flag = 1; break;}
				}
				if(flag) continue;
			}
			if(i<y2)
			{
				for(k=i; k<y2; k++)
				{
					if(a[x2][k]) {flag = 1; break;}
				}
				if(flag) continue;
			}
			else
			{
				for(k=i; k>y2; k--)
				{
					if(a[x2][k]) {flag = 1; break;}
				}
				if(flag) continue;
			}
			return true;
		}
	}
	return false;
}


int main()
{
	int opera;
	int x1, y1, x2, y2;
	while(cin >> n >> m && n && m)
	{
		init(n, m);
		cin >> opera;
		int ans = 0;
		for(int i=0; i<opera; i++)
		{
			cin >> x1 >> y1 >> x2 >> y2;
			bool yes = find(x1, y1, x2, y2);
			if(yes)
			{
				ans += 2;
				a[x1][y1] = a[x2][y2] = 0;
			}
		}
		cout << ans << endl;
	}
	return 0;
}