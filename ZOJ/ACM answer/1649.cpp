#include <iostream>
#include <string>
#include <deque>
using namespace std;


struct rescue
{
	int x;
	int y;
};
string str[200];
int dir[2][4] = {-1, 0, 1,0, 0, 1, 0, -1};

int go(rescue angel, rescue angelfren, int row, int col)
{
	int a[200][200];
	memset(a, 1, sizeof(a));
	deque <rescue> gotoangel;
	gotoangel.push_back(angelfren);
	a[angelfren.x][angelfren.y] = 0;
	while(!gotoangel.empty())
	{
		rescue t = gotoangel.front();
		gotoangel.pop_front();
		if(t.x == angel.x && t.y == angel.y)
			continue;
		for(int i=0; i<4; i++)
		{
			if(t.x+dir[0][i] >= 0 && t.x + dir[0][i] < row && t.y + dir[1][i] >=0 && t.y + dir[1][i] <col)
			{
				if(str[t.x+dir[0][i]][t.y + dir[1][i]] != '#')
				{
					int num = a[t.x][t.y];
					if(str[t.x+dir[0][i]][t.y + dir[1][i]] == 'x')
					{
						num += 2;
					}
					else num += 1;
					if(num < a[t.x + dir[0][i]][t.y + dir[1][i]])
					{
						a[t.x + dir[0][i]][t.y + dir[1][i]] = num;
						rescue temp;
						temp.x = t.x + dir[0][i];
						temp.y = t.y + dir[1][i];
						gotoangel.push_back(temp);
					}
				}
			}
		}
	}
	if(a[angel.x][angel.y]==16843009)
	{
		cout << "Poor ANGEL has to stay in the prison all his life." << endl;
		return -1;
	}
	else return a[angel.x][angel.y];
}



int main()
{
	int row, col;
	while(cin >> row >> col)
	{
		rescue angel, angelfren;
		for(int i=0; i<row; i++)
		{
			cin >> str[i];
			for(int j=0; j<col; j++)
			{
				if(str[i][j] == 'a')
				{
					angel.x = i;
					angel.y = j;
				}
				if(str[i][j] == 'r')
				{
					angelfren.x = i;
					angelfren.y = j;
				}
			}
		}
		int ans = go(angel, angelfren, row, col);
		if(ans!=-1)
			cout << ans << endl;
	}
	return 0;
}

		
