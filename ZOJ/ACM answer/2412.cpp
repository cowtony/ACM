#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

struct  node
{
	deque <int> direc;
}a[11];

struct pipe
{
	int row;
	int col;
	int dir;
}p, q;

int map[50][50];
void init()
{
	a[0].direc.push_back(3);
	a[0].direc.push_back(4);
	a[1].direc.push_back(2);
	a[1].direc.push_back(3);
	a[2].direc.push_back(1);
	a[2].direc.push_back(4);
	a[3].direc.push_back(1);
	a[3].direc.push_back(2);
	a[4].direc.push_back(1);
	a[4].direc.push_back(3);
	a[5].direc.push_back(2);
	a[5].direc.push_back(4);
	a[6].direc.push_back(2);
	a[6].direc.push_back(3);
	a[6].direc.push_back(4);
	a[7].direc.push_back(1);
	a[7].direc.push_back(3);
	a[7].direc.push_back(4);
	a[8].direc.push_back(1);
	a[8].direc.push_back(2);
	a[8].direc.push_back(4);
	a[9].direc.push_back(1);
	a[9].direc.push_back(2);
	a[9].direc.push_back(3);
	a[10].direc.push_back(1);
	a[10].direc.push_back(2);
	a[10].direc.push_back(3);
	a[10].direc.push_back(4);
}

void input(int m, int n)
{
	int i, j;
	char ch;
	for(i=0; i<m; i++)
	{
		j = 0;
		while(j != n)
		{
			cin >> ch;
			if(ch >= 'A' && ch <= 'K')
			{
				map[i][j] = ch - 'A';
				j++;
			}
		}
	}
}

int search(int m, int n)
{
	int i, j, k;
	int spring = 0;
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			if(map[i][j] == -1) continue;
			deque <struct pipe> deq;
			for(k=0; k<a[map[i][j]].direc.size(); k++)
			{
				p.row = i;
				p.col = j;
				p.dir = a[map[i][j]].direc[k];
				deq.push_back(p);
			}
			map[i][j] = -1;
			while(!deq.empty())
			{
				int row = -1, col = -1;
				p = deq.front();
				deq.pop_front();
				deque <int>::iterator iter;
				if(p.dir == 1 && p.row + 1 < m && map[p.row+1][p.col] != -1)
				{
					
					iter = find(a[map[p.row+1][p.col]].direc.begin(), a[map[p.row+1][p.col]].direc.end(), 3);
					if(iter !=  a[map[p.row+1][p.col]].direc.end())
					{
						row = p.row + 1;
						col = p.col;
					}
				}
				else if(p.dir == 2 && p.col + 1 < n && map[p.row][p.col+1] != -1)
				{
					iter = find(a[map[p.row][p.col+1]].direc.begin(), a[map[p.row][p.col+1]].direc.end(), 4);
					if(iter != a[map[p.row][p.col+1]].direc.end())
					{
						row = p.row;
						col = p.col + 1;
					}
				}
				else if(p.dir == 3 && p.row > 0 && map[p.row-1][p.col] != -1)
				{
					iter = find(a[map[p.row-1][p.col]].direc.begin(), a[map[p.row-1][p.col]].direc.end(), 1);
					if(iter != a[map[p.row-1][p.col]].direc.end())
					row = p.row - 1;
					col = p.col;
				}
				else if(p.dir == 4 && p.col > 0 && map[p.row][p.col-1] != -1)
				{
					iter = find(a[map[p.row][p.col-1]].direc.begin(), a[map[p.row][p.col-1]].direc.end(), 2);
					if(iter != a[map[p.row][p.col-1]].direc.end())
					{
						row = p.row;
						col = p.col-1;
					}
				}
				if(row != -1 && col != -1)
				{
					for(k=0; k<a[map[row][col]].direc.size(); k++)
					{
						p.row = row;
						p.col = col;
						p.dir = a[map[row][col]].direc[k];
						deq.push_back(p);	
					}
					map[row][col] = -1;
				}
			}
			spring++;
		}
	}
	return spring;
}


int main()
{
	int m, n;
	init();
	while(cin >> m >> n && m != -1 && n != -1)
	{
		input(m, n);
		int ans = search(m, n);
		cout << ans << endl;
	}
	return 0;
}