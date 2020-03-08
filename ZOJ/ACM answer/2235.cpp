#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>
using namespace std;

struct node
{
	int row;
	int col;
	int val;
}p;

int main()
{
	int i,j;
	int a[52][52];
	int cas;
	cin >> cas;
	while(cas--)
	{
		int m, n, k;
		vector <struct node> vec; 
		cin >> m >> n >> k;
		for(i=0; i<m; i++)
		{
			for(j=0; j<n; j++)
			{
				cin >> a[i][j];
				if(a[i][j])
				{
					p.row = i;
					p.col = j;
					p.val = a[i][j];
					vec.push_back(p);
				}
			}
		}
		for(i=0; i<vec.size(); i++)
		{
			for(j=i+1; j<vec.size(); j++)
			{
				if(vec[i].val < vec[j].val)
				{
					p= vec[i];
					vec[i] =vec[j];
					vec[j] = p;
				}
			}
		}
		k -= 2;
		int nr = 0;
		int nc = vec[0].col;
		int index = 0;
		int peanut = 0;
		while(index <vec.size())
		{
			if(k >= (abs(nr-vec[index].row)+abs(nc-vec[index].col) +1 + vec[index].row))
			{
				k = k-abs(nr-vec[index].row) -abs(nc-vec[index].col) - 1;
				nr = vec[index].row;
				nc = vec[index].col;
				peanut += vec[index].val;
				index++;
			}
			else break;
		}
		cout << peanut << endl;

	}
	return 0;
}
