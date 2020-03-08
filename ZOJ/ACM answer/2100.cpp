#include <iostream>
#include <string>
using namespace std;

int b[5][2] = {0, 0, 0, 1, 1, 0, 0, -1, -1, 0};
string str[7];
int a[7][7], feed;
int n, m, flag;

void dfs(int x, int y, int num)
{
	int i;
	if(num == feed)  {flag = 1; return ;}
	a[x][y] = 1;
	for(i=1; i<=4; i++)
	{
		if(x+b[i][0] >=0 && x+b[i][0] <n && y+b[i][1] >= 0 && y+b[i][1] < m && a[x+b[i][0]][y+b[i][1]] == 0)
		{
			dfs(x+b[i][0], y+b[i][1], num+1);
			a[x+b[i][0]][y+b[i][1]] = 0;
		}
	}
	return ;
}

int main()
{
	int i, j;
	while(cin >> n >> m && n && m)
	{
		feed = 0;
		flag = 0;
		for(i=0; i<n; i++)
		{
			cin >> str[i];
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				if(str[i][j] == '.') {a[i][j] = 0;feed++;}
				else a[i][j] = 1;
			}
		}
		dfs(0, 0, 1);
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}